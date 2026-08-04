#include "ft_list.h"
#include <stdio.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
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

void	print_str(void *data)
{
	printf("%s ", (char *)data);
}

int	main(void)
{
	t_list	*list;

	list = ft_create_elem("a");
	list->next = ft_create_elem("b");
	list->next->next = ft_create_elem("c");
	ft_list_foreach(list, &print_str);
	printf("\n");
	return (0);
}
