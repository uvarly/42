/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:30:13 by uvarly            #+#    #+#             */
/*   Updated: 2018/10/27 15:30:13 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *string)
{
    int i;
    
    i = 0;
    while (string[i])
        ft_putchar(string[i++]);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int     input_is_valid(char **parameter)
{   
    int i;
    int j;

    i = 1;
    j = 0;
    while (i <= 9)
    {
        if (ft_strlen(parameter[i]) != 9) // верни 0, если хотя бы одна строка не имеет 9 символов
            return (0);
        while (j <= 9)
        {
            if ((parameter[i][j] != '.') && !(parameter[i][j] >= '0' || parameter[i][j] <= '9')) //верни 0, если символ не точка или не цифра (1-9)
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (1);
}   

int     main(int argc, char **argv)
{   
    char **table;
    
    if (argc != 10 || !input_is_valid(argv)) // выведи сообщение об ошибке, если параметров не 9 или ошибка в их вводе
    {
        ft_putstr("Error\n");
        return (0);
    }

    return (0);
}
