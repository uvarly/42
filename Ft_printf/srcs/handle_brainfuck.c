/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_brainfuck.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:44:39 by uvarly            #+#    #+#             */
/*   Updated: 2019/02/16 15:44:41 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	is_prime(char c)
{
	int i;

	i = 2;
	while (i < c)
	{
		if (c % i == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	print_char_prime(char c, int *ret)
{
	int	i;
	int	braces;
	int	offset;

	braces = 0;
	while (c != 1)
	{
		i = 2;
		while (c % i != 0)
			i++;
		c /= i;
		*ret += (c != 1) ? i + 6 : i;
		putnchr('+', i);
		if (c != 1)
		{
			braces++;
			write(1, "[>", 2);
		}
	}
	offset = braces;
	while (braces--)
		write(1, "<-]", 3);
	putnchr('>', offset);
	*ret += 2;
	write(1, "+.", 2);
}

static void	print_char(char c, int *ret)
{
	int	i;
	int	braces;
	int offset;

	braces = 0;
	while (c != 1)
	{
		i = 2;
		while (c % i != 0)
			i++;
		c /= i;
		*ret += (c != 1) ? i + 6 : i;
		putnchr('+', i);
		if (c != 1)
		{
			braces++;
			write(1, "[>", 2);
		}
	}
	offset = braces;
	while (braces--)
		write(1, "<-]", 3);
	putnchr('>', offset);
	*ret += 1;
	write(1, ".", 1);
}

void		handle_brainfuck(va_list arglist, int *ret)
{
	char	*str;

	str = va_arg(arglist, char *);
	while (*str)
	{
		(is_prime(*str)) ? print_char_prime(*str - 1, ret)
						: print_char(*str, ret);
		if (*(str + 1))
		{
			*ret += 1;
			write(1, ">", 1);
		}
		str++;
	}
}
