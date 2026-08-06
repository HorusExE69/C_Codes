/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:41:24 by emmrober          #+#    #+#             */
/*   Updated: 2026/08/04 18:55:21 by emmrober         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	read_file_into_buffer(t_read *reader, char *path)
{
	int		fd;
	int		nb;
	char	*buf;

	buf = malloc(READ_BUF_SIZE);
	if (!buf)
		return (1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (1);
	nb = read(fd, buf, READ_BUF_SIZE);
	if (nb < 0)
		return (close(fd), 1);
	reader->fd = fd;
	reader->buf = buf;
	reader->nbytes = nb;
	reader->total = nb;
	return (0);
}

void	parse_header(char *line, t_map *map)
{
	int	i;

	i = ft_strlen(line);
	map->full = line[i - 1];
	map->obstacle = line[i - 2];
	map->empty = line[i - 3];
	line[i - 3] = '\0';
	map->rows = ft_atoi(line);
	if (map->rows <= 0)
	{
		map->err = 1;
		return ;
	}
}

int	parse_map_info(t_read *reader, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (reader->buf[i] && reader->buf[i] != '\n')
		i++;
	reader->buf[i] = '\0';
	parse_header(reader->buf, map);
	if (map->err == 1)
		return (-1);
	i++;
	while (reader->buf[i + j] && reader->buf[i + j] != '\n')
		j++;
	map->cols = j;
	map->data = malloc(sizeof(char) * (map->cols * map->rows + 1));
	if (!map->data)
		return (-1);
	return (i);
}

void	parse_map(long long int index, t_read *reader, t_map *map)
{
	long long int	j;

	j = 0;
	while (index < reader->nbytes)
	{
		if (reader->buf[index] != '\n')
			map->data[j++] = reader->buf[index];
		index++;
	}
	if (j == 0)
	{
		return (free (map->data), free (reader->buf), error(map));
	}
	reader->total = j;
}

void	read_map(char *path, t_map *map)
{
	t_read	reader;
	int		i;

	i = 0;
	if (read_file_into_buffer(&reader, path) == 1 || !reader.buf)
		return (error(map));
	i = parse_map_info(&reader, map);
	if (i <= 4)
		return (free(reader.buf), error(map));
	parse_map(i, &reader, map);
	if (map->err == 1)
		return ;
	while (reader.nbytes > 0)
	{
		reader.nbytes = read(reader.fd, reader.buf, READ_BUF_SIZE);
		if (reader.nbytes < 0)
			break ;
		fill_data_from_buffer(map, &reader);
	}
	close(reader.fd);
	free (reader.buf);
}
