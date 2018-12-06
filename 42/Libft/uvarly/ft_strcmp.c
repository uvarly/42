/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:38:41 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/05 13:26:55 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	char	*c_str1;
	char	*c_str2;

	c_str1 = (char *)str1;
	c_str2 = (char *)str2;
	while (*c_str1 == *c_str2 && *c_str1 && *c_str2)
	{
		c_str1++;
		c_str2++;
	}
	return (*c_str1 - *c_str2);
}
