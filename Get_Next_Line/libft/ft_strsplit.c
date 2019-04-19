/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:37:31 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 16:44:21 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static int	ft_countchars(char *str, int c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static void	ft_fillword(char *dst, char *src, int start, size_t len)
{
	src += start;
	while (*src && len > 0)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new_arr;
	size_t	words;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	words = ft_countwords((char *)s, c);
	if (!(new_arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (0);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] && s[j] == c)
			j++;
		if (!(new_arr[i] = ft_strnew(ft_countchars((char *)&s[j], c))))
			return (0);
		ft_fillword(new_arr[i], (char *)s, j, ft_countchars((char *)&s[j], c));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	new_arr[i] = 0;
	return (new_arr);
}
