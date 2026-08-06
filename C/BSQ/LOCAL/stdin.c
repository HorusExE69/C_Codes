/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:53:32 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 19:02:01 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	reading(t_read_stdin *stdin)
{
	long long int	i;

	i = 0;
	while (i < stdin->total)
	{
		stdin->tmp[i] = stdin->result[i];
		i++;
	}
	free(stdin->result);
	i = 0;
	while (i < stdin->bytes)
	{
		stdin->tmp[stdin->total + i] = stdin->buffer[i];
		i++;
	}
}

char	*read_stdin(t_read_stdin *stdin)
{
	char			buffer[READ_BUF_SIZE];

	stdin->bytes = read(0, buffer, READ_BUF_SIZE);
	if (stdin->bytes < 0)
		return (NULL);
	while (stdin->bytes > 0)
	{
		stdin->tmp = malloc(stdin->total + stdin->bytes + 2);
		if (!stdin->tmp)
			return (free(stdin->result), NULL);
		stdin->buffer = buffer;
		reading(stdin);
		stdin->total += stdin->bytes;
		stdin->tmp[stdin->total] = '\0';
		stdin->result = stdin->tmp;
		stdin->bytes = read(0, buffer, READ_BUF_SIZE);
		if (stdin->bytes < 0)
			return (NULL);
	}
	if (stdin->result[stdin->total - 1] != '\n')
	{
		stdin->result[stdin->total++] = '\n';
		stdin->result[stdin->total] = '\0';
	}
	return (stdin->result);
}

void	read_map_from_buffer(char *buf, t_map *map)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	i++;
	map->cols = get_map_cols(buf, i);
	if (map->cols <= 0)
		return (error(map));
	map->rows = get_map_rows(buf, i);
	if (map->rows <= 0)
		return (error(map));
	map->empty = buf[i - 4];
	map->obstacle = buf[i - 3];
	map->full = buf[i - 2];
	map->data = malloc(sizeof(char) * (map->cols * map->rows + 1));
	if (!map->data)
		return (error(map));
	fill_map_data(buf, i, map->data);
}
