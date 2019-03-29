/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:06:49 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 13:35:05 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *app, size_t size)
{
	char	*d;
	char	*a;
	size_t	len;

	len = strlen(dst);
	if (len >= size)
		return (size + strlen(app));
	d = (char *)dst;
	a = (char *)app;
	d += len;
	size -= len;
	while (*a && size > 1)
	{
		*d = *a;
		d++;
		a++;
		size--;
	}
	*d = 0;
	return (strlen(dst) + strlen(a));
}
