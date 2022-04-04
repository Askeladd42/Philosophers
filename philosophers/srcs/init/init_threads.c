/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:46:39 by plam              #+#    #+#             */
/*   Updated: 2022/04/04 16:27:39 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	stop_thrd(t_rules *rules)
{
	pthread_mutex_lock(&rules->m_print);
	rules->can_write = KO;
	pthread_mutex_unlock(&rules->m_print);
	timestamp(20, NULL);
}

int	create_ph_thrd(t_philo *philo)
{
	if (pthread_create(&philo->thrd_id, NULL, &routine, philo) != 0)
	{
		stop_thrd(philo->rules);
		return (ERR);
	}
	return (OK);
}

void	join_thrd(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (philo->thrd_id != 0)
			pthread_join((philo + i)->thrd_id, NULL);
		i++;
	}
}
