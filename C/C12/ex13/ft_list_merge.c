#include "ft_list.h"
#include <stdio.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last;

	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	last = *begin_list1;
	while (last->next)
		last = last->next;
	last->next = begin_list2;
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
	t_list	*l1;
	t_list	*l2;

	l1 = ft_create_elem("a");
	l1->next = ft_create_elem("b");
	l2 = ft_create_elem("c");
	l2->next = ft_create_elem("d");
	ft_list_merge(&l1, l2);
	print_list(l1);
	return (0);
}
