/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:23:15 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/01 18:48:12 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i] - 48);
		i++;
	}
	return (num * sign);
}

void	cleanup(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	free(table->forks);
	free(table->forks_mutex);
	free(table);
	free(philo);
}

int	print_status(t_philo *philo, char *status)
{
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->simulation == 0)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return (1);
	}
	printf("%ld %d %s\n",
		get_time() - philo->table->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (0);
}

int	check_arguments(t_table **table)
{
	if ((*table)->number_of_philosophers < 1)
	{
		printf("Error: Number of philosophers must be at least 1.\n");
		free(table);
		return (1);
	}
	if ((*table)->time_to_die < 1 || (*table)->time_to_eat < 1
		|| (*table)->time_to_sleep < 1)
	{
		printf("Error: Time to die, eat, and sleep must be at least 1.\n");
		free(*table);
		return (1);
	}
	if ((*table)->num_meals == 0)
	{
		free(*table);
		printf("Error: Number of meals must be at least 1.\n");
		return (1);
	}
	return (0);
}
