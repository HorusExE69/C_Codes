#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
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

	list = NULL;
	ft_list_push_front(&list, "c");
	ft_list_push_front(&list, "b");
	ft_list_push_front(&list, "a");
	print_list(list);
	return (0);
}
