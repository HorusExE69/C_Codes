/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:03:21 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/11 10:03:24 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;
	int	swapped;

	if (size <= 1)
		return ;
	i = 0;
	swapped = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			swapped = 1;
		}
		i++;
	}
	if (swapped)
	{
		ft_sort_int_tab(tab, size - 1);
	}
}
/*
int main(void)
{
	int tab[5] = {2,4,1,9,7};
	ft_sort_int_tab(tab,5);
	printf("%d,%d,%d,%d,%d",tab[0],tab[1],tab[2],tab[3],tab[4]);
	return (0);
}
*/
