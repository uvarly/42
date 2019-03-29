/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:17:07 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 17:39:26 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_delimiter(char c)
{
	if (c == ';' || c == ':' || c == ',' || c == '_')
		return (1);
	return (0);
}

int	valid_modifiers(char c)
{
	if (c == '-' || c == ' ' || c == '+' || c == '#' || c == '.' ||
			c == 'h' || c == 'l' || c == 'L' || is_delimiter(c) ||
			(c >= '0' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int	is_data_type_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
			c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == 'b' ||
			c == 'r' || c == 'q' || c == 'w' || c == 'k' || c == '%')
		return (1);
	return (0);
}
