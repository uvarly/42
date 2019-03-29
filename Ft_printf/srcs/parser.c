/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:06:20 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/13 17:21:23 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	parse_width(t_flags *output, char **format)
{
	output->width = ft_atoi(*format);
	(*format) += ft_numlen(output->width) - 1;
}

static void	parse_precision(va_list arglist, t_flags *output, char **format)
{
	if (*(*format + 1) == '*')
	{
		output->precision = va_arg(arglist, int);
		output->precision = (output->precision < 0) ? -1 : output->precision;
		(*format)++;
		return ;
	}
	if (*(*format + 1) < '0' || *(*format + 1) > '9')
	{
		output->precision = 0;
		return ;
	}
	(*format)++;
	output->precision = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		(*format)++;
	(*format)--;
}

static void	parse_llhh(char **format, t_flags *output)
{
	if (**format == 'h')
	{
		if (*(*format + 1) == 'h')
		{
			output->size = hh;
			(*format)++;
		}
		else
			output->size = h;
	}
	if (**format == 'l')
	{
		if (*(*format + 1) == 'l')
		{
			output->size = ll;
			(*format)++;
		}
		else
			output->size = l;
	}
	output->size = (**format == 'L') ? L : output->size;
}

void		parse_flags(va_list arglist, char **format, t_flags *output)
{
	if (**format == '%')
		(*format)++;
	while (**format && !is_data_type_specifier(**format))
	{
		while (is_delimiter(**format))
			(*format)++;
		output->align = (**format == '-') ? 1 : output->align;
		output->filling = (**format == '0') ? 1 : output->filling;
		output->sign = (**format == '+') ? 1 : output->sign;
		output->space = (**format == ' ') ? 1 : output->space;
		output->hash = (**format == '#') ? 1 : output->hash;
		if (**format == '*')
		{
			output->width = va_arg(arglist, int);
			output->align = (output->width < 0) ? 1 : 0;
		}
		if (**format >= '1' && **format <= '9')
			parse_width(output, format);
		if (**format == '.')
			parse_precision(arglist, output, format);
		parse_llhh(format, output);
		if (!(valid_modifiers(**format)))
			return ;
		(*format)++;
	}
}
