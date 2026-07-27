/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 08:46:45 by habretag          #+#    #+#             */
/*   Updated: 2026/07/14 08:46:48 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i ++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main()
{
	char	*s1 = "coucou1";
	char	*s2 = "coucou";

	printf("offieuse = %d\n", ft_strcmp(s1, s2));
	printf("offielle = %d\n", strcmp(s1, s2));
	return (0);
}
*/
