/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_date.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:45:49 by uvarly            #+#    #+#             */
/*   Updated: 2019/02/16 15:45:51 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	determine_year(int *date)
{
	unsigned int	year;

	year = 1;
	while (*date > 365)
	{
		*date -= ((year % 400 == 0 || year % 4 == 0)
				&& year % 100 != 0) ? 366 : 365;
		year++;
	}
	return (year);
}

static void			init_calendar(int *calendar, int leap_year)
{
	calendar[0] = 0;
	calendar[1] = 31;
	calendar[2] = (leap_year) ? 29 : 28;
	calendar[3] = 31;
	calendar[4] = 30;
	calendar[5] = 31;
	calendar[6] = 30;
	calendar[7] = 31;
	calendar[8] = 31;
	calendar[9] = 30;
	calendar[10] = 31;
	calendar[11] = 30;
	calendar[12] = 31;
}

static unsigned int	determine_month(int *date, unsigned int year)
{
	unsigned int	month;
	int				calendar[13];
	int				leap_year;

	leap_year = ((year % 400 == 0 || year % 4 == 0)
			&& year % 100 != 0) ? 1 : 0;
	init_calendar(calendar, leap_year);
	month = 1;
	while (*date - calendar[month] > 0)
	{
		*date -= calendar[month];
		month = (month > 12) ? 1 : month + 1;
	}
	return (month);
}

static void			print_date(int date)
{
	unsigned int		year;
	unsigned int		month;
	unsigned int		day;

	year = determine_year(&date);
	month = determine_month(&date, year);
	day = date;
	(year / 1000 == 0) ? write(1, "0", 1) : 0;
	(year / 100 == 0) ? write(1, "0", 1) : 0;
	(year / 10 == 0) ? write(1, "0", 1) : 0;
	ft_putnbr(year < 10000 ? year : 9999);
	write(1, "-", 1);
	(month < 10) ? write(1, "0", 1) : 0;
	ft_putnbr(month);
	write(1, "-", 1);
	(day < 10) ? write(1, "0", 1) : 0;
	ft_putnbr(day);
}

void				handle_date(va_list arglist, int *ret)
{
	int	date;

	date = va_arg(arglist, int);
	print_date(date + 1);
	*ret += 10;
}
