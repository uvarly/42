/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 11:09:05 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/19 19:53:43 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str);

char	*ft_strrev(char *str)
{
	char	temp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	while (i < (count / 2))
	{
		temp = str[i];
		str[i] = str[i - i - 1];
		str[i - i - 1] = temp;
		i++;
	}
	return (str);
}
