/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:32:21 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 13:47:53 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	str = ft_strnew(len);
	if (!str)
		return (0);
	i = 0;
	while (len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	return (str);
}
