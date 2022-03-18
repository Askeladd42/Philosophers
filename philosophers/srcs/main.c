/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:48 by plam              #+#    #+#             */
/*   Updated: 2022/03/18 17:09:12 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(int number_of_philosophers, int time_to_die, int time_to_sleep)
{
	
}

int	main(int ac, char **av)
{
	t_table	table;
	t_rules	rules;

	if (ac < 5 || ac > 6 || arg_parsing(ac, av, &table, &rules) == 0)
		return (philo_err(ARG_ERR, &table));
	init_philo(&table, &rules);
	if (rules.nb_meal == 0)
	{
		free_table(&table);
		return (OK);
	}
	// condition : start the procedure but if failure
	{
		return (KO);
	}
	free_table(&table);
	return (OK);
}
