#include "ft_list.h"

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
