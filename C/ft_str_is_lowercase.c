/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:57:20 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/09 16:57:24 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!(*str >= 'a' && *str <= 'z'))
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
	char	*str1 = "ojbqvejbveojbve";
	char	*str2 = "OGSEBAOF";
	printf("Vrai : %d\n",ft_str_is_lowercase(str1));
	printf("Faux : %d",ft_str_is_lowercase(str2));
	return (0);
}
*/
