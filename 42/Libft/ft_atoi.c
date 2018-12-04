/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:53:11 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 12:04:25 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || \
			c == '\v' || c == '\n')
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
	char	*c_str;
	int		sign;
	int		res;

	if (!str)
		return (0);
	c_str = (char *)str;
	sign = 0;
	res = 0;
	while (ft_is_whitespace(*c_str))
		c_str++;
	if (*c_str == '-')
	{
		sign = 1;
		c_str++;
	}
	if (*c_str == '+' && sign)
		return (0);
	else if (*c_str == '+' && !sign)
		c_str++;
	while (ft_is_digit(*c_str))
		res = (res * 10) + (*(c_str++) - '0');
	return (sign ? -res : res);
}
