/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 22:40:40 by plam              #+#    #+#             */
/*   Updated: 2022/03/31 00:08:51 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->m_fork);
}

static void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->m_fork);
	print_status(philo, TAKE_FORK, philo->rules);
}

static void	meal_ready(t_philo *philo)
{
	change_status(philo, IS_EATING);
	print_status(philo, IS_EATING, philo->rules);
	timestamp(philo->rules->eat_time, philo->rules);
}

/*
** Here we will distinguish the routine for a odd & even number of philosophers:
** - If there is an odd number : one of them will not have a fork on his left
**		-> Only one of them will not being able to eat at one point
** - If there is an even number : the usual procedure
*/

void	eat_routine_odd(t_philo *philo)
{
	take_fork(philo, philo->r_fork);
	if (philo->l_fork == NULL)
	{
		drop_fork(philo->r_fork);
		change_status(philo, IS_DEAD);
		return ;
	}
	take_fork(philo, philo->l_fork);
	meal_ready(philo);
	drop_fork(philo->l_fork);
	drop_fork(philo->r_fork);
}

void	eat_routine_even(t_philo *philo)
{
	take_fork(philo, philo->l_fork);
	take_fork(philo, philo->r_fork);
	meal_ready(philo);
	drop_fork(philo->r_fork);
	drop_fork(philo->l_fork);
}
