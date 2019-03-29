/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:05:24 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/14 17:19:53 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_octet_aligned(t_flags output, unsigned long long num, int len)
{
	int tmp;

	tmp = 0;
	if (output.hash)
		write(1, "0", 1);
	tmp = output.precision - len - ((num != 0) ? output.hash : 0);
	putnchr('0', (tmp > 0) ? tmp : 0);
	if ((num != 0 || !output.hash) && !(output.precision == 0 && num == 0))
		put_ubase(num, 8, output.uppercase);
	putnchr(' ', output.width);
}

static void	print_octet_not_aligned(t_flags o, unsigned long long num, int len)
{
	(o.precision < 0 && o.filling)
		? putnchr('0', o.width) : putnchr(' ', o.width);
	if (o.hash)
		write(1, "0", 1);
	if (o.precision >= len + o.hash)
		putnchr('0', o.precision - len - ((num == 0) ? 0 : o.hash));
	if ((num != 0 || !o.hash) && !(o.precision == 0 && num == 0))
		put_ubase(num, 8, o.uppercase);
}

static int	count_len_width_octet(t_flags *output, unsigned long long num,
									int len)
{
	int	len_tmp;
	int ret;

	if (output->hash && num == 0 && output->precision == -1)
		len_tmp = 1;
	else
		len_tmp = (output->precision > len)
				? output->precision + output->hash : len + output->hash;
	ret = (output->width >= len_tmp) ? output->width : len_tmp;
	if (output->width == 1 && num == 0 && output->precision == 0
				&& output->hash)
		output->width = 0;
	else
	{
		output->width = (output->width > len_tmp) ? output->width - len_tmp : 0;
		if (output->width > 0 && output->precision > 0
				&& output->hash)
			output->width++;
	}
	return (ret);
}

void		handle_octet(va_list arglist, t_flags output, int *ret)
{
	unsigned long long	num;
	int					len;

	(output.size == none) ? num = va_arg(arglist, unsigned int) : 0;
	(output.size == ll) ? num = va_arg(arglist, unsigned long long) : 0;
	(output.size == l) ? num = va_arg(arglist, unsigned long) : 0;
	(output.size == h) ? num = (unsigned short)va_arg(arglist, int) : 0;
	(output.size == hh) ? num = (unsigned char)va_arg(arglist, int) : 0;
	len = unumlen(num, 8);
	if (output.precision == 0 && num == 0)
		len = 0;
	*ret += count_len_width_octet(&output, num, len);
	(output.align) ? print_octet_aligned(output, num, len)
			: print_octet_not_aligned(output, num, len);
}
