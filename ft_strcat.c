/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 08:56:09 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/10 08:56:12 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

char	*ft_strcat(char *dest, char *src)
{
	int	len_d;
	int	len_s;
	int	i;

	len_d = len(dest);
	len_s = len(src);
	i = 0;
	while (i <= len_s)
	{
		dest[len_d + i] = src[i];
		i ++;
	}
	dest[len_d + i + 1] = '\0';
	return (*&dest);
}

/*
int main(void)
{
	char	dest[50] = "Hello, ";
	char	src[10] = "World !";
	printf("%s",ft_strcat(dest,src));
	return 0;
}
*/
