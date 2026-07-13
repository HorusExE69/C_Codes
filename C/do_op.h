#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

void	put_nbr(int n);
int		ft_atoi(char *str);
int		op_add(int a, int b);
int		op_sub(int a, int b);
int		op_mul(int a, int b);
int		op_div(int a, int b);
int		op_mod(int a, int b);
void	fill_ops(int (*ops[5])(int, int));
int		get_op_index(char *op);
void	print_zero_error(char op);

#endif
