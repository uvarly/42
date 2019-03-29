/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:40:40 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 15:27:08 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char		*c_dst;
	const char	*c_src;

	c_dst = (char*)dst;
	c_src = (const char*)src;
	while (*c_src)
	{
		*c_dst = *c_src;
		c_dst++;
		c_src++;
	}
	*c_dst = 0;
	return (dst);
}
