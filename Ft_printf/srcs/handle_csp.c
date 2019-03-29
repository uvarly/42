/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_csp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:05:54 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 16:20:23 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		handle_char(va_list arglist, t_flags output, int *ret)
{
	int	c;

	c = va_arg(arglist, int);
	*ret += output.width ? output.width : 1;
	if (output.align)
	{
		write(1, &c, 1);
		putnchr(' ', ((output.width - 1 > 0) ? output.width - 1 : 0));
	}
	else
	{
		putnchr(((output.filling) ? '0' : ' '), ((output.width - 1 > 0) ?
						output.width - 1 : 0));
		write(1, &c, 1);
	}
}

static void	print_null_string(int precision)
{
	write(1, "(null)", (precision >= 0 && precision < 6)
		? precision : 6);
}

void		handle_string(va_list arglist, t_flags output, int *ret)
{
	char	*s;
	int		len;

	s = va_arg(arglist, char *);
	len = (s == 0) ? 6 : ft_strlen(s);
	if (output.precision >= 0 && output.precision < len)
		len = output.precision;
	*ret += (output.width > len) ? output.width : len;
	if (output.align)
	{
		if (s == 0)
			print_null_string(output.precision);
		else
			write(1, s, len);
		putnchr(' ', ((output.width - len > 0) ? output.width - len : 0));
	}
	else
	{
		putnchr(((output.filling) ? '0' : ' '), (output.width - len > 0)
												? output.width - len : 0);
		if (s == 0)
			print_null_string(output.precision);
		else
			write(1, s, len);
	}
}

static void	print_pointer(t_flags output, unsigned long ptr)
{
	write(1, "0x", 2);
	putnchr('0', ((output.precision - 12 > 0 && ptr != 0)
						? output.precision - 12 : 0));
	putnchr('0', ((output.precision > 0 && ptr == 0)
						? output.precision - 1 : 0));
	(ptr == 0 && output.precision == 0)
						? 0 : put_ubase(ptr, 16, output.uppercase);
}

void		handle_pointer(va_list arglist, t_flags output, int *ret)
{
	unsigned long	ptr;
	int				len;

	ptr = va_arg(arglist, unsigned long);
	len = unumlen(ptr, 16);
	len = (output.precision > len) ? output.precision + 2 : len + 2;
	len -= (ptr == 0 && output.precision == 0) ? 1 : 0;
	*ret += (output.width > len) ? output.width : len;
	if (output.align)
	{
		print_pointer(output, ptr);
		putnchr(' ', ((output.width - len > 0) ? output.width - len : 0));
	}
	else
	{
		putnchr(' ', ((output.width - len > 0) ? output.width - len : 0));
		print_pointer(output, ptr);
	}
}
