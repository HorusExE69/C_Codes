/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <hbretagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:18:58 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/21 17:28:42 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	*ft_range(int min, int max)
{
	long int	i;
	long int	j;
	int			*tab;

	tab = malloc(sizeof(int) * (max - min));
	i = min;
	j = 0;
	while (j < max - min)
	{
		tab[j] = i;
		i ++;
		j ++;
	}
	return (tab);
}

// int	main(int ac, char **av)
// {
// 	int	i;
// 	int	*tab = ft_range((atoi(av[1])), (atoi(av[2])));

// 	i = 0;
// 	if (ac == 3)
// 	{
// 		while (i < atoi(av[2]) - atoi(av[1]))
// 		{
// 			__builtin_printf("%i\n", tab[i]);
// 			i ++;
// 		}
// 	}
// 	free(tab);
// 	return (0);
// }