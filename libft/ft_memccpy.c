/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:29:36 by ymukobar          #+#    #+#             */
/*   Updated: 2020/11/22 13:24:31 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		uc;
	unsigned char		*p1;
	const unsigned char	*p2;

	uc = (unsigned char)c;
	p1 = (unsigned char *)dst;
	p2 = (const unsigned char *)src;
	while (n > 0)
	{
		*p1 = *p2;
		if (*p2 == uc)
			return (++p1);
		p1++;
		p2++;
		n--;
	}
	return (NULL);
}
