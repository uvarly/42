/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:17:16 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/25 10:26:23 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while ((dest[i] = src[i]) != '\0')
		i++;
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char*)malloc((sizeof(char)) * ft_strlen(src) + 1);
	if (*dest)
		return (ft_strcpy(dest, src));
	return (dest);
}
