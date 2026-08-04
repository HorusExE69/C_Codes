#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (NULL);
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
	t_list	*at;

	list = ft_create_elem("a");
	list->next = ft_create_elem("b");
	list->next->next = ft_create_elem("c");
	printf("at(1) = %s\n", (char *)ft_list_at(list, 1)->data);
	at = ft_list_at(list, 9);
	printf("at(9) = %s\n", at ? (char *)at->data : "NULL");
	return (0);
}
