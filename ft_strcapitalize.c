/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:59:48 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/15 08:24:46 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_test(char *str, int i)
{
	if (!((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			|| (str[i - 1] >= '0' && str[i - 1] <= '9')
			|| (str[i - 1] >= 'a' && str[i - 1] <= 'z'))
		&& (str[i] >= 'a' && str[i] <= 'z'))
		return (1);
	else
		return (0);
}

char	ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	i++;
	while (str[i] != '\0')
	{
		if (ft_test(str, i))
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i ++;
	}
	return (*str);
}
/*
int	main(void)
{
        char    a[] = "hi,j h AAAAA-GGG--AA 42wORds forty-two; fifty+and+one";
        ft_strcapitalize(a);
        printf("%s", a);
}
*/
