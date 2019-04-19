/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:50:05 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/07 13:50:47 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*bgn;

	str = (char *)s;
	bgn = (char *)s;
	while (*str)
		str++;
	while (str >= bgn)
	{
		if (*str == (unsigned char)c)
			return (str);
		str--;
	}
	return (0);
}
