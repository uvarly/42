/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkihn <kkihn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:45:24 by uvarly            #+#    #+#             */
/*   Updated: 2019/02/13 18:03:49 by kkihn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# include <stdio.h>

# define INF 1.0 / 0

# define NRM  "\x1B[0m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

typedef enum	e_size
{
	none = 0,
	L = 5,
	ll = 4,
	l = 3,
	h = 2,
	hh = 1
}				t_size;

typedef struct	s_flags
{
	int			precision;
	int			width;
	int			align;
	int			filling;
	int			sign;
	int			space;
	int			hash;
	int			uppercase;
	t_size		size;
}				t_flags;

int				ft_printf(const char *format, ...);
int				is_data_type_specifier(char c);
void			parse_flags(va_list arglist, char **format, t_flags	*output);

void			handle_char(va_list arglist, t_flags output, int *ret);
void			handle_string(va_list arglist, t_flags output, int *ret);
void			handle_pointer(va_list arglist, t_flags output, int *ret);
void			handle_digit(va_list arglist, t_flags output, int *ret);
void			handle_unsigned_int(va_list arglist, t_flags output, int *ret);
void			handle_octet(va_list arglist, t_flags output, int *ret);
void			handle_hex(va_list arglist, t_flags output, int *ret);
void			handle_float(va_list arglist, t_flags output, int *ret);
void			handle_binary(va_list arglist, int *ret);
void			handle_nonprintable(va_list arglist, int *ret);
void			handle_percent(t_flags output, int *ret);
void			handle_binary_float(va_list arglist, t_flags output, int *ret);
void			handle_brainfuck(va_list arglist, int *ret);
void			handle_date(va_list arglist, int *ret);

void			determine_variables(t_flags *output, long double num,
		int *len, int *len_tmp);
void			put_ubase(unsigned long long num, unsigned int base,
						int uppercase);
void			put_base(long long num, int base);
int				unumlen(unsigned long long num, unsigned int base);
int				numlen(long long num, int base);
void			putnchr(char c, int amount);
void			print_float(char *num);
int				is_delimiter(char c);
int				valid_modifiers(char c);
int				is_data_type_specifier(char c);

void			putnchr(char c, int amount);
void			print_float_binary(char *num);

#endif
