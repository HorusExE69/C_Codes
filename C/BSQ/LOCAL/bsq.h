/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:42:13 by habretag          #+#    #+#             */
/*   Updated: 2026/08/04 19:11:19 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_CHUNK 1048576
# define READ_BUF_SIZE 4096

typedef struct s_map
{
	long long int		rows;
	long long int		cols;
	char				empty;
	char				obstacle;
	char				full;
	char				*data;
	int					err;
}						t_map;

typedef struct s_point
{
	long long int		x;
	long long int		y;
	long long int		size;
}						t_point;

typedef struct s_read
{
	int		nbytes;
	int		total;
	int		fd;
	char	*buf;
}	t_read;

typedef struct s_read_stdin
{
	char			*tmp;
	char			*result;
	long long int	total;
	long long int	bytes;
	// long long int	prev_bytes;
	char			*buffer;
}					t_read_stdin;

typedef struct s_line_buffer
{
	long long	i;
	long long	*curr;
	long long	*prev;
}				t_data;

void			error(t_map *map);
long long int	ft_atoi(char *str);
int				ft_strlen(char	*str);
long long int	*ft_calloc(size_t nbcols, size_t type_size);
long long int	min(int a, int b, int c);
long long int	get_map_cols(char *buf, int start);
long long int	get_map_rows(char *buf, int start);
void			parse_map(long long int index, t_read *reader, t_map *map);
int				parse_map_info(t_read *reader, t_map *map);
void			parse_header(char *line, t_map *map);
int				read_file_into_buffer(t_read *reader, char *path);
void			read_map(char *path, t_map *map);
void			init_solver(t_point *res, long long int **curr,
					long long int **prev, int cols);
void			update_result(t_point *res, int val, long long i, long long j);
t_point			solve_bsq(t_map *map);
void			print_map(t_map *map);
void			print_map2(t_map *map, char *buf);
void			fill_square(t_map *map, t_point square);
void			fill_curr_line(t_map *map, t_data *buf, t_point *res);
void			fill_data_from_buffer(t_map *map, t_read *reader);
void			fill_map_data(char *buf, int start, char *data);
void			reading(t_read_stdin *stdin);
char			*read_stdin(t_read_stdin *stdin);
void			read_map_from_buffer(char *buf, t_map *map);

#endif
