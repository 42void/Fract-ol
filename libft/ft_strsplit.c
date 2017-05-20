/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhoeg <avanhoeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:16:38 by avanhoeg          #+#    #+#             */
/*   Updated: 2014/12/29 23:57:11 by avanhoeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_count_words(const char *s, char c)
{
	int		cnt;
	int		in;

	in = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in == 1 && *s == c)
			in = 0;
		if (in == 0 && *s != c)
		{
			in = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

int		ft_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		index;

	if (!s || !c)
		return (NULL);
	index = 0;
	nb_word = ft_count_words((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_count_words((const char *)s, c) + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[index] = ft_strsub((const char *)s, 0, ft_len((const char *)s, c));
		if (t[index] == NULL)
			return (NULL);
		s = s + ft_len(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
