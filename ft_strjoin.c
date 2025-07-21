/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <hbretagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:32:25 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/20 18:36:53 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int	len_d;
	int	len_s;
	int	i;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	i = 0;
	while (i <= len_s)
	{
		dest[len_d + i] = src[i];
		i ++;
	}
	dest[len_d + i + 1] = '\0';
	return (*&dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i ++;
	}
	i = 0;
	str = malloc(sizeof(char) * len);
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		i ++;
	}
	return (str);
}

// int	main(void)
// {
// 	char	*strs[] = {"[1]    305454 segmentation fault","(core dumped)  ./exec.sh"};
// 	char	*sep = " ";
// 	char	*chain = ft_strjoin(2, strs, sep);

// 	__builtin_printf("%s\n",chain);
// 	free(chain);
// 	return (0);
// }

