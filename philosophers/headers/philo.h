/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:59:38 by plam              #+#    #+#             */
/*   Updated: 2022/03/14 20:38:40 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define TRUE 1
# define FALSE 0
# define ERR -1

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <time.h>
# include <sys/wait.h>
# include <sys/errno.h>

typedef struct s_common
{
	int				alive;
	long			lifetime;
	long			hungry;
	long			sleeptime;
	long			meal_nb;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;

}				t_common;


typedef struct	s_philo
{
	int				id;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	struct s_philo	*next;
	struct s_philo	*first
}				t_philo;


int			init_philo(t_philo *philo);
int			init_pthread(pthread_t *thread);
t_common	get_common_values(char	**av);
void		philo(int number_of_philosophers, int time_to_die, int time_to_sleep);

#endif