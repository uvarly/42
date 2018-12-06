/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:56:55 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 16:25:59 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	if (n > -10 && n < 10)
		return (1);
	if (n != 0)
		return (1 + ft_numlen(n / 10));
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	len = ft_numlen(n);
	sign = (n < 0) ? 1 : 0;
	str = ft_strnew(sign + len);
	if (!str)
		return (0);
	while (len > 0)
	{
		str[sign + len - 1] = (sign) ? ((n % 10) * -1 + '0') : (n % 10 + '0');
		n /= 10;
		len--;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
