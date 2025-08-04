/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:40:45 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/19 18:18:53 by hbretagn         ###   ########.fr       */
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
		i ++;
	}
	return (1);
}

int	gen_tab(int lst[4][4])
{
	int	i;
	int	j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			lst[i - 1][j - 1] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

void	gen_view(char *str, int tab[4][4])
{
	int	i;
	int	l;
	int	c;

	i = 0;
	l = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			tab[l][c] = str[i] - '0';
			c ++;
			if (c == 4)
			{
				c = 0;
				l ++;
			}
		}
		i ++;
	}
}
