/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:48:44 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 19:07:55 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	error(t_map *map)
{
	write(2, "map error\n", 10);
	map->err = 1;
}

long long int	ft_atoi(char *str)
{
	long long int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long int	*ft_calloc(size_t nbcols, size_t type_size)
{
	void			*ptr;
	long long int	total;
	long long int	i;
	char			*tmp;

	i = 0;
	total = nbcols * type_size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	tmp = (char *)ptr;
	while (i < total)
		tmp[i++] = 0;
	return (ptr);
}
