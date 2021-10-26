/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:25:00 by ymukobar          #+#    #+#             */
/*   Updated: 2021/04/11 21:34:21 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (s == NULL)
		return (NULL);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (p);
	ft_strlcpy(p, s + start, len + 1);
	return (p);
}
