/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:51:24 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/17 08:20:45 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_src;
	unsigned int	len_dst;
	unsigned int	len_tot;
	unsigned int	i;

	len_src = len(src);
	len_dst = len(dest);
	len_tot = len_src + len_dst;
	i = len_dst;
	if (size == 0)
		return (len_src);
	else if (len_dst >= size)
		return (size + len_src);
	while (i < size - 1 && src[i - len_dst])
	{
		dest[i] = src[i - len_dst];
		i ++;
	}
	dest[i] = '\0';
	return (len_tot);
}
/*
#include <bsd/string.h>
int    main(void)
{
    char src[] = "cavapas";
    char dest[20][20] = { "bonjour", "bonjour","bonjour",
           "bonjour", "bonjour","bonjour","bonjour","bonjour",
    "bonjour","bonjour","bonjour","bonjour","bonjour",
    "bonjour","bonjour","bonjour","bonjour","bonjour",
    "bonjour","bonjour"};
    char dest1[20][20] = { "bonjour", "bonjour","bonjour",
           "bonjour", "bonjour","bonjour","bonjour","bonjour",
    "bonjour","bonjour","bonjour","bonjour","bonjour","bonjour",
    "bonjour","bonjour","bonjour","bonjour","bonjour","bonjour"};
    int i = 0;
    while (i < 18)
    {
    printf("%zu\n",strlcat(dest[i], src, i));
    printf("%s\n",dest[i]);
    printf("%d\n",ft_strlcat(dest1[i], src, i));
    printf("%s\n",dest1[i]);
    printf("-----------\n");
    i++;
    }
    return (0);
}
*/
