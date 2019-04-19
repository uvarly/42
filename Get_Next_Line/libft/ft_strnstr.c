/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:29:46 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 16:30:55 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	char	*c_hst;
	char	*c_ndl;
	size_t	len;

	c_hst = (char *)haystack;
	c_ndl = (char *)needle;
	if (*c_ndl == 0)
		return (c_hst);
	len = ft_strlen((char *)needle);
	while (*c_hst && n >= len)
	{
		if (!ft_strncmp(c_hst, c_ndl, len))
			return (c_hst);
		c_hst++;
		n--;
	}
	return (0);
}
