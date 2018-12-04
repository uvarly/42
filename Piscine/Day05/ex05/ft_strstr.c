/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:14:29 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/23 16:36:26 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int position;

	position = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[position] != '\0')
	{
		if (to_find[0] == str[position])
		{
			i = 1;
			while (to_find[i] != '\0' && to_find[i] == str[position + i])
				i++;
			if (to_find[i] == '\0')
				return (&str[position]);
		}
		position++;
	}
	return (0);
}
