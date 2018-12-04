/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:52:48 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/25 12:13:49 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_concat_params(int argc, char **argv)
{
	unsigned int 	i;
	unsigned int 	memory;
	char			*line;

	i = 1;
	memory = 0;

	while (i < argc)
	{
		memory += ft_strlen(argv[i]) + 2;
		i++;
	}
	i = 1;
	line = (char*)malloc(sizeof(char) * memory);
	while (i < argc)
	{
		line = ft_strcat(line, argv[i]);
		i++;
	}
	return (line);
}
