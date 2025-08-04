/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 08:49:41 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/16 08:22:35 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(int a)
{
	char	b;
	char	c;

	b = (a / 10) + 48;
	c = (a % 10) + 48;
	write (1, &b, 1);
	write (1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			putchar(a);
			write (1, " ", 1);
			putchar(b);
			if (a != 98)
			{
				write (1, ", ", 2);
			}
			b = b + 1;
		}
		a = a +1 ;
		b = a +1;
	}
}
/*
int   main(void)
{
        ft_print_comb2();
        return (0);
}
*/
