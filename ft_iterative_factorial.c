/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 08:30:05 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/12 08:30:08 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
	{
		res = 0;
	}
	else
	{
		if (nb == 0)
		{
			res = 1;
		}
		else
		{
			while (nb > 0)
			{
				res *= nb;
				nb --;
			}
		}
	}
	return (res);
}
/*
int	main(void)
{
	printf("%d \n",ft_iterative_factorial(-1));
	printf("%d \n",ft_iterative_factorial(0));
	printf("%d \n",ft_iterative_factorial(2));
	printf("%d \n",ft_iterative_factorial(5));
	return (0);
}
*/
