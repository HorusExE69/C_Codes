#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_entry
{
	unsigned long long	key;
	char				*value;
	struct s_entry		*next;
}	t_entry;

int			ft_strlen(char *s);
int			skip_spaces(char *s, int i);
int			skip_ws(char *s, int i);
int			trim_end(char *s, int start, int end);
int			next_line(char *s, int i);
char		*append(char *data, int size, char *buf, int n);
char		*read_all(int fd);
char		*substr(char *s, int start, int end);
int			valid_number(char *s, unsigned long long *n);
int			fail(int *err);
int			parse_key(char *s, int i, unsigned long long *key);
int			add_entry(t_entry **head, unsigned long long key, char *val);
int			parse_line(char *s, int i, t_entry **head, int *err);
t_entry		*parse_dict(char *s, int *err);
t_entry		*load_dict(char *path, int *err);
void		free_dict(t_entry *head);
char		*lookup(t_entry *dict, unsigned long long key);
int			all_present(t_entry *dict, unsigned long long *keys, int n);
void		print_words(t_entry *dict, unsigned long long *keys, int n);
int			convert(t_entry *dict, unsigned long long n);
int			run(char *path, char *numstr);
int			run_stdin(void);

#endif
