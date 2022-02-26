/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:59:38 by plam              #+#    #+#             */
/*   Updated: 2022/02/26 22:50:10 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <memory.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <time.h>
# include <sys/wait.h>
# include <sys/errno.h>

typedef	struct	s_philosopher
{
	int				alive;
	int				lifetime;
	int				hungry;
	int				sleeptime;
	int				meal_nb;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
}				t_philo;

void	philo(int number_of_philosophers, int time_to_die, int time_to_sleep);

#endif