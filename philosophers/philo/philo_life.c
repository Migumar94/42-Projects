/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:47:47 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/01 21:53:29 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*philo_life(void *philo)
{
	t_philo	*philo_ptr;

	philo_ptr = (t_philo *)philo;
	if (philo_ptr->id % 2)
	{
		uwait(philo_ptr->table->time_to_eat, philo_ptr);
	}
	while (1)
	{
		if (philo_take_forks(philo_ptr))
			break ;
		if (philo_eat(philo_ptr))
		{
			philo_drop_forks(philo_ptr);
			break ;
		}
		if (philo_sleep(philo_ptr))
			break ;
		if (print_status(philo, "is thinking"))
			break ;
		if (philo_ptr->numbers_of_philo % 2)
			if (uwait(philo_ptr->table->time_to_eat, philo_ptr))
				break ;
	}
	return (NULL);
}

int	philo_take_a_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->table->forks_mutex[fork]);
	if (print_status(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->table->forks_mutex[fork]);
		return (1);
	}
	return (0);
}

int	philo_take_forks(t_philo *philo)
{
	int	first_fork;
	int	second_fork;

	first_fork = philo->left_fork;
	second_fork = philo->right_fork;
	if (philo->id % philo->table->number_of_philosophers == 0)
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	if (philo_take_a_fork(philo, first_fork))
		return (1);
	if (philo->table->number_of_philosophers == 1)
		if (uwait(philo->table->time_to_die, philo))
			return (1);
	if (philo_take_a_fork(philo, second_fork))
	{
		pthread_mutex_unlock(&philo->table->forks_mutex[first_fork]);
		return (1);
	}
	return (0);
}

void	philo_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->forks_mutex[philo->right_fork]);
}

int	philo_eat(t_philo *philo)
{
	if (print_status(philo, "is eating"))
	{
		return (1);
	}
	philo->meals_eaten++;
	if (check_meals(philo))
		return (1);
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->simulation == 0)
	{
		pthread_mutex_unlock(&philo->table->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
	if (uwait(philo->table->time_to_eat, philo))
	{
		return (1);
	}
	philo->last_meal = get_time();
	philo_drop_forks(philo);
	return (0);
}
