/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:12:17 by habretag          #+#    #+#             */
/*   Updated: 2026/07/14 12:12:18 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str ++;
	}
}
/*
int	main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(av[1]);
	return (0);
}
*/
