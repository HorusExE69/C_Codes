/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:50:37 by habretag          #+#    #+#             */
/*   Updated: 2026/07/25 15:08:15 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_value(int tab[4][4], int idx_l, int idx_c, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (val == tab[idx_l][i] || val == tab[i][idx_c])
			return (0);
		i++;
	}
	return (1);
}

void	gen_tab(int lst[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			lst[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	gen_view(char *str, int tab[4][4])
{
	int	l;
	int	c;
	int	i;

	i = 0;
	c = 0;
	l = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			tab[l][c] = str[i] - '0';
			c++;
			if (c == 4)
			{
				c = 0;
				l++;
			}
		}
		i++;
	}
}
