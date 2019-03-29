/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float_additional.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:40:27 by uvarly            #+#    #+#             */
/*   Updated: 2019/02/17 17:40:28 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	determine_variables(t_flags *output,
		long double num, int *len, int *len_tmp)
{
	*len = unumlen((num < 0) ? -num : num, 10)
			+ ((output->precision > 0) ? output->precision + 1 : 0);
	*len_tmp = *len + ((output->sign) ? 1 : 0) + ((num < 0 && !output->sign)
			? 1 : 0) + ((output->space && num >= 0 && !output->sign) ? 1 : 0);
	*len_tmp = (output->width > *len_tmp) ? output->width : *len_tmp;
	output->width -= *len + ((num < 0 || (num >= 0 && output->sign)) ? 1 : 0)
			+ ((output->space && num >= 0 && !output->sign) ? 1 : 0);
	output->width = output->width < 0 ? 0 : output->width;
	if (num >= 0 && output->space && !output->sign)
		write(1, " ", 1);
}
