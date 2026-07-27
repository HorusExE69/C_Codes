/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:12:28 by habretag          #+#    #+#             */
/*   Updated: 2026/07/14 12:12:29 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int a)
{
	int	b;
	int	c;

	if (a == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (a < 0)
		{
			ft_putchar('-');
			a = -a;
		}
		b = a / 10;
		c = a % 10;
		if (b != 0)
		{
			ft_putnbr(b);
		}
		ft_putchar(c + '0');
	}
}
/*
int	main(void)
{
	ft_putnbr(492);
	return (0);
}
*/
