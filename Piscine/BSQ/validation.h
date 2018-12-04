/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:40:29 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/06 19:25:57 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

int	input_is_valid(char *file_name);
int	firstline_is_valid(char *map);
int	map_is_valid(char *map);
int	same_length(char *map);

#endif
