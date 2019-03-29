/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:00:39 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 18:56:42 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	truncate_float(char *array, long double num)
{
	int					i;
	unsigned long long	integer_part;

	i = 0;
	while (array[i])
		i++;
	i--;
	num *= 10;
	integer_part = (num < 0) ? -num : num;
	if (integer_part >= 5)
	{
		if (array[i] >= '0' && array[i] <= '8')
			array[i]++;
		else
		{
			while (array[i] == '9')
			{
				array[i] = '0';
				i--;
				if (array[i] == '.')
					i--;
			}
			array[i]++;
		}
	}
}

static void	totally_unnecessary_function(t_flags *output,
					char *array, long double *num, int *i)
{
	unsigned long long	integer_part;
	int					integer_len;

	integer_part = (*num < 0) ? -*num : *num;
	integer_len = unumlen(integer_part, 10);
	if (!output->precision)
	{
		*num = (*num < 0) ? *num + integer_part : *num - integer_part;
		(integer_part % 2 == 1 || *num < -0.5 || *num > 0.5) ?
				truncate_float(array, *num) : 0;
		write(1, array, ft_strlen(array));
		return ;
	}
	*i += integer_len + 1;
	while (*i + ft_isdigit(array[0]) <= output->precision + integer_len + 1)
	{
		*num = (*num < 0) ? 10 * (*num + integer_part)
							: 10 * (*num - integer_part);
		integer_part = (*num < 0) ? -(*num) : *num;
		array[(*i)++] = integer_part + '0';
	}
	*num = (*num < 0) ? *num + integer_part : *num - integer_part;
	truncate_float(array, *num);
	write(1, array, ft_strlen(array));
}

static void	put_double(t_flags output, long double num, int buff)
{
	char				array[buff + 1];
	unsigned long long	integer_part;
	int					integer_len;
	int					i;

	ft_bzero(array, buff + 2);
	integer_part = (num < 0) ? -num : num;
	integer_len = unumlen(integer_part, 10);
	i = 0;
	array[integer_len + i] = (output.precision) ? '.' : 0;
	while (integer_len > 0)
	{
		array[integer_len-- + i - 1] = integer_part % 10 + '0';
		integer_part /= 10;
	}
	totally_unnecessary_function(&output, array, &num, &i);
	ft_bzero(array, buff + 2);
}

static void	put_undefined(char *name, t_flags output, int *ret)
{
	int	len;

	len = ft_strlen(name) + (ft_strequ(name, "inf")
				&& (output.sign || output.space) ? 1 : 0);
	*ret += (output.width >= len) ? output.width : len;
	if (!output.align)
		putnchr(' ', output.width > len ? output.width - len : 0);
	if (ft_strequ(name, "inf"))
	{
		output.sign ? write(1, "+inf", 4) : write(1, "inf", 3);
	}
	ft_strequ(name, "-inf") ? write(1, "-inf", 4) : 0;
	ft_strequ(name, "nan") ? write(1, "nan", 3) : 0;
	if (output.align)
		putnchr(' ', output.width > len ? output.width - len : 0);
}

void		handle_float(va_list arglist, t_flags output, int *ret)
{
	long double	num;
	int			len;
	int			len_tmp;

	num = (output.size == L) ? va_arg(arglist, long double)
			: (long double)va_arg(arglist, double);
	(num == (long double)INF) ? put_undefined("inf", output, ret) : 0;
	(num == (long double)-INF) ? put_undefined("-inf", output, ret) : 0;
	(num != num) ? put_undefined("nan", output, ret) : 0;
	if (num == INF || num == -INF || num != num)
		return ;
	determine_variables(&output, num, &len, &len_tmp);
	*ret += (output.width >= len_tmp) ? output.width : len_tmp;
	if (output.align && (num < 0 || (num >= 0 && output.sign)))
		(num < 0) ? write(1, "-", 1) : write(1, "+", 1);
	(output.align) ? put_double(output, num, len) : 0;
	(output.align) ? putnchr(' ', output.width) : 0;
	if (!output.align)
	{
		(!output.filling) ? putnchr(' ', output.width) : 0;
		if ((num < 0 || (num >= 0 && output.sign)))
			(num < 0) ? write(1, "-", 1) : write(1, "+", 1);
		(output.filling) ? putnchr('0', output.width) : 0;
	}
	(!output.align) ? put_double(output, num, len) : 0;
}
