/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_headers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:52:52 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/26 18:12:49 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADERS_H
# define FT_HEADERS_H

# include <fcntl.h>
# include <unistd.h>

# define BUF_SIZE 1024

void	ft_putstr(char *str);
void	ft_print_error(int ac);

#endif
