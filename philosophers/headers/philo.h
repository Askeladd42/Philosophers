/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:59:38 by plam              #+#    #+#             */
/*   Updated: 2022/03/17 00:20:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define OK 1
# define KO 0
# define ERR -1

# define MALLOC_ERR -2
# define ARG_ERR -3

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <time.h>
# include <sys/wait.h>
# include <sys/errno.h>

# include "philo_utils.h"


typedef struct s_fork
{
	pthread_mutex_t	m_fork;
}				t_fork;

typedef struct s_common
{
	int				alive;
	t_ms			lifetime;
	t_ms			sleeptime;
	struct timeval	last_meal;
	long			nb_meal;
	t_fork			l_fork;
	t_fork			r_fork;

}				t_common;

typedef struct s_rules
{
	t_ms			eat_time;
	t_ms			sleep_time;
	t_ms			alive_time;
	long			nb_meal;
	int				think_time;
	pthread_mutex_t	m_print;
}				t_rules;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	struct s_philo	*next;
	struct s_philo	*first;
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

int			set_table(char **av, t_table *table, t_rules *rules);
void		free_table(t_table *table);

/*
** rules functions
*/

static int	check_rules(t_rules *rules);
int			set_rules(int ac, char **av, t_rules *rules);
void		free_rules(t_rules *rules);

/*
** error function
*/

int			philo_err(int err, t_table *table);

/*
** routine functions
*/

int			arg_parsing(int ac, char **av, t_table *table, t_rules *rules);
int			init_pthread(pthread_t *thread);
t_common	get_common_values(char	**av);
void		philo(int number_of_philosophers, int time_to_die,
				int time_to_sleep);

#endif