/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:24:08 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/10 15:24:12 by hbretagn         ###   ########.fr       */
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
