/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:00:21 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 15:30:09 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *dst, const char *app, size_t n)
{
	char		*c_dst;
	const char	*c_app;

	c_dst = (char *)dst + ft_strlen(dst);
	c_app = (const char *)app;
	while (*c_app && n > 0)
	{
		*c_dst = *c_app;
		c_dst++;
		c_app++;
		n--;
	}
	*c_dst = 0;
	return (dst);
}
