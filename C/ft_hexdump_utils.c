/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:33:04 by habretag          #+#    #+#             */
/*   Updated: 2026/07/29 08:33:04 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	put_hex(unsigned int n, int width)
{
	char	*base;
	char	buf[16];
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (i < width)
	{
		buf[i] = base[(n >> ((width - 1 - i) * 4)) & 0xf];
		i++;
	}
	write(1, buf, width);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	lines_equal(unsigned char *a, unsigned char *b)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

void	copy16(unsigned char *dst, unsigned char *src)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		dst[i] = src[i];
		i++;
	}
}
