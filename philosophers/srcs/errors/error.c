/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:39:37 by plam              #+#    #+#             */
/*   Updated: 2022/03/15 22:11:40 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_err(int err, t_table *table)
{
	if (err == MALLOC_ERR)
		printf("Error : Malloc problem returned NULL\n");
	if (err == ARG_ERR)
		printf("Error : Arguments not well formated\n");
	if (table)
		free_table(table);
	return (ERR);
}
