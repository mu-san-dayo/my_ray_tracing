/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 00:20:59 by ymukobar          #+#    #+#             */
/*   Updated: 2021/04/11 21:38:22 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ary_size(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (i);
		while (*s && *s != c)
			s++;
		i++;
	}
	return (i);
}

static char	**free_ary(char **ary, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(ary[j]);
		j++;
	}
	free(ary);
	return (NULL);
}

static char	**split_ary(char **ary, char *s, char c)
{
	int		len;
	int		i;

	i = 0;
	while (ary)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		ary[i] = (ft_substr(s, 0, len));
		if (!ary[i])
			return (free_ary(ary, i));
		i++;
		s += len;
	}
	ary[i] = NULL;
	return (ary);
}

char	**ft_split(char const *s, char c)
{
	char	**ary;

	if (s == NULL)
		return (NULL);
	ary = malloc(sizeof(char *) * (ary_size((char *)s, c) + 1));
	if (ary == NULL)
		return (NULL);
	return (split_ary(ary, (char *)s, c));
}
