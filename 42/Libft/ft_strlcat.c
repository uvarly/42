/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:06:49 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 11:46:41 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *app, size_t size)
{
	char	*c_dst;
	char	*c_app;
	size_t	len;

	c_dst = (char *)dst;
	c_app = (char *)app;
	len = ft_strlen(dst);
	if (len >= size)
		return (size + ft_strlen(app));
	c_dst += len;
	size -= len;
	while (*c_app && size > 1)
	{
		*c_dst = *c_app;
		c_dst++;
		c_app++;
		size--;
	}
	*c_dst = 0;
	return (ft_strlen(dst));
}
