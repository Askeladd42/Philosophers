/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:58:48 by plam              #+#    #+#             */
/*   Updated: 2022/03/15 22:22:06 by plam             ###   ########.fr       */
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

	if (ac < 5 || ac > 6 || parse_av(ac, av) == 0)
		return (philo_err(ARG_ERR, &table));
	init_philo(&table, &rules);
	{
		while (philo_nb() == ft_atol(av[2]))
		{
			
		}
	}
	return (EXIT_SUCCESS);
}
