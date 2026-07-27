/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 12:03:15 by habretag          #+#    #+#             */
/*   Updated: 2026/07/25 15:18:40 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	gen_tab(int lst[4][4]);

void	gen_view(char *str, int tab[4][4]);

int		solve(int tab[4][4], int t_view [4][4], int l, int c);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
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
		write(1, "\n", 1);
		i++;
	}
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	tab[4][4];
	int	t_view[4][4];

	if (ac == 2 && ft_strlen(av[1]) == 31)
	{
		if (!check_arg(av[1]))
			write(2, "Error\n", 6);
		else
		{
			gen_tab(tab);
			gen_view(av[1], t_view);
			if (solve(tab, t_view, 0, 0))
				disp_tab(tab);
			else
				write(2, "Error\n", 6);
		}
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
