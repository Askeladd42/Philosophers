/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:48 by plam              #+#    #+#             */
/*   Updated: 2022/04/04 13:44:39 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	t_rules	rules;

	if (arg_parsing(ac, av, &table, &rules) == ERR)
		return (ERR);
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
