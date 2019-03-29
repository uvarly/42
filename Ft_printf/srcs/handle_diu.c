/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:05:43 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/12 18:15:02 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_digit_aligned(t_flags output, long long num, int len)
{
	if (output.space && !output.sign && num >= 0)
		write(1, " ", 1);
	if (output.sign || num < 0)
		write(1, num < 0 ? "-" : "+", 1);
	putnchr('0', (output.precision > len) ? output.precision - len : 0);
	if ((num != 0 && output.width >= 0) || output.precision != 0)
		put_base(num, 10);
	putnchr(' ', output.width);
}

static void	print_digit_not_aligned(t_flags output, long long num, int len)
{
	if (output.space && !output.sign && num >= 0)
		write(1, " ", 1);
	if (output.width > 0 && output.filling && output.precision == -1 &&
			(output.sign || num < 0))
	{
		write(1, num < 0 ? "-" : "+", 1);
		output.sign = 0;
		num *= (num < 0) ? -1 : 1;
	}
	(output.precision < 0 && output.filling)
			? putnchr('0', output.width) : putnchr(' ', output.width);
	if (output.sign || num < 0)
		write(1, num < 0 ? "-" : "+", 1);
	putnchr('0', (output.precision > len) ? output.precision - len : 0);
	if ((num != 0 && output.width >= 0) || output.precision != 0)
		put_base(num, 10);
}

void		handle_digit(va_list arglist, t_flags output, int *ret)
{
	long long	num;
	int			len;
	int			len_tmp;

	(output.size == none) ? num = va_arg(arglist, int) : 0;
	(output.size == ll) ? num = va_arg(arglist, long long) : 0;
	(output.size == l) ? num = va_arg(arglist, long) : 0;
	(output.size == h) ? num = (short)va_arg(arglist, int) : 0;
	(output.size == hh) ? num = (char)va_arg(arglist, int) : 0;
	len = numlen(num, 10);
	len_tmp = len + ((output.sign) ? 1 : 0);
	len_tmp += (num < 0 && !output.sign) ? 1 : 0;
	len_tmp += (output.space && num >= 0 && !output.sign) ? 1 : 0;
	len_tmp += (output.precision > len) ? output.precision - len : 0;
	len_tmp -= (output.precision == 0 && num == 0) ? 1 : 0;
	len = (output.precision == 0 && num == 0) ? 0 : len;
	len_tmp = (output.width >= len_tmp) ? output.width : len_tmp;
	*ret += len_tmp;
	output.width -= output.precision > len ? output.precision : len;
	output.width -= output.space && !output.sign && num >= 0 ? 1 : 0;
	output.width -= num < 0 && !output.sign ? 1 : 0;
	output.width -= output.sign ? 1 : 0;
	output.width = (output.width < 0) ? 0 : output.width;
	(output.align) ? print_digit_aligned(output, num, len)
			: print_digit_not_aligned(output, num, len);
}

static void	print_unsigned_int(t_flags output, unsigned long long num, int len)
{
	putnchr('0', ((output.precision > len) ? output.precision - len : 0));
	(output.precision == 0 && num == 0)
				? write(1, " ", 1) : put_ubase(num, 10, output.uppercase);
}

void		handle_unsigned_int(va_list arglist, t_flags output, int *ret)
{
	unsigned long long	num;
	int					len;
	int					len_tmp;

	(output.size == none) ? (num = va_arg(arglist, unsigned int)) : 0;
	(output.size == ll) ? (num = va_arg(arglist, unsigned long long)) : 0;
	(output.size == l) ? (num = va_arg(arglist, unsigned long)) : 0;
	(output.size == h) ? (num = (unsigned short)va_arg(arglist, int)) : 0;
	(output.size == hh) ? (num = (unsigned char)va_arg(arglist, int)) : 0;
	if (output.precision == 0 && num == 0 && !output.width)
		return ;
	len = unumlen(num, 10);
	len_tmp = len + ((output.precision > len) ? output.precision - len : 0);
	*ret += (output.width >= len_tmp) ? output.width : len_tmp;
	output.width -= output.precision > len ? output.precision : len;
	(output.align) ? print_unsigned_int(output, num, len) : 0;
	if (output.align)
		putnchr(' ', (output.width < 0) ? 0 : output.width);
	if (!output.align)
		putnchr(((output.precision < 0 && output.filling)
					? '0' : ' '), (output.width < 0) ? 0 : output.width);
	(!output.align) ? print_unsigned_int(output, num, len) : 0;
}
