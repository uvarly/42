/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:02:40 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 11:54:11 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*c_dst;
	const unsigned char		*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (const unsigned char *)src;
	while (n > 0)
	{
		*c_dst = *c_src;
		c_dst++;
		c_src++;
		n--;
	}
	return (dst);
}
