#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
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

int	main(void)
{
	t_list	*list;

	list = ft_create_elem("a");
	list->next = ft_create_elem("b");
	list->next->next = ft_create_elem("c");
	printf("last = %s\n", (char *)ft_list_last(list)->data);
	return (0);
}
