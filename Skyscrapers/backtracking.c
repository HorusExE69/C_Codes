/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:05:44 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/19 18:21:26 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_visibility(int tab[4][4], int t_view[4][4]);

int		is_value(int tab[4][4], int idx_l, int idx_c, int val);

int	next_l(int c, int l)
{
	int	n_line;

	if (c == 3)
	{
		n_line = l + 1;
	}
	else
	{
		n_line = l;
	}
	return (n_line);
}

int	next_c(int c)
{
	int	n_col;

	if (c == 3)
	{
		n_col = 0;
	}
	else
	{
		n_col = c + 1;
	}
	return (n_col);
}

int	solve(int tab[4][4], int t_view [4][4], int l, int c)
{
	int	n_line;
	int	n_col;
	int	val;

	if (l == 4)
	{
		return (check_visibility(tab, t_view));
	}
	n_line = next_l(c, l);
	n_col = next_c(c);
	val = 1;
	while (val <= 4)
	{
		if (is_value(tab, l, c, val))
		{
			tab[l][c] = val;
			if (solve(tab, t_view, n_line, n_col))
				return (1);
			tab[l][c] = 0;
		}
		val ++;
	}
	return (0);
}
