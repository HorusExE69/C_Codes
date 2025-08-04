/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:52:32 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/14 11:10:35 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return (0);
		}
		i ++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str1 = "0123";
	char	*str2 = "Hello, World !";
	printf("Vrai : %d\n",ft_str_is_numeric(str1));
	printf("Faux : %d",ft_str_is_numeric(str2));
	return (0);
}
*/
