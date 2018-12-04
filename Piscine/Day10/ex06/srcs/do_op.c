/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:36:55 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/30 13:26:21 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

int		get_sign(char *string)
{
	if (*string == '+')
		return (0);
	if (*string == '-')
		return (1);
	if (*string == '*')
		return (2);
	if (*string == '/')
		return (3);
	if (*string == '%')
		return (4);
	return (-1);
}

int		calculate(int a, int b, int op)
{
	int		(*function[5])(int, int);

	function[0] = &ft_add;
	function[1] = &ft_sub;
	function[2] = &ft_mul;
	function[3] = &ft_div;
	function[4] = &ft_mod;
	return ((*function[op])(a, b));
}

int		main(int argc, char **argv)
{
	int op;
	int result;

	if (argc != 4)
		return (0);
	op = get_sign(argv[2]);
	if (op == -1)
	{
		ft_putchar('0');
		return (0);
	}
	if (op == 3 && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (op == 4 && ft_atoi(argv[3]) == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	result = calculate(ft_atoi(argv[1]), ft_atoi(argv[3]), get_sign(argv[2]));
	ft_putnbr(result);
	ft_putchar('\n');
	return (0);
}
