/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:18:58 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/18 14:19:00 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*tab;

	tab = malloc(sizeof(int) * (max - min + 1));
	i = min;
	j = 0;
	while (j <= max - min - 1)
	{
		tab[j] = i;
		i ++;
		j ++;
	}
	tab[j] = 0;
	return (tab);
}
/*
int	main(int ac, char **av)
{
	int	i;
	int	*tab;


	i = 0;
	if (ac == 3)
	{
		tab = ft_range((atoi(av[1])), (atoi(av[2])));
		while (tab[i])
		{
			__builtin_printf("%i\n", tab[i]);
			i ++;
		}
	}
	return (0);
}
*/
