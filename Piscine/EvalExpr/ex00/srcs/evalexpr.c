/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalexpr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:46:12 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/04 17:02:22 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval.h"
#include "../includes/functions.h"

int		ft_strtoi(char **expr)
{
	int res;

	res = 0;
	while (**expr == ' ')
		(*expr)++;
	while (**expr >= '0' && **expr <= '9')
	{
		res = (res * 10) + (**expr - '0');
		(*expr)++;
	}
	return (res);
}

int		parse_atom(char **expr)
{
	int		res;

	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		res = parse_summands(expr);
		if (**expr == ')')
			(*expr)++;
		return (res);
	}
	return (ft_strtoi(expr));
}

int		parse_factors(char **expr)
{
	int		num1;
	int		num2;
	char	oper;

	num1 = parse_atom(expr);
	while (1)
	{
		while (**expr == ' ')
			(expr)++;
		oper = **expr;
		if (oper != '*' && oper != '/' && oper != '%')
			return (num1);
		(*expr)++;
		num2 = parse_atom(expr);
		if (oper == '*')
			num1 *= num2;
		else if (oper == '/')
			num1 /= num2;
		else if (oper == '%')
			num1 %= num2;
	}
	return (num1);
}

int		parse_summands(char **expr)
{
	int		num1;
	int		num2;
	char	oper;

	num1 = parse_factors(expr);
	while (1)
	{
		while (**expr == ' ')
			(*expr)++;
		oper = **expr;
		if (oper != '+' && oper != '-')
			return (num1);
		(*expr)++;
		num2 = parse_factors(expr);
		if (oper == '+')
			num1 += num2;
		else if (oper == '-')
			num1 -= num2;
	}
	return (num1);
}

int		eval_expr(char *expr)
{
	int		i;

	i = 0;
	while (expr[i])
	{
		if (expr[i] == ' ' || expr[i] == '\t' || expr[i] == '\n')
		{
			while (expr[i])
			{
				expr[i] = expr[i + 1];
				i++;
			}
			i = -1;
		}
		i++;
	}
	return (parse_summands(&expr));
}
