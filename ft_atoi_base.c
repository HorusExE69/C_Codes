/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:28:24 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/22 08:28:24 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
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

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	skip_and_get_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;
	int	b_len;
	int	idx;

	i = 0;
	res = 0;
	if (!is_valid_base(base))
		return (0);
	sign = skip_and_get_sign(str, &i);
	b_len = 0;
	while (base[b_len])
		b_len++;
	idx = get_index(str[i], base);
	while (idx != -1)
	{
		res = res * b_len + idx;
		i++;
		idx = get_index(str[i], base);
	}
	return (res * sign);
}

// #include <unistd.h>
// #include <stdio.h>

// int    main(void)
// {
// 	printf("%i\n",ft_atoi_base("   ---123", "0123456789"));
// 	printf("%i\n",ft_atoi_base("   -1010", "01"));
// 	printf("%i\n",ft_atoi_base("1A", "0123456789ABCDEF"));
// 	printf("%i\n",ft_atoi_base("one", "poneyvif"));
// 	printf("%i\n",ft_atoi_base("123", "012340")); 
// 	return (0);
// }