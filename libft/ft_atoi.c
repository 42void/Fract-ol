/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:29:24 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/02/20 17:49:48 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		value;
	char	*cur;

	cur = (char *)str;
	value = 0;
	while (*cur == ' ' || *cur == '\n' || *cur == '\v' \
			|| *cur == '\t' || *cur == '\r' || *cur == '\f')
		cur++;
	sign = (*cur == '-') ? -1 : 1;
	cur = (*cur == '+' || *cur == '-') ? cur + 1 : cur;
	while (*cur >= '0' && *cur <= '9')
	{
		value = value * 10 + *cur - 48;
		cur++;
	}
	value *= sign;
	return (value);
}
