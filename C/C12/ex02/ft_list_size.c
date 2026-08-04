#include "ft_list.h"
#include <stdio.h>

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
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
	printf("size = %d\n", ft_list_size(list));
	printf("size (NULL) = %d\n", ft_list_size(NULL));
	return (0);
}
