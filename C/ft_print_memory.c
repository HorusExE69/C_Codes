/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:55:31 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/22 12:55:35 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	get_hex(unsigned long long nb, int prev)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 16 && prev == 1)
		ft_putchar('0', 1);
	if (nb >= 16)
	{
		get_hex(nb / 16, 0);
		get_hex(nb % 16, 0);
	}
	else
		ft_putchar(base[nb], 1);
}

void	put_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			ft_putchar('0', 1);
		tmp /= 16;
	}
	get_hex(addr, 0);
}

void	put_data(unsigned char *c, int size)
{
	int		i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ', 1);
		if (i < size)
		{
			get_hex((unsigned long long)*(c + i), 1);
		}
		else if (i != 16)
		{
			ft_putchar(' ', 2);
		}
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 127)
			ft_putchar('.', 1);
		else
			ft_putchar(*(c + i), 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*c;
	unsigned int	s;

	i = 0;
	c = addr;
	while (i * 16 < size)
	{
		if (i < size / 16)
			s = 16;
		else
			s = size % 16;
		put_addr((unsigned long long)c + (i * 16));
		ft_putchar(':', 1);
		put_data(c + (i * 16), s);
		ft_putchar('\n', 1);
		i++;
	}
	return (addr);
}

// int	main(void)
// {
// 	char *str = "J'aime tou\at ce qu\bi est \tcaca,
// 	cr\fotte, crott\vin, bous\fe de v\nache aussi c'e\rst bon";

// 	ft_print_memory(str, 92);
// 	return (0);
// }