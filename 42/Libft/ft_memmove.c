/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:27:26 by uvarly            #+#    #+#             */
/*   Updated: 2018/11/29 17:11:45 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*c_dst;
	const unsigned char	*c_src;
	int					delta;

	c_dst = (unsigned char *)dst;
	c_src = (const unsigned char *)src;
	if (dst < src)
		delta = 1;
	else if (dst > src)
	{
		delta = -1;
		c_dst += (n - 1);
		c_src += (n - 1);
	}
	else
		return (dst);
	while (n > 0)
	{
		*c_dst = *c_src;
		c_dst += delta;
		c_src += delta;
		n--;
	}
	return (dst);
}
