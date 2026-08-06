/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 10:53:57 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 17:23:32 by emmrober         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

long long int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= c)
		return (b);
	return (c);
}

long long int	get_map_cols(char *buf, int start)
{
	int	cols;

	cols = 0;
	while (buf[start + cols] && buf[start + cols] != '\n')
		cols++;
	return (cols);
}

long long int	get_map_rows(char *buf, int start)
{
	int	rows;

	rows = 0;
	while (buf[start])
	{
		if (buf[start++] == '\n')
			rows++;
	}
	return (rows);
}
