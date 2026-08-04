#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*last;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (!*begin_list)
	{
		*begin_list = elem;
		return ;
	}
	last = *begin_list;
	while (last->next)
		last = last->next;
	last->next = elem;
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
	ft_list_push_back(&list, "a");
	ft_list_push_back(&list, "b");
	ft_list_push_back(&list, "c");
	print_list(list);
	return (0);
}
