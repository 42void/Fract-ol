/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:10:00 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/11/12 16:39:10 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lend;
	int				lens;
	int				i;
	int				most;

	i = 0;
	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	most = size - lend - 1;
	while (i < most)
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	if (size < lend)
		return (lens + size);
	return (lend + lens);
}
