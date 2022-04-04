/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:39:37 by plam              #+#    #+#             */
/*   Updated: 2022/04/04 13:24:56 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_err(int err, t_table *table)
{
	if (err == MALLOC_ERR)
		printf("Error : Malloc problem returned NULL\n");
	if (err == ARG_ERR)
		printf("Error : Arguments not well formated\n");
	if (err == INIT_THRD_ERR)
		printf("Error : Fail to create a pthread\n");
	if (table)
		free_table(table);
	return (ERR);
}
