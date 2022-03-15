/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:25:02 by plam              #+#    #+#             */
/*   Updated: 2022/03/15 22:48:17 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_table(char **av, t_table *table, t_rules *rules)
{
	int	nb_philo;

	nb_philo = ft_atol(av[1]);
	if (nb_philo < 1)
		return (KO);
	table->forks = NULL;
	table->rules = rules;
	table->nb_philo = nb_philo;
	table->philos = NULL;
	return (OK);
}

void	free_table(t_table *table)
{
	sleep(1);		//to replace with another function correctly later
	if (table)
	{
		if (table->rules)
			free_rules(table->rules);
		if (table->philos)
			free_philos(table->philos);
		if (table->forks)
			free_forks(table->forks);
		table->nb_philo = 0;
	}
}
