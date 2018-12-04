/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 00:25:23 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/26 01:16:50 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

char	*ft_to_lowercase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 64 || str[i] < 91))
			str[i] += 32;
		i++;
	}
	return (str);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == ' ' || s1[i] == '\t' || s1[i] == '\n')
		i++;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(ft_to_lowercase(argv[i]), "president") ||
				!ft_strcmp(ft_to_lowercase(argv[i]), "attack") ||
						!ft_strcmp(ft_to_lowercase(argv[i]), "bauer"))
			ft_putstr("Alert!!!");
		i++;
	}
	return (0);
}
