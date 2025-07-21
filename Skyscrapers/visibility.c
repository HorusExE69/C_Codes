/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 09:46:52 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/20 09:46:53 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible_line(int line[4], int dir)
{
	int	i;
	int	max;
	int	l_count;
	int	val;

	i = 0;
	max = 0;
	l_count = 0;
	val = 0;
	while (i < 4)
	{
		if (!dir)
			val = line[i];
		else
			val = line[3 - i];
		if (val > max)
		{
			max = val;
			l_count++;
		}
		i++;
	}
	return (l_count);
}

int	count_visible_column(int tab[4][4], int idx, int dir)
{
	int	i;
	int	max;
	int	c_count;
	int	val;

	i = 0;
	max = 0;
	c_count = 0;
	val = 0;
	while (i < 4)
	{
		if (dir)
			val = tab[i][idx];
		else
			val = tab[3 - i][idx];
		if (val > max)
		{
			max = val;
			c_count++;
		}
		i++;
	}
	return (c_count);
}

int	is_line_comp(int line[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (line[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_col_comp(int tab[4][4], int idx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][idx] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_visibility(int tab[4][4], int t_view[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (is_line_comp(tab[i]))
		{
			if (count_visible_line(tab[i], 0) != t_view[2][i])
				return (0);
			if (count_visible_line(tab[i], 1) != t_view[3][i])
				return (0);
		}
		if (is_col_comp(tab, i))
		{
			if (count_visible_column(tab, i, 1) != t_view[0][i])
				return (0);
			if (count_visible_column(tab, i, 0) != t_view[1][i])
				return (0);
		}
		i++;
	}
	return (1);
}
