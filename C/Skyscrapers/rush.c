/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:56:23 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/19 18:17:44 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		gen_tab(int lst[4][4]);

int		solve(int tab[4][4], int t_view [4][4], int l, int c);

void	gen_view(char *str, int tab[4][4]);

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n ++;
	}
	return (n);
}

void	disp_tab(int tab[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = ' ';
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = tab[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	t_view[4][4];
	int	tab[4][4];

	if (ac == 2 && ft_strlen(av[1]) == 31)
	{
		gen_tab (tab);
		gen_view(av[1], t_view);
		if (solve(tab, t_view, 0, 0))
			disp_tab(tab);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
