/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:57:05 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/09 18:57:15 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((s1[i] || s2[i]) && (i != n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	int	n = 4;
	char	*s1 = "6511616";
	char	*s2 = "651fs4h6";

	printf("offieuse = %d\n", ft_strncmp(s1, s2, n));
	printf("offielle = %d\n", strncmp(s1, s2, n));
	return (0);
}
*/
