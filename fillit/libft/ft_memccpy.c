/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:07:41 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 13:01:27 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	unsigned char	ch;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*c_src == ch)
		{
			*c_dst = *c_src;
			c_dst++;
			return (c_dst);
		}
		*c_dst = *c_src;
		c_dst++;
		c_src++;
		n--;
	}
	return (0);
}
