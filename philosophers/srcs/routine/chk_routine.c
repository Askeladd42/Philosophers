/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:44:16 by plam              #+#    #+#             */
/*   Updated: 2022/03/21 00:22:03 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** The project starts in even or odd case so the philosophers can't be blocked
** with a fork at the same time 
*/

static void	begin_time_init(t_rules *rules, t_philo *philo, int nb_philo)
{
	pthread_mutex_lock(&rules->m_print);
	gettimeofday(&rules->start, NULL);
	while (nb_philo--)
	{
		philo[nb_philo].last_meal.tv_sec = rules->start.tv_sec;
		philo[nb_philo].last_meal.tv_usec = rules->start.tv_usec;
	}
	pthread_mutex_unlock(&rules->m_print);
}

int	start_it(int nb_philo, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (!(i % 2))
		{
			if (create_ph_thrd(philo + i) == ERR)
				return (ERR);
		}
		i++;
	}
	return (OK);
}

void	stop_it(t_philo *philo, int nb_philo)
{
	while (nb_philo--)
	{
		pthread_mutex_lock(&philo[nb_philo].m_status);
		philo[nb_philo].status = FINISHED_EATING;
		pthread_mutex_unlock(&philo[nb_philo].m_status);
	}
}

/*
** In the case of a defined number of meals, it will checks if all of the
** philosophers have eaten the necessary number of meals, but also checks if
** a philosopher is dead, i.e if last_meal > alive_time : he is dead.
*/

static int	last_meal_or_dead(t_philo *philo, int nb_philo, int max_eat,
		t_ms alive_time)
{
	int				nb_finished;
	int				i;
	struct timeval	now;
	t_ms			last_meal;

	i = -1;
	nb_finished = 0;
	while (++i < nb_philo)
	{
		pthread_mutex_lock(&philo[i].m_status);
		if (max_eat != -1 && philo[i].status == FINISHED_EATING)
			nb_finished++;
		gettimeofday(&now, NULL);
		last_meal = get_diff_time(philo[i].last_meal, now);
		if (last_meal > 0 && last_meal > alive_time)
		{
			print_status(&philo[i], IS_DEAD, philo->rules);
			pthread_mutex_unlock(&philo[i].m_status);
			return (OK);
		}
		pthread_mutex_unlock(&philo[i].m_status);
	}
	if (nb_finished == nb_philo)
		return (OK);
	return (KO);
}

int	start_project(t_table *table, t_rules *rules, t_philo *philo, int nb_philo)
{
	begin_time_init(rules, philo, nb_philo);
	if (start_it(nb_philo, philo) == ERR)
		return (philo_err(INIT_THRD_ERR, table));
	while (last_meal_or_dead(philo, nb_philo, rules->nb_meal,
			rules->alive_time) == KO)
		ms_sleep(1, NULL);
	stop_it(philo, nb_philo);
	return (OK);
}
