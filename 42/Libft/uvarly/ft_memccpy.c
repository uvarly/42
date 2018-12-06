/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:07:41 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 11:54:22 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (const unsigned char *)src;
	while (n > 0)
	{
		if (*c_src == c)
			return (dst);
		*c_dst = *c_src;
		c_dst++;
		c_src++;
		n--;
	}
	return (dst);
}
