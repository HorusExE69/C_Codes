/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 08:40:20 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/12 08:40:22 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_factorial(nb - 1));
}
/*
int	main(void)
{
	printf("%d \n",ft_recursive_factorial(-1));
	printf("%d \n",ft_recursive_factorial(0));
	printf("%d \n",ft_recursive_factorial(2));
	printf("%d \n",ft_recursive_factorial(5));
	return (0);
}
*/
