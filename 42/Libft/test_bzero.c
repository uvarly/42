/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:09:17 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 12:16:07 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *dest, size_t n);

int	main(void)
{
	char	str[10] = "0123456789";
	ft_bzero(str, 5);
	for (int i = 0; i < 10; i++)
		if (str[i] != 0 && i < 5)
			write(1, "Error: not all bytes were set to zeroes within \
					specified range");
}
