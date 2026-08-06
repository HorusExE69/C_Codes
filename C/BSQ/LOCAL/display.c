/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 16:28:13 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 09:05:32 by emmrober         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_map *map)
{
	long long int		i;
	long long int		j;
	long long int		k;
	char				*buf;

	buf = malloc((map->cols + sizeof(char)) * map->rows);
	i = 0;
	k = 0;
	if (!buf)
		return ;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
			buf[k++] = map->data[i * map->cols + j++];
		buf[k++] = '\n';
		i++;
	}
	print_map2(map, buf);
	free(buf);
}

void	print_map2(t_map *map, char *buf)
{
	long long int	i;
	long long int	chunk_size;

	i = 0;
	while (i < (map->cols + 1) * map->rows)
	{
		chunk_size = BUF_CHUNK;
		if (((map->cols + 1) * map->rows - i) < BUF_CHUNK)
			chunk_size = (map->cols + 1) * map->rows - i;
		write(1, buf + i, chunk_size);
		i += chunk_size;
	}
}
