/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_headers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:46:19 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/01 20:32:18 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADERS_H
# define FT_HEADERS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

# define BUF_SIZE 1023

void	ft_putstr(char *string);
void	ft_displayerror(char *file);
void	ft_display(int argc, char **argv);
int		ft_strlen(char *string);

#endif
