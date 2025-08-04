/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:27:43 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/09 17:27:45 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if ((*str < 32) || (*str > 126))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str1 = "OIHTA5                   46~~~4687_!$#AOHG";
	char	*str2 = "groh\nowe";
	printf("Vrai : %d\n",ft_str_is_printable(str1));
	printf("Faux : %d",ft_str_is_printable(str2));
	return (0);
}
*/
