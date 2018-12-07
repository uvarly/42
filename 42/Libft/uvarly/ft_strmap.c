/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:11:07 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 12:27:38 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = ft_strnew(len);
	if (!str)
		return (0);
	while (*s)
	{
		*str = f(*s);
		str++;
		s++;
	}
	return (str - len);
}
