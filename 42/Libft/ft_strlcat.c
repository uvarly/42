/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:06:49 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/30 14:48:18 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *app, size_t n)
{
	char		*c_dst;
	const char	*c_app;
	size_t		buf;

	c_dst = (char *)dst + ft_strlen(dst);
	c_app = (const char *)app;
	buf = sizeof(dst) - ft_strlen(dst) + 1;
	while (*c_app && n > 0 && buf > 0)
	{
		*c_dst = *c_app;
		c_dst++;
		c_app++;
		buf--;
		n--;
	}
	*c_dst = 0;
	return (ft_strlen(dst));
}
