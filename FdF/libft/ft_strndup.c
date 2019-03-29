/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:49:22 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/15 14:26:37 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (n >= len)
		dst = (char *)malloc(sizeof(char) * (len + 1));
	else
		dst = (char *)malloc(sizeof(char) * (n + 1));
	if (!dst)
		return (0);
	i = 0;
	while (src[i] && n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	dst[i] = 0;
	return (dst);
}
