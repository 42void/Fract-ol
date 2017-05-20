/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:36:20 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/11/09 14:52:17 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *tmp1;
	const char *tmp2;

	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		tmp1 = s1;
		tmp2 = s2;
		while (*tmp1 == *tmp2 && *tmp1 && *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (!*tmp2)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
