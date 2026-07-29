/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:31:23 by habretag          #+#    #+#             */
/*   Updated: 2026/07/29 11:34:46 by habretag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <libgen.h>

int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	copy_bytes(char *dst, char *src, int n);
void	print_error(char *prog, char *file);
char	*read_file(int fd, int *size);
void	print_header(char *file, int mode);
void	print_tail(char *data, long long unsigned int size,
			long long unsigned int nbytes);
int		is_c_flag(char *arg);
int		is_c_attached(char *arg);
int		parse_args(int argc, char **argv, int *nbytes, int *nfiles);
int		get_mode(int nfiles, int idx);
void	print_c_error(char *prog);
void	process_file(char *prog, char *file,
			long long unsigned int nbytes, int mode);
void	process_all(int argc, char **argv,
			long long unsigned int nbytes, int nfiles);
int		bytes_error(char *prog, char *b);

#endif
