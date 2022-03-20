/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:13:58 by plam              #+#    #+#             */
/*   Updated: 2022/03/20 22:40:24 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Will define the project issues : will execute it when there is an even or odd
** number of philosophers and will treat each of them differently.
**
** We will also define the different routine of each thread, 
** i.e eating (in the eat_routine.c), sleeping, thinking.
**
** CAUTION : while a philosopher is alive or finished eating,
** they must follow this order : EAT -> SLEEP -> THINK etc.
*/

static int	get_status(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->m_status);
	status = philo->status;
	pthread_mutex_unlock(&philo->m_status);
	return (status);
}

static void sleeping_routine(t_philo *philo)
{
	change_status(philo, IS_SLEEPING);
	print_status(philo, IS_SLEEPING, philo->rules);
	ms_sleep(philo->rules->sleep_time, philo->rules);
}

static void thinking_routine(t_philo *philo)
{
	change_status(philo, IS_THINKING);
	print_status(philo, IS_THINKING, philo->rules);
}

void	*routine(void *philos)
{
	t_philo	*philo;
	int		even_odd;
	int		status;

	philo = (t_philo *)philos;
	even_odd = philo->id % 2;
	while (can_write(philo->rules))
	{
		status = get_status(philo);
		if (status == IS_THINKING)
		{
			if (even_odd == 0)
				eating_routine(philo);
			else
				eating_routine(philo);
		}
		else if (status == IS_EATING)
			sleeping_routine(philo);
		else if (status == IS_SLEEPING)
			thinking_routine(philo);
		else
			return (NULL);
	}
	return (NULL);
}
