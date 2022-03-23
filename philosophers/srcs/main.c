/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:48 by plam              #+#    #+#             */
/*   Updated: 2022/03/23 14:21:16 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	t_rules	rules;

	if (ac < 5 || ac > 6 || arg_parsing(ac, av, &table, &rules) == 0)
		return (philo_err(ARG_ERR, &table));
	if (rules.nb_meal == 0)
	{
		free_table(&table);
		return (OK);
	}
	if (start_project(&table, &rules, table.philos, table.nb_philo) == ERR)
		return (ERR);
	free_table(&table);
	return (OK);
}
