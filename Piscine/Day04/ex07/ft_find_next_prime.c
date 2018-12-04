/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:08:06 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/20 17:20:28 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb);
int		ft_is_prime(int nb);

int		ft_is_prime(int nb)
{
	long i;

	i = 3;
	if (nb == 2 || nb == 3)
	{
		return (1);
	}
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0)
	{
		return (0);
	}
	while (i * i < nb)
	{
		if (nb % i == 0)
		{
			return (0);
		}
		i += 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (true)
	{
		if (ft_is_prime(nb))
		{
			return (nb);
		}
		nb++;
	}
}
