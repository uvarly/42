/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:45:20 by uvarly            #+#    #+#             */
/*   Updated: 2019/02/13 18:55:35 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_structure(t_flags *output)
{
	output->precision = -1;
	output->width = 0;
	output->align = 0;
	output->filling = 0;
	output->sign = 0;
	output->space = 0;
	output->hash = 0;
	output->uppercase = 0;
	output->size = none;
}

static void	check_bonus_flags(va_list arglist, t_flags output,
								char **format, int *ret)
{
	(**format == 'b') ? handle_binary(arglist, ret) : 0;
	(**format == 'r') ? handle_nonprintable(arglist, ret) : 0;
	(**format == 'q') ? handle_binary_float(arglist, output, ret) : 0;
	(**format == 'w') ? handle_brainfuck(arglist, ret) : 0;
	(**format == 'k') ? handle_date(arglist, ret) : 0;
}

void		separate_functions(va_list arglist, t_flags output,
								char **format, int *ret)
{
	if (is_data_type_specifier(**format))
	{
		(**format == 'c') ? handle_char(arglist, output, ret) : 0;
		(**format == 's') ? handle_string(arglist, output, ret) : 0;
		(**format == 'p') ? handle_pointer(arglist, output, ret) : 0;
		(**format == 'd' || **format == 'i') ?
				handle_digit(arglist, output, ret) : 0;
		(**format == 'o') ? handle_octet(arglist, output, ret) : 0;
		(**format == 'u') ? handle_unsigned_int(arglist, output, ret) : 0;
		(**format == 'x') ? handle_hex(arglist, output, ret) : 0;
		if (**format == 'X')
		{
			output.uppercase = 1;
			handle_hex(arglist, output, ret);
		}
		if (**format == 'f')
		{
			output.precision = (output.precision == -1) ? 6 : output.precision;
			handle_float(arglist, output, ret);
		}
		check_bonus_flags(arglist, output, format, ret);
		(**format == '%') ? handle_percent(output, ret) : 0;
		(*format)++;
	}
}

void		primary_parser(va_list arglist, char **format, int *ret)
{
	t_flags	output;

	init_structure(&output);
	while (**format == '%' && *(*format + 1) == '%')
	{
		write(1, "%", 1);
		(*format) += 2;
		*ret += 1;
		return ;
	}
	parse_flags(arglist, format, &output);
	output.width = (output.width < 0) ? -output.width : output.width;
	separate_functions(arglist, output, format, ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	arglist;
	char	*temp_format;
	char	*specifier;
	int		ret;

	va_start(arglist, format);
	ret = 0;
	temp_format = (char *)format;
	specifier = ft_strchr(temp_format, '%');
	write(1, temp_format, specifier
				? specifier - temp_format : ft_strlen(temp_format));
	ret += specifier ? specifier - temp_format : ft_strlen(temp_format);
	while (specifier)
	{
		primary_parser(arglist, &specifier, &ret);
		temp_format += specifier - temp_format;
		specifier = ft_strchr(specifier, '%');
		write(1, temp_format, specifier
				? specifier - temp_format : ft_strlen(temp_format));
		ret += specifier ? specifier - temp_format : ft_strlen(temp_format);
	}
	va_end(arglist);
	return (ret);
}
