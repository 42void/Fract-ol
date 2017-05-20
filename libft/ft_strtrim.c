/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:41:23 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/11/10 20:16:23 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = ft_strlen(s);
	while (i-- > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		(void)s;
	if (!(str = ft_strsub(s, 0, i + 1)))
		return (NULL);
	return (str);
}
