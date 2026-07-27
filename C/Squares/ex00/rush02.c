/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:04:33 by habretag          #+#    #+#             */
/*   Updated: 2026/07/18 11:57:17 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	bottom_top2(int jx, int iy, int x, int y)
{
	if (iy == 0)
	{
		if (jx == 0 || jx == x - 1)
		{
			ft_putchar('A');
		}
		else
			ft_putchar('B');
	}
	else if (iy == y - 1)
	{
		if (jx == 0 || jx == x - 1)
		{
			ft_putchar('C');
		}
		else
			ft_putchar('B');
	}
}

void	rush2(int x, int y)
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
				bottom_top2(j, i, x, y);
			}
			else
			{
				if (j == 0 || j == x - 1)
					ft_putchar('B');
				else
					ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
