/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:09:10 by habretag          #+#    #+#             */
/*   Updated: 2026/07/18 11:46:33 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);
void	rush0(int x, int y);
void	rush2(int x, int y);
void	rush3(int x, int y);
void	rush4(int x, int y);
int		ft_str_is_numeric(char *str);

int	ft_atoi(char *str)
{
	int	s;
	int	res;
	int	i;

	s = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * s);
}

void	rush_selector_3arg(char **av)
{
	if (ft_atoi(av[1]) == 0)
		rush0(ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ft_atoi(av[1]) == 1)
		rush(ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ft_atoi(av[1]) == 2)
		rush2(ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ft_atoi(av[1]) == 3)
		rush3(ft_atoi(av[2]), ft_atoi(av[3]));
	else if (ft_atoi(av[1]) == 4)
		rush4(ft_atoi(av[2]), ft_atoi(av[3]));
	else
		write(2, "RUSH NUMBER INVALID\n", 20);
}

void	rush_selector_1arg(char **av)
{
	if (ft_atoi(av[1]) == 0)
		rush0(6, 7);
	else if (ft_atoi(av[1]) == 1)
		rush(6, 7);
	else if (ft_atoi(av[1]) == 2)
		rush2(6, 7);
	else if (ft_atoi(av[1]) == 3)
		rush3(6, 7);
	else if (ft_atoi(av[1]) == 4)
		rush4(6, 7);
	else
		write(2, "RUSH NUMBER INVALID\n", 20);
}

void	select_by_arg(int ac, char **av)
{
	if (ac == 4)
	{
		if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0)
			write(2, "NEGATIVE X OR Y ARE IMPOSSIBLE\n", 31);
		rush_selector_3arg(av);
	}
	else if (ac == 2)
		rush_selector_1arg(av);
	else if (ac == 3)
	{
		if (ft_atoi(av[1]) < 0 || ft_atoi(av[2]) < 0)
			write(2, "NEGATIVE X OR Y ARE IMPOSSIBLE\n", 31);
		rush(ft_atoi(av[1]), ft_atoi(av[2]));
	}
	else
		write(2, "USAGE : ./a.out [nb_rush] [nb_cols] [nb rows]\n", 46);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
	{
		rush(6, 7);
		return (0);
	}
	while (av[i])
	{
		if (!ft_str_is_numeric(av[i]))
			return (1);
		i++;
	}
	select_by_arg(ac, av);
	return (0);
}
