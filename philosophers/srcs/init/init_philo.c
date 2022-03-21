/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:36:23 by plam              #+#    #+#             */
/*   Updated: 2022/03/21 23:43:34 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(int id, t_rules *rules, t_fork *left, t_fork *right)
{
	t_philo	philo;

	philo.id = id;
	philo.alive = OK;
	philo.l_fork = left;
	philo.r_fork = right;
	philo.status = IS_THINKING;
	philo.rules = rules;
	philo.last_meal.tv_sec = 0;
	philo.last_meal.tv_usec = 0;
	philo.nb_meal = 0;
	philo.thrd_id = 0;
	return (philo);
}

t_philo	*init_philo_mutex(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&philo[i].m_status, NULL) != 0)
		{
			free_philos(philo, i);
			return (NULL);
		}
		i++;
	}
	return (philo);
}

t_philo	*malloc_philos(int nb_philo, t_rules *rules, t_fork *forks)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * nb_philo + 1);
	if (!philos)
		return (NULL);
	if (nb_philo == 1)
		philos[0] = init_philo(1, rules, NULL, forks);
	else
		philos[0] = init_philo(1, rules, forks + nb_philo - 1, forks);
	i = 1;
	while (i < nb_philo)
	{
		philos[i] = init_philo((i + 1), rules, (forks + i - 1), (forks + i));
	}
	return (init_philo_mutex(philos, nb_philo));
}

void	free_philos(t_philo *philos, int nb_philo)
{
	if (philos)
	{
		join_ph_thrd(philo, nb_philo);
		while (nb_philo--)
			pthread_mutex_destroy(&(philo + nb_philo)->m_status);
		free(philo);
	}
}
