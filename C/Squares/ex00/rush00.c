/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:23:53 by habretag          #+#    #+#             */
/*   Updated: 2026/07/18 11:00:51 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	bottom_top0(int jx, int x)
{
	if (jx == 0 || jx == x - 1)
	{
		ft_putchar('o');
	}
	else
		ft_putchar('-');
}

void	rush0(int x, int y)
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
				bottom_top0(j, x);
			}
			else
			{
				if (j == 0 || j == x - 1)
					ft_putchar('|');
				else
					ft_putchar(' ');
			}
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
