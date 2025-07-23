/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:48:40 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/23 08:48:45 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	is_valid_base(char *base);

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

void	ft_putnbr_base(int nbr, char *base, int *i, char *tab)
{
	long	n;
	int		base_len;

	n = nbr;
	if (!is_valid_base(base))
		return ;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		tab[(*i)++] = '-';
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base, i, tab);
	tab[(*i)++] = base[n % base_len];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		n;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!(is_valid_base(base_from) && is_valid_base(base_to)))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	while (n / ft_strlen(base_to) != 0)
	{
		count++;
		n /= ft_strlen(base_to);
	}
	res = malloc(sizeof(char) * (count + 1));
	if (!res)
		return (NULL);
	ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to, &i, res);
	res[i] = '\0';
	return (res);
}

// int main(void)
// {
// 	char *nbr = "-2a";
// 	char	*n_conv;

// 	n_conv = ft_convert_base(nbr, "0123456789abcdef", "01");
// 	__builtin_printf("%s", n_conv);
// 	free(n_conv);
// 	return (0);
// }