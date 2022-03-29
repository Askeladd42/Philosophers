/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:38:01 by plam              #+#    #+#             */
/*   Updated: 2022/03/29 16:17:50 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_sleep(t_ms waiting_time, t_rules *rules)
{
	struct timeval	time_now;
	t_ms			stop_time;
	int				cnt;

	cnt = 0;
	gettimeofday(&time_now, NULL);
	stop_time = set_time(time_now) + waiting_time;
	while (set_time(time_now) - stop_time < 0)
	{
		cnt++;
		if (cnt == 5000)
		{
			if (can_write(rules) == KO)
				return ;
			cnt = 0;
		}
		usleep(100);
		gettimeofday(&time_now, NULL);
	}
}
