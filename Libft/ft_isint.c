/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 18:29:49 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/17 18:30:34 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(const char *str)
{
	int		sign;
	int		len;

	if (!*str || !ft_isnum(str))
		return (0);
	sign = (*str == '-') ? 1 : 0;
	len = ft_strlen(str);
	if (len < 10 + sign)
		return (1);
	return (sign ? ft_strcmp(str, "-2147483648") <= 0
			: ft_strcmp(str, "2147483647") <= 0);
}
