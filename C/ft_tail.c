/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:31:04 by habretag          #+#    #+#             */
/*   Updated: 2026/07/29 11:34:56 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	process_file(char *prog, char *file,
				long long unsigned int nbytes, int mode)
{
	int		fd;
	int		size;
	char	*data;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, file);
		return ;
	}
	data = read_file(fd, &size);
	close(fd);
	print_header(file, mode);
	print_tail(data, size, nbytes);
	free(data);
}

void	process_all(int argc, char **argv,
				long long unsigned int nbytes, int nfiles)
{
	int	i;
	int	idx;

	idx = 0;
	i = 1;
	while (i < argc)
	{
		if (is_c_flag(argv[i]))
			i += 2;
		else if (is_c_attached(argv[i]))
			i += 1;
		else
		{
			process_file(basename(argv[0]), argv[i], nbytes,
				get_mode(nfiles, idx));
			idx++;
			i += 1;
		}
	}
}

int	main(int argc, char **argv)
{
	int	nbytes;
	int	nfiles;

	if (parse_args(argc, argv, &nbytes, &nfiles) == 0)
	{
		print_c_error(basename(argv[0]));
		return (1);
	}
	if (nfiles == 0)
		return (0);
	process_all(argc, argv, nbytes, nfiles);
	return (0);
}
