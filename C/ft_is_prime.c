/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:23:11 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/19 08:23:13 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 0 || nb == 1)
		return (0);
	while (i < nb)
	{
		if (nb % i == 0)
			return (0);
		i ++;
	}
	return (1);
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
	n4 = 10;
	
	__builtin_printf("%i\n", ft_is_prime(n1));
	__builtin_printf("%i\n", ft_is_prime(n2));
	__builtin_printf("%i\n", ft_is_prime(n3));
	__builtin_printf("%i", ft_is_prime(n4));
	return (0);
}
*/
