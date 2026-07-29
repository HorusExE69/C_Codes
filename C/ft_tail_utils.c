/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:31:11 by habretag          #+#    #+#             */
/*   Updated: 2026/07/29 10:43:36 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	copy_bytes(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	print_error(char *prog, char *file)
{
	write(2, prog, ft_strlen(prog));
	write(2, ": cannot open \xE2\x80\x98", 18);
	write(2, file, ft_strlen(file));
	write(2, "\xE2\x80\x98 for reading: ", 18);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}

int	bytes_error(char *prog, char *b)
{
	if (b[0] == '0')
		return (1);
	else if (ft_atoi(b) == 0)
	{
		write(2, prog, ft_strlen(prog));
		write(2, ": invalid number of bytes: \xE2\x80\x98", 31);
		write(2, b, 1);
		write(2, "\xE2\x80\x98\n", 5);
		return (1);
	}
	return (0);
}
