/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:59:38 by plam              #+#    #+#             */
/*   Updated: 2022/04/04 14:48:58 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define OK 1
# define KO 0
# define ERR -1

# define MALLOC_ERR -2
# define ARG_ERR -3
# define INIT_THRD_ERR -4

# include <stdio.h>
# include <memory.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/errno.h>

# include "philo_utils.h"

enum	e_status
{
	TAKE_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DEAD,
	FINISHED_EATING,
};

typedef long long	t_ms;

typedef struct s_fork
{
	pthread_mutex_t	m_fork;
}				t_fork;

typedef struct s_rules
{
	t_ms			eat_time;
	t_ms			sleep_time;
	t_ms			alive_time;
	long			nb_meal;
	int				can_write;
	struct timeval	start;
	pthread_mutex_t	m_print;
}				t_rules;

typedef struct s_philo
{
	int				id;
	int				alive;
	int				status;
	long			nb_meal;
	struct timeval	last_meal;
	t_rules			*rules;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		thrd_id;
	pthread_mutex_t	m_status;
}				t_philo;

typedef struct s_table
{
	int			nb_philo;
	t_philo		*philos;
	t_fork		*forks;
	t_rules		*rules;
}				t_table;

/*
** table functions
*/

int			set_table(int ac, char **av, t_table *table, t_rules *rules);
void		free_table(t_table *table);

/*
** rules functions
*/

int			set_rules(int ac, char **av, t_rules *rules);
void		free_rules(t_rules *rules);

/*
** error function
*/

int			philo_err(int err, t_table *table);

/*
** fork usage functions
*/

t_fork		*malloc_forks(int nb_philo);
void		free_forks(t_fork *forks, int nb_philo);

/*
** time functions
*/

t_ms		set_time(struct timeval time);
t_ms		get_diff_time(struct timeval begin, struct timeval end);
void		timestamp(t_ms waiting_time, t_rules *rules);

/*
**philo structure functions
*/

t_philo		*malloc_philos(int nb_philo, t_rules *rules, t_fork *forks);
t_philo		*init_philo_mutex(t_philo *philo, int nb_philo);
void		free_philos(t_philo *philo, int nb_philo);
int			create_ph_thrd(t_philo *philo);
void		join_thrd(t_philo *philo, int nb_philo);

/*
** routine functions
*/

void		eat_routine_odd(t_philo *philo);
void		eat_routine_even(t_philo *philo);
void		*routine(void *philos);

void		change_status(t_philo *philo, int status);
int			can_write(t_rules *rules);
void		print_status(t_philo *philo, int status, t_rules *rules);

int			start_project(t_table *table, t_rules *rules, t_philo *philo,
				int nb_philo);
int			arg_parsing(int ac, char **av, t_table *table, t_rules *rules);
int			only_digits(int ac, char **av);

#endif