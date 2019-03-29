/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:53:11 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 16:31:17 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		res;

	sign = 0;
	res = 0;
	while (ft_is_whitespace(*str) && *str)
		str++;
	if (*str == '-')
	{
		sign = 1;
		str++;
	}
	if ((*str == '-' && sign) || (*str == '+' && sign))
		return (0);
	if (*str == '+')
		str++;
	while (ft_is_digit(*str) && *str)
	{
		res = (res * 10) + (int)(*str - '0');
		str++;
	}
	return (sign ? -res : res);
}
