/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 15:25:09 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 10:54:14 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	init_solver(t_point *res, long long int **curr,
	long long int **prev, int cols)
{
	*curr = ft_calloc(cols, sizeof(long long int));
	*prev = ft_calloc(cols, sizeof(long long int));
	res->x = 0;
	res->y = 0;
	res->size = 0;
}

void	update_result(t_point *res, int val, long long i, long long j)
{
	if (val > res->size)
	{
		res->size = val;
		res->y = i - val + 1;
		res->x = j - val + 1;
	}
}

t_point	solve_bsq(t_map *map)
{
	t_point		res;
	long long	*tmp;
	t_data		data;

	init_solver(&res, &data.curr, &data.prev, map->cols);
	data.i = 0;
	while (data.i < map->rows)
	{
		fill_curr_line(map, &data, &res);
		tmp = data.curr;
		data.curr = data.prev;
		data.prev = tmp;
		data.i++;
	}
	free(data.curr);
	free(data.prev);
	return (res);
}
