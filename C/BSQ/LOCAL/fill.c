/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:41:31 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 16:41:51 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_curr_line(t_map *map, t_data *buf, t_point *res)
{
	long long	j;

	j = 0;
	while (j < map->cols)
	{
		if (map->data[buf->i * map->cols + j] == map->obstacle)
			buf->curr[j] = 0;
		else if (buf->i == 0 || j == 0)
			buf->curr[j] = 1;
		else
			buf->curr[j] = 1 + min(buf->prev[j],
					buf->curr[j - 1], buf->prev[j - 1]);
		update_result(res, buf->curr[j], buf->i, j);
		j++;
	}
}

void	fill_square(t_map *map, t_point square)
{
	long long int	i;
	long long int	j;

	i = 0;
	while (i < square.size)
	{
		j = 0;
		while (j < square.size)
		{
			map->data[(square.y + i) * map->cols + (square.x + j)] = map->full;
			j++;
		}
		i++;
	}
}

void	fill_map_data(char *buf, int start, char *data)
{
	int	j;

	j = 0;
	while (buf[start])
	{
		if (buf[start] != '\n')
			data[j++] = buf[start];
		start++;
	}
	data[j] = '\0';
}

void	fill_data_from_buffer(t_map *map, t_read *reader)
{
	int	i;

	i = 0;
	while (i < reader->nbytes && reader->total < map->cols * map->rows)
	{
		if (reader->buf[i] != '\n')
		{
			map->data[reader->total] = reader->buf[i];
			reader->total++;
		}
		i++;
	}
}
