/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:05:24 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 16:12:55 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_hex_aligned(t_flags output, unsigned long long num, int len)
{
	int tmp;

	tmp = 0;
	if (output.hash)
	{
		if (num != 0)
			(output.uppercase) ? write(1, "0X", 2) : write(1, "0x", 2);
		else if (output.precision != 0)
			write(1, "0", 1);
	}
	if (output.precision >= len)
		putnchr('0', output.precision - len);
	if ((num != 0 || !output.hash) && !(output.precision == 0 && num == 0))
		put_ubase(num, 16, output.uppercase);
	putnchr(' ', output.width);
}

static void	print_hex_not_aligned(t_flags o, unsigned long long num, int len)
{
	if (o.width > 0 && o.hash == 2 && o.precision < 0 && o.filling && num != 0)
	{
		(o.uppercase) ? write(1, "0X", 2) : write(1, "0x", 2);
		o.hash = 0;
	}
	(o.precision < 0 && o.filling)
		? putnchr('0', o.width) : putnchr(' ', o.width);
	if (o.hash)
	{
		if (num != 0)
			(o.uppercase) ? write(1, "0X", 2) : write(1, "0x", 2);
		else if (o.precision != 0)
			write(1, "0", 1);
	}
	if (o.precision >= len)
		putnchr('0', o.precision - len);
	if ((num != 0 || !o.hash) && !(o.precision == 0 && num == 0))
		put_ubase(num, 16, o.uppercase);
}

static int	count_len_width_hex(t_flags *output, unsigned long long num,
									int len)
{
	int	len_tmp;
	int ret;

	if (output->hash && num == 0 && output->precision == 0)
		len_tmp = 0;
	else if (output->hash && num == 0 && output->precision == -1)
		len_tmp = 1;
	else
		len_tmp = (output->precision > len)
				? output->precision + output->hash : len + output->hash;
	ret = (output->width >= len_tmp) ? output->width : len_tmp;
	if (output->width == 1 && num == 0 && output->precision == 0
					&& output->hash)
		output->width = 0;
	else if (output->width > 0 && num == 0 && output->precision == -1
					&& output->hash)
		output->width = (output->width > len) ? output->width - len : 0;
	else
		output->width = (output->width > len_tmp) ? output->width - len_tmp : 0;
	return (ret);
}

void		handle_hex(va_list arglist, t_flags output, int *ret)
{
	unsigned long long	num;
	int					len;

	(output.size == none) ? num = va_arg(arglist, unsigned int) : 0;
	(output.size == ll) ? num = va_arg(arglist, unsigned long long) : 0;
	(output.size == l) ? num = va_arg(arglist, unsigned long) : 0;
	(output.size == h) ? num = (unsigned short)va_arg(arglist, int) : 0;
	(output.size == hh) ? num = (unsigned char)va_arg(arglist, int) : 0;
	len = unumlen(num, 16);
	output.hash = (output.hash && num != 0) ? 2 : 0;
	len = (output.precision == 0 && num == 0) ? 0 : len;
	*ret += count_len_width_hex(&output, num, len);
	(output.align) ? print_hex_aligned(output, num, len)
			: print_hex_not_aligned(output, num, len);
}
