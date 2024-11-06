/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:10:35 by migumar2          #+#    #+#             */
/*   Updated: 2024/08/01 21:47:50 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long			last_meal;
	int				numbers_of_philo;
	pthread_t		thread;
	struct s_table	*table;
}				t_philo;

typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print_mutex;
	long			start_time;
	int				simulation;
	int				philo_meals;
}				t_table;

int			ft_atoi(const char *str);
long		get_time(void);
t_table		*init_table(char **argv);
t_philo		*init_philo(t_table *table);
void		free_table(t_table *table);
int			start_simulation(t_philo *philo);
void		*philo_life(void *philo);
int			print_status(t_philo *philo, char *status);
int			philo_sleep(t_philo *philo);
int			philo_eat(t_philo *philo);
int			philo_take_forks(t_philo *philo);
void		philo_drop_forks(t_philo *philo);
int			check_death(t_philo *philo);
int			check_meals(t_philo *philo);
void		cleanup(t_table *table, t_philo *philo);
int			uwait(int time, t_philo *philo);
int			check_arguments(t_table **table);

#endif
