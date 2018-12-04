/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:29:46 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/30 15:37:59 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*c_hst;
	char	*c_ndl;
	size_t	i;

	c_hst = (char *)haystack;
	c_ndl = (char *)needle;
	if (*c_ndl == 0)
		return (c_hst);
	while (*c_hst && len > 0)
	{
		if (*c_hst == *c_ndl)
		{
			i = 0;
			while (c_hst[i] == c_ndl[i] && c_hst[i] && c_ndl[i])
				i++;
			if (!c_ndl[i])
				return (c_hst + i - ft_strlen(needle));
		}
		c_hst++;
		len--;
	}
	return (0);
}
