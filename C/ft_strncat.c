/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:25:00 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/18 08:25:04 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len_d;
	unsigned int	len_s;

	len_d = len(dest);
	len_s = len(src);
	i = 0;
	while (src[i] && i < nb)
	{
		dest[len_d + i] = src[i];
		i ++;
	}
	dest[len_d + i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char	dest[50] = "Hello, ";
	char	src[10] = "World !";
	printf("%s",ft_strncat(dest,src,6));
	return (0);
}
*/
