/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 17:34:54 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/11/12 16:45:48 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	u;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < n && s1[i])
	{
		y = 0;
		if (s1[i] == s2[0])
		{
			u = i;
			y = 0;
			while (y < (n - i) && s2[y] && s1[u] == s2[y])
			{
				u++;
				y++;
			}
			if (s1[u - 1] == s2[y - 1] && s2[y] == '\0')
				return (&((char *)s1)[i]);
		}
		i++;
	}
	return (NULL);
}
