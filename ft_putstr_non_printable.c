/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <hbretagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:17:19 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/21 15:10:54 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i >= 2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] < 32 || (unsigned char)str[i] > 126)
			ft_puthex((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

// int	main(void)
// {
// 	ft_putstr_non_printable("J'aime tou\at ce qu\bi est \tcaca, cr\fotte, 
// crott\vin, bous\fe de v\nache aussi c'e\rst bon");
// 	return (0);
// }