#include "ft_list.h"
#include <stdio.h>

static int	rev_size(t_list *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}

static t_list	*rev_at(t_list *lst, int idx)
{
	while (idx > 0 && lst)
	{
		lst = lst->next;
		idx--;
	}
	return (lst);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		size;
	void	*tmp;
	t_list	*a;
	t_list	*b;

	size = rev_size(begin_list);
	i = 0;
	while (i < size / 2)
	{
		a = rev_at(begin_list, i);
		b = rev_at(begin_list, size - 1 - i);
		tmp = a->data;
		a->data = b->data;
		b->data = tmp;
		i++;
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s ", (char *)lst->data);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*list;

	list = ft_create_elem("a");
	list->next = ft_create_elem("b");
	list->next->next = ft_create_elem("c");
	ft_list_reverse_fun(list);
	print_list(list);
	return (0);
}
