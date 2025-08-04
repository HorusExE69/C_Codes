/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:01:14 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/09 14:01:19 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	div;
	int	mod;
	int	a;
	int	b;

	div = 0;
	mod = 0;
	a = 5;
	b = 2;
	ft_div_mod(a,b,&div,&mod);
	printf("%d / %d = %d, reste : %d", a, b, div, mod);
	return (0);
}
*/
