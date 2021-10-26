/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:24:06 by ymukobar          #+#    #+#             */
/*   Updated: 2021/04/11 21:28:07 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = nbrlen(n);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		p[0] = '-';
	}
	while (len--)
	{
		if (p[len] == '-')
			break ;
		p[len] = n % 10 + '0';
		n /= 10;
	}
	return (p);
}
