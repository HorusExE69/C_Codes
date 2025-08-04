/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:14:57 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/24 14:14:59 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

// int	ft_strlen(char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// char	*ft_strdup(char *src)
// {
// 	int		i;
// 	char	*copy;

// 	i = 0;
// 	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
// 	if (!copy)
// 		return (NULL);
// 	while (src[i])
// 	{
// 		copy[i] = src[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

// struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
// {
// 	int					i;
// 	struct s_stock_str	*array;

// 	array = malloc(sizeof(struct s_stock_str) * (ac + 1));
// 	if (!array)
// 		return (NULL);
// 	i = 0;
// 	while (i < ac)
// 	{
// 		array[i].size = ft_strlen(av[i]);
// 		array[i].str = av[i];
// 		array[i].copy = ft_strdup(av[i]);
// 		if (!array[i].copy)
// 		{
// 			while (--i >= 0)
// 				free(array[i].copy);
// 			free(array);
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	array[i].str = 0;
// 	return (array);
// }

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

// int main(int argc, char **argv)
// {
// 	t_stock_str *arr = ft_strs_to_tab(argc - 1, &argv[1]);
// 	if (!arr)
// 		return 1;
// 	ft_show_tab(arr);
// 	return 0;
// }