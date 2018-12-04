/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:06:12 by uvarly            #+#    #+#             */
/*   Updated: 2018/12/04 12:08:18 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_isvalid(char *str)
{
	if (ft_atoi(str) != atoi(str))
	{
		write(1, "Error: wrong ft_atoi value:\t", 29);
		write(1, str, strlen(str));
		write(1, "\n\n", 2);
	}
}

int			main(void)
{
	ft_isvalid("0");
	ft_isvalid("123");
	ft_isvalid("-123");
	ft_isvalid("+123");
	ft_isvalid("+-123");
	ft_isvalid("-+123");
	ft_isvalid("   -123");
	ft_isvalid("	   -123	 ");
	ft_isvalid("	123		 ");
	ft_isvalid("2147483647");
	ft_isvalid("-2147483648");
	ft_isvalid("	 	 2147483647	 	 ");
	ft_isvalid("	  -2147483648 	  ");
	ft_isvalid("214 7483	647");
	ft_isvalid("214	7483 647");
	ft_isvalid("   -21474836	48");
	ft_isvalid("   -21474836	48");
	return (0);
}
