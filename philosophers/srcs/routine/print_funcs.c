/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:47:54 by plam              #+#    #+#             */
/*   Updated: 2022/03/23 14:10:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Here we will deal with printing and changing status of threads during the
** execution of them
** Need to add a e_num or define status on the header
*/

void	change_status(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->m_status);
	if (philo->status != IS_DEAD && philo->status != FINISHED_EATING)
		philo->status = status;
	if (status == IS_EATING)
	{
		philo->nb_meal++;
		if (philo->nb_meal == philo->rules->nb_meal)
			philo->status = FINISHED_EATING;
		gettimeofday(&philo->last_meal, NULL);
	}
	pthread_mutex_unlock(&philo->m_status);
}

int	can_write(t_rules *rules)
{
	if (&rules)
		return (OK);
	pthread_mutex_lock(&rules->m_print);
	if (rules->can_write == KO)
	{
		pthread_mutex_unlock(&rules->m_print);
		return (KO);
	}
	pthread_mutex_unlock(&rules->m_print);
	return (OK);
}

static void	write_status(t_ms time, int id, int status)
{
	static char	*str_status[5] = {
		" has taken a fork\n", " is eating\n", " is sleeping\n",
		" is thinking\n", " died\n",
	};
	
	printf("%lld %d %s\n", time, id, str_status[status]);
}

/*
** status display : if a philosopher has a "IS_DEAD" status
** -> the permission is blocked for all other philosophers to write
*/
void	print_status(t_philo *philo, int status, t_rules *rules)
{
	struct timeval	now;

	pthread_mutex_lock(&rules->m_print);
	gettimeofday(&now, NULL);
	if (philo != NULL && rules->can_write == OK)
		write_status(get_diff_time(rules->start, now), philo->id, status);
	if (status == IS_DEAD)
		rules->can_write = KO;
	pthread_mutex_unlock(&rules->m_print);
}
