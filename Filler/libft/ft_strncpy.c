/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:11:14 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 15:30:27 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*c_dst;
	const char	*c_src;

	c_dst = (char *)dst;
	c_src = (const char*)src;
	while (*c_src && len > 0)
	{
		*c_dst = *c_src;
		c_dst++;
		c_src++;
		len--;
	}
	while (len > 0)
	{
		*c_dst = 0;
		c_dst++;
		len--;
	}
	return (dst);
}
