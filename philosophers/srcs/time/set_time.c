/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:57:03 by plam              #+#    #+#             */
/*   Updated: 2022/03/29 16:15:29 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** Conversion time : first one is given in microseconds, so we have to * 1000 to
** have it in ms (milliseconds), when the second one is in seconds, we have to
** "dividing" it by 1000 to have it in ms.
*/

t_ms	set_time(struct timeval time)
{
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000.0);
}

t_ms	get_diff_time(struct timeval begin, struct timeval end)
{
	return (set_time(end) - set_time(begin));
}
