/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:18:30 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/09 17:18:34 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'A' && *str <= 'Z'))
		{
			return (0);
		}
		str ++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str1 = "OIHTAEAOHG";
	char	*str2 = "grohowe";
	printf("Vrai : %d\n",ft_str_is_uppercase(str1));
	printf("Faux : %d",ft_str_is_uppercase(str2));
	return (0);
}
*/
