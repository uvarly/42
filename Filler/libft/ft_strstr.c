/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:56:00 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 16:30:52 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*c_hst;
	char	*c_ndl;

	c_hst = (char *)haystack;
	c_ndl = (char *)needle;
	if (*c_ndl == 0)
		return (c_hst);
	while (*c_hst)
	{
		if (!ft_strncmp(c_hst, c_ndl, ft_strlen(c_ndl)))
			return (c_hst);
		c_hst++;
	}
	return (0);
}
