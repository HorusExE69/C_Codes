/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 09:22:57 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/12 09:23:00 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
int	main(void)
{
	printf("%d \n",ft_recursive_power(4,-1));
	printf("%d \n",ft_recursive_power(0,0));
	printf("%d \n",ft_recursive_power(2,0));
	printf("%d \n",ft_recursive_power(4,3));
	return (0);
}
*/
