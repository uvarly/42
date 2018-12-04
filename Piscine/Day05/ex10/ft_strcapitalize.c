/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 10:44:31 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/23 13:14:28 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int		ft_is_symbol(int c)
{
	if ((c > 32 && c < 48) || (c > 57 && c < 65) ||
			(c > 90 && c < 97) || (c > 122 && c < 127))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		i++;
	}
	i = 0;
	if (str[0] > 96 && str[0] < 123)
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if ((ft_is_space(str[i]) || ft_is_symbol(str[i])) &&
				(str[i + 1] > 96 && str[i + 1] < 123))
			str[i + 1] -= 32;
		i++;
	}
	return (str);
}
