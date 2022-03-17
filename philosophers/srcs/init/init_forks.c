/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:29:03 by plam              #+#    #+#             */
/*   Updated: 2022/03/17 10:40:58 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*malloc_forks(int nb_philo)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * nb_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&forks[i].m_fork, NULL) != 0)
		{
			free_forks(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	free_forks(t_fork *forks, int nb_philo)
{
	if (forks)
	{
		while (nb_philo--)
			pthread_mutex_destroy(&forks[nb_philo].m_fork);
		free (forks);
	}
}
