/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:39:25 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/16 13:39:27 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n ++;
	}
	return (n);
}

char	*to_find_str(char *str, char *to_find, int i, int j)
{
	while (str[i] != '\0')
	{
		to_find[j] = str[i];
		j ++;
		i ++;
	}
	to_find[j] = '\0';
	return (to_find);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len_str;

	i = 0;
	j = 0;
	len_str = len(str);
	while (i != len_str + 1)
	{
		if (to_find[j] && to_find[j] == str[i])
			j ++;
		else if (!to_find[j])
			return (to_find_str(str, to_find, i, j));
		else
			j = 0;
		i ++;
	}
	return (0);
}
/*
int	main(int ac, char **av)
{
	char *c;

	if (ac == 3)
	{
		c = ft_strstr(av[1],av[2]);
		__builtin_printf("%s",c);
	}
	return (0);
}
*/
