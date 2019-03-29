/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:57:48 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/12 14:07:05 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		numlen(long long num, int base)
{
	int	len;

	len = 1;
	while (num / base != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}

int		unumlen(unsigned long long num, unsigned int base)
{
	int	len;

	len = 1;
	while (num / base != 0)
	{
		num /= base;
		len++;
	}
	return (len);
}
