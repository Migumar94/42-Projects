/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:36:23 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/01 21:49:50 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_table	*init_mutex(t_table *table)
{
	int	i;

	i = 0;
	table->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_of_philosophers);
	if (!table->forks_mutex)
	{
		free(table->forks);
		free(table);
		return (NULL);
	}
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_init(&table->forks_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print_mutex, NULL);
	return (table);
}

t_table	*init_table(char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->number_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->num_meals = -1;
	if (argv[5])
		table->num_meals = ft_atoi(argv[5]);
	if (check_arguments(&table))
		return (NULL);
	table->forks = (int *)malloc(sizeof(int) * table->number_of_philosophers);
	if (!table->forks)
	{
		free(table);
		return (NULL);
	}
	init_mutex(table);
	table->start_time = get_time();
	table->simulation = 1;
	return (table);
}

t_philo	*init_philos(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)malloc(sizeof(t_philo) * table->number_of_philosophers);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1);
		if (i == table->number_of_philosophers - 1)
			philo[i].right_fork = 0;
		philo[i].meals_eaten = 0;
		philo[i].last_meal = table->start_time;
		philo[i].table = table;
		philo[i].numbers_of_philo = table->number_of_philosophers;
		i++;
	}
	return (philo);
}

int	start_simulation(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].table->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_life, &philo[i]))
		{
			philo[0].table->simulation = 0;
			while (i-- > 0)
				pthread_join(philo[i].thread, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (1);
	}
	table = init_table(argv);
	if (!table)
		return (1);
	philo = init_philos(table);
	if (!philo)
	{
		free(table);
		return (1);
	}
	if (start_simulation(philo))
	{
		cleanup(table, philo);
		return (1);
	}
	cleanup(table, philo);
	return (0);
}
