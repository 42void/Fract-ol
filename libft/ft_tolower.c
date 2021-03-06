/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:54:49 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/11/12 16:45:04 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c)
	{
		if (c >= 'A' && c <= 'Z')
			c = c + 32;
		return (c);
	}
	return (0);
}
