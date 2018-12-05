/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:00:36 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 14:37:16 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\n' && *s != '\t')
			count++;
		s++;
	}
	return (count);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	char	*src;
	size_t	len;
	size_t	i;

	len = ft_count((char *)s);
	dst = ft_strnew(len);
	if (!dst)
		return (0);
	src = (char *)s;
	i = 0;
	while (*src)
	{
		if (*src != ' ' && *src != '\n' && *src != '\t')
		{
			dst[i] = *src;
			i++;
		}
		src++;
	}
	return (dst);
}
