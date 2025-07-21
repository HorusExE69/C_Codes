/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:32:16 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/19 08:32:18 by hbretagn         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	int	res;

	res = nb;
	if (ft_is_prime(res))
		return (res);
	while (!ft_is_prime(res))
	{
		res ++;
	}
	return (res);
}
/*
int	main(void)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;
	
	n1 = -4;
	n2 = 0;
	n3 = 7;
	n4 = 10;
	
	__builtin_printf("%i\n", ft_find_next_prime(n1));
	__builtin_printf("%i\n", ft_find_next_prime(n2));
	__builtin_printf("%i\n", ft_find_next_prime(n3));
	__builtin_printf("%i", ft_find_next_prime(n4));
	return (0);
}
*/
