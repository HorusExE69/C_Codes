/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:59:48 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/14 13:08:07 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_alpha(int i, char *str)
{
	if ((str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z')
		|| (str[i] >= '0' && str[i] <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	a;
	int	mot;

	i = 0;
	while (str[i])
	{
		if (str [0] == (str[0] >= 'A' && str[i] <= 'Z'))
			mot = 0;
		a = is_alpha((i - 1), str);
		mot = 0;
		if (a == 0)
			mot = 1;
		if (mot == 1 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] -= 32;
			mot = 0;
		}
		else if (mot == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] += 32;
		else if (str[i] >= '0' && str[i] <= '9')
			mot = 0;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	str[] = "ahi, how are you? 42words fOrty-two; fifty+aNd+one";
// 	char	*str2 = str + 1;
// 	printf("%s\n", str2);
// 	printf("%s", ft_strcapitalize(str2));
// 	return (0);
// }
