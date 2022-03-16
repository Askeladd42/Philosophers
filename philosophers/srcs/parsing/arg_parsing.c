/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 23:59:48 by plam              #+#    #+#             */
/*   Updated: 2022/03/17 00:08:18 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_parsing(int ac, char **av, t_table *table, t_rules *rules)
{
	if (set_rules(ac, av, rules) == ERR 
		|| set_table(av, table, rules == ERR))
		return (philo_err(ARG_ERR, NULL));
	table->forks = malloc_forks(table->nb_philo);
	if (!table->forks)
		return (philo_err(ARG_ERR, table));
	table->philos = malloc_philos(table->nb_philo, rules, table->forks);
	if (!table->philos)
		return (philo_err(ARG_ERR, table));
	return (OK);
}
