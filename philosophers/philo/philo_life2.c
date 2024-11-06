/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:17:06 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/01 19:08:12 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->simulation)
	{
		if (philo->meals_eaten == philo->table->num_meals)
		{
			philo->table->philo_meals++;
			if (philo->table->philo_meals
				== philo->table->number_of_philosophers)
			{
				philo->table->simulation = 0;
				pthread_mutex_unlock(&philo->table->print_mutex);
				return (1);
			}
			pthread_mutex_unlock(&philo->table->print_mutex);
			return (0);
		}
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	if (print_status(philo, "is sleeping"))
		return (1);
	if (uwait(philo->table->time_to_sleep, philo))
		return (1);
	return (0);
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->simulation)
	{
		if (get_time() - philo->last_meal > philo->table->time_to_die)
		{
			printf("%ld %d died\n", get_time()
				- philo->table->start_time, philo->id);
			philo->table->simulation = 0;
			pthread_mutex_unlock(&philo->table->print_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	return (0);
}

int	uwait(int time, t_philo *philo)
{
	int	start;
	int	current_time;

	start = get_time();
	current_time = get_time();
	while (current_time - start < time)
	{
		if (check_death(philo))
			return (1);
		usleep(100);
		current_time = get_time();
	}
	return (0);
}
