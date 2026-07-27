/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 08:46:57 by habretag          #+#    #+#             */
/*   Updated: 2026/07/14 08:46:58 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
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
