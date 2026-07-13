#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*current;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	if (!*begin_list || cmp((*begin_list)->data, data) > 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
		return ;
	}
	current = *begin_list;
	while (current->next && cmp(current->next->data, data) <= 0)
		current = current->next;
	elem->next = current->next;
	current->next = elem;
}
