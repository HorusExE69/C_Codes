/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 08:50:20 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/12 08:50:24 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	if (nb == 0)
	{
		return (0);
	}
	while (power > 1)
	{
		res *= nb;
		power --;
	}
	return (res);
}
/*
int	main(void)
{
	printf("%d \n",ft_iterative_power(4,-1));
	printf("%d \n",ft_iterative_power(0,0));
	printf("%d \n",ft_iterative_power(2,0));
	printf("%d \n",ft_iterative_power(4,3));
	return (0);
}
*/
