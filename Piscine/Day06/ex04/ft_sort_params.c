/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 14:36:11 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/24 17:06:34 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_cmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	**ft_bubble_sort(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (j < argc - 1)
	{
		while (i < argc - 1)
		{
			if (ft_cmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
		}
		i = 1;
		j++;
	}
	return (argv);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	argv = ft_bubble_sort(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
