/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:34:13 by plam              #+#    #+#             */
/*   Updated: 2022/03/23 14:45:56 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# define LONG_MAX 2147483647

# include <stddef.h>

int		ft_isdigit(int c);
void	*ft_memset(void *s, int c, size_t n);
long	ft_atol(const char *str);

#endif