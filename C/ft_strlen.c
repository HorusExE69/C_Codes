/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:12:10 by habretag          #+#    #+#             */
/*   Updated: 2026/07/14 12:12:11 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n ++;
	}
	return (n);
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		__builtin_printf("%i",ft_strlen(av[1]));
	return (0);
}
*/
