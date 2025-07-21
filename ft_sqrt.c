/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:10:13 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/19 08:10:14 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	r;

	r = 0;
	while (r * r <= nb)
	{
		if (r * r == nb)
			return (r);
		r += 1;
	}
	return (0);
}
/*
int	main(void)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;
	
	n1 = -5;
	n2 = 0;
	n3 = 7;
	n4 = 25;
	__builtin_printf("sqrt(%i) = %i\n",n1,ft_sqrt(n1));
	__builtin_printf("sqrt(%i) = %i\n",n2,ft_sqrt(n2));
	__builtin_printf("sqrt(%i) = %i\n",n3,ft_sqrt(n3));
	__builtin_printf("sqrt(%i) = %i",n4,ft_sqrt(n4));
	return (0);
}
*/
