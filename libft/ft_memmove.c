/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:54:14 by ymukobar          #+#    #+#             */
/*   Updated: 2021/04/11 21:38:41 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t	i;

	if (!buf1 && !buf2)
		return (NULL);
	if (buf1 > buf2)
		ft_memcpy(buf1, buf2, n);
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)buf1)[i] = ((char *)buf2)[i];
			i++;
		}
	}
	return (buf1);
}
