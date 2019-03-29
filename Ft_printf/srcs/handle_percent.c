/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:05:08 by kkihn             #+#    #+#             */
/*   Updated: 2019/02/12 14:09:23 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_percent(t_flags output, int *ret)
{
	int	c;

	c = '%';
	*ret += output.width ? output.width : 1;
	if (output.align)
	{
		write(1, &c, 1);
		while (output.width > 1)
		{
			write(1, " ", 1);
			output.width--;
		}
	}
	else
	{
		while (output.width > 1)
		{
			(output.filling) ? write(1, "0", 1) : write(1, " ", 1);
			output.width--;
		}
		write(1, &c, 1);
	}
}
