/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <hbretagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:59:42 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/21 14:12:09 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	size_t    j = 0;
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

// #include <bsd/string.h>
// int    main(void)
// {
// 	char src[] = "cavapas";
// 	char dest[20][20] = { "bonjour", "bonjour","bonjour",
// 			"bonjour", "bonjour","bonjour","bonjour","bonjour",
// 	"bonjour","bonjour","bonjour","bonjour","bonjour",
// 	"bonjour","bonjour","bonjour","bonjour","bonjour",
// 	"bonjour","bonjour"};
// 	char dest1[20][20] = { "bonjour", "bonjour","bonjour",
// 			"bonjour", "bonjour","bonjour","bonjour","bonjour",
// 	"bonjour","bonjour","bonjour","bonjour","bonjour","bonjour",
// 	"bonjour","bonjour","bonjour","bonjour","bonjour","bonjour"};
// 	int i = 0;
// 	while (i < 18)
// 	{
// 		printf("%zu\n",strlcpy(dest[i], src, i));
// 		printf("%s\n",dest[i]);
// 		printf("%d\n",ft_strlcpy(dest1[i], src, i));
// 		printf("%s\n",dest1[i]);
// 		printf("-----------\n");
// 	i++;
// 	}
// 	return (0);
// }