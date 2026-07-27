/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:04:33 by habretag          #+#    #+#             */
/*   Updated: 2026/07/18 11:56:33 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(2, "RUSH ARGS MUST CONTAIN ONLY NUMBERS\n", 36);
			return (0);
		}
		i ++;
	}
	return (1);
}

void	bottom_top(int jx, int iy, int x, int y)
{
	if (iy == 0)
	{
		if (jx == 0 || jx == x - 1)
		{
			if (jx == 0)
				ft_putchar('/');
			else
				ft_putchar('\\');
		}
		else
			ft_putchar('*');
	}
	else if (iy == y - 1)
	{
		if (jx == 0 || jx == x - 1)
		{
			if (jx == 0)
				ft_putchar('\\');
			else
				ft_putchar('/');
		}
		else
			ft_putchar('*');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == y - 1)
			{
				bottom_top(j, i, x, y);
			}
			else
			{
				if (j == 0 || j == x - 1)
					ft_putchar('*');
				else
					ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
