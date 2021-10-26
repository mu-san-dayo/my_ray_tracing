/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:29:53 by ymukobar          #+#    #+#             */
/*   Updated: 2021/04/11 20:57:39 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	char	*sv;

	p = (char *)s;
	sv = NULL;
	while (1)
	{
		if (*p == (char)c)
			sv = p;
		if (*p == '\0')
			break ;
		p++;
	}
	return (sv);
}
