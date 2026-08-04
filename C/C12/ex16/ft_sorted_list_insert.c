#include "ft_list.h"
#include <stdio.h>

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
	t_list	*list;

	list = NULL;
	ft_sorted_list_insert(&list, "m", &cmp_str);
	ft_sorted_list_insert(&list, "a", &cmp_str);
	ft_sorted_list_insert(&list, "z", &cmp_str);
	ft_sorted_list_insert(&list, "f", &cmp_str);
	print_list(list);
	return (0);
}
