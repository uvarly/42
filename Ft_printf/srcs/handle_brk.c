/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_brk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:06:03 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 18:55:59 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_binary(va_list arglist, int *ret)
{
	unsigned long long	num;
	int					len;

	num = va_arg(arglist, unsigned int);
	len = numlen(num, 2);
	*ret += len;
	put_base(num, 2);
}

int		print_first_part(char c)
{
	int res;

	res = 0;
	(c == 0) ? write(1, "[NUL]", 5) : 0;
	(c == 1) ? write(1, "[SOH]", 5) : 0;
	(c == 2) ? write(1, "[STX]", 5) : 0;
	(c == 3) ? write(1, "[ETX]", 5) : 0;
	(c == 4) ? write(1, "[EOT]", 5) : 0;
	(c == 5) ? write(1, "[ENQ]", 5) : 0;
	(c == 6) ? write(1, "[ACK]", 5) : 0;
	(c == 7) ? write(1, "[BEL]", 5) : 0;
	(c == 9) ? write(1, "[TAB]", 5) : 0;
	(c == 8) ? write(1, "[BS]", 4) : 0;
	(c == 10) ? write(1, "[LF]", 4) : 0;
	(c == 11) ? write(1, "[VT]", 4) : 0;
	(c == 12) ? write(1, "[FF]", 4) : 0;
	(c == 13) ? write(1, "[CR]", 4) : 0;
	(c == 14) ? write(1, "[SO]", 4) : 0;
	(c == 15) ? write(1, "[SI]", 4) : 0;
	res += ((c >= 0 && c <= 7) || c == 9) ? 5 : 4;
	return (res);
}

int		print_second_part(char c)
{
	(c == 16) ? write(1, "[DLE]", 5) : 0;
	(c == 17) ? write(1, "[DC1]", 5) : 0;
	(c == 18) ? write(1, "[DC2]", 5) : 0;
	(c == 19) ? write(1, "[DC3]", 5) : 0;
	(c == 20) ? write(1, "[DC4]", 5) : 0;
	(c == 21) ? write(1, "[NAK]", 5) : 0;
	(c == 22) ? write(1, "[SYN]", 5) : 0;
	(c == 23) ? write(1, "[ETB]", 5) : 0;
	(c == 24) ? write(1, "[CAN]", 5) : 0;
	(c == 26) ? write(1, "[SUB]", 5) : 0;
	(c == 27) ? write(1, "[ESC]", 5) : 0;
	(c == 25) ? write(1, "[EM]", 4) : 0;
	(c == 28) ? write(1, "[FS]", 4) : 0;
	(c == 29) ? write(1, "[GS]", 4) : 0;
	(c == 30) ? write(1, "[RS]", 4) : 0;
	(c == 31) ? write(1, "[US]", 4) : 0;
	return (((c >= 16 && c <= 24) || c == 26 || c == 27) ? 5 : 4);
}

void	handle_nonprintable(va_list arglist, int *ret)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(arglist, char *);
	if (s == 0)
	{
		write(1, "(null)", 6);
		*ret += 6;
		return ;
	}
	while (s[i])
	{
		if (s[i] >= 0 && s[i] <= 15)
			*ret += print_first_part(s[i]);
		else if (s[i] >= 0 && s[i] <= 15)
			*ret += print_second_part(s[i]);
		else
		{
			write(1, &s[i], 1);
			(*ret)++;
		}
		i++;
	}
}

void	handle_binary_float(va_list arglist, t_flags output, int *ret)
{
	long double	num;

	num = (output.size == L) ? va_arg(arglist, long double)
				: (long double)va_arg(arglist, double);
	*ret += 80;
	print_float((void *)&(num));
}
