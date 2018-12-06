/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:47:47 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 13:28:15 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char	*c_str1;
	char	*c_str2;

	c_str1 = (char *)str1;
	c_str2 = (char *)str2;
	while (*c_str1 == *c_str2 && *c_str1 && *c_str2 && n > 1)
	{
		c_str1++;
		c_str2++;
		n--;
	}
	return (*c_str1 - *c_str2);
}
