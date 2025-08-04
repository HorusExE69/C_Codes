/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:18:08 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/15 10:18:11 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != (10 - n))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_generate(int *tab, int index, int n)
{
	int	i;

	if (index == n)
	{
		ft_print(tab, n);
		return ;
	}
	if (index == 0)
		i = 0;
	else
		i = tab[index - 1] + 1;
	while (i <= 9)
	{
		tab[index] = i;
		ft_generate(tab, index + 1, n);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];

	if (n >= 1 && n <= 9)
		ft_generate(tab, 0, n);
}
/*
int	main(void)
{
	int	n;

	n = 9;
	if (n >= 1 && n <= 10)
		ft_print_combn(n);
	return (0);
}
*/
