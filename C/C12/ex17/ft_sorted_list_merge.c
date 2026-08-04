#include "ft_list.h"
#include <stdio.h>

static void	sorted_insert_node(t_list **begin_list, t_list *node,
		int (*cmp)())
{
	t_list	*current;

	if (!*begin_list || cmp((*begin_list)->data, node->data) > 0)
	{
		node->next = *begin_list;
		*begin_list = node;
		return ;
	}
	current = *begin_list;
	while (current->next && cmp(current->next->data, node->data) <= 0)
		current = current->next;
	node->next = current->next;
	current->next = node;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*next;

	while (begin_list2)
	{
		next = begin_list2->next;
		sorted_insert_node(begin_list1, begin_list2, cmp);
		begin_list2 = next;
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

int	cmp_str(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
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
	t_list	*a;
	t_list	*b;

	a = ft_create_elem("a");
	a->next = ft_create_elem("c");
	a->next->next = ft_create_elem("e");
	b = ft_create_elem("b");
	b->next = ft_create_elem("d");
	ft_sorted_list_merge(&a, b, &cmp_str);
	print_list(a);
	return (0);
}
