/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:44:28 by plam              #+#    #+#             */
/*   Updated: 2022/03/29 14:18:10 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_rules(t_rules *rules)
{
	if (rules->eat_time < 0 || rules->sleep_time < 0
		|| rules->alive_time < 0)
	{
		pthread_mutex_destroy(&rules->m_print);
		return (ERR);
	}
	return (OK);
}

int	set_rules(int ac, char **av, t_rules *rules)
{
	int	nb_meal;

	nb_meal = -1;
	if (ac == 6)
	{
		nb_meal = ft_atol(av[5]);
		if (nb_meal < 1)
			return (ERR);
	}
	rules->alive_time = (t_ms)ft_atol(av[2]);
	rules->eat_time = (t_ms)ft_atol(av[3]);
	rules->sleep_time = (t_ms)ft_atol(av[4]);
	rules->nb_meal = (t_ms)nb_meal;
	rules->can_write = OK;
	if (pthread_mutex_init(&rules->m_print, NULL) != 0)
		return (ERR);
	return (check_rules(rules));
}

void	free_rules(t_rules *rules)
{
	if (rules)
		pthread_mutex_destroy(&rules->m_print);
}
