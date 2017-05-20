/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:20:10 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/12/29 20:38:54 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;

	if (src == NULL)
		return (NULL);
	i = 0;
	while (((char *)src)[i] != c && i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	if (i == n)
		return (NULL);
	((char *)dest)[i] = ((char *)src)[i];
	return (&((char *)dest)[i + 1]);
}
