/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:20:12 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/09 15:20:21 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
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
	char	*str1 = "HelloWorld";
	char	*str2 = "Hello, World !";
	printf("Vrai : %d\n",ft_str_is_alpha(str1));
	printf("Faux : %d",ft_str_is_alpha(str2));
	return (0);
}
*/
