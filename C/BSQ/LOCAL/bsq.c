/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:47:42 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 19:09:20 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_map(t_map *map)
{
	t_point	res;

	res = solve_bsq(map);
	fill_square(map, res);
	print_map(map);
	free(map->data);
}

void	init_stdin(t_read_stdin *stdin)
{
	stdin->total = 0;
	stdin->result = NULL;
}

void	handle_argc_one(char *input, t_map *map, t_read_stdin *stdin)
{
	map->err = 0;
	init_stdin(stdin);
	input = read_stdin(stdin);
	if (input == NULL)
		return (error(map));
	read_map_from_buffer(input, map);
	if (map->err == 0)
		map_map(map);
	free(stdin->result);
}

int	main(int ac, char **av)
{
	t_map			map;
	t_read_stdin	stdin;
	int				i;
	char			*input;

	i = 1;
	input = NULL;
	if (ac == 1)
		handle_argc_one(input, &map, &stdin);
	else
	{
		while (i < ac)
		{
			map.err = 0;
			read_map(av[i++], &map);
			if (map.err == 0)
				map_map(&map);
			write(1, "\n", 1);
		}
	}
	return (0);
}
