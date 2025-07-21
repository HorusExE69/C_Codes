/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:32:49 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/10 14:32:52 by hbretagn         ###   ########.fr       */
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
