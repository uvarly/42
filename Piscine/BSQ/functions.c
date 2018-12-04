/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:26:41 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/06 19:25:39 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *orig)
{
	int i;

	i = 0;
	while (orig[i])
	{
		dest[i] = orig[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		custom_atoi(char *str, int end_i)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (i < end_i)
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}
