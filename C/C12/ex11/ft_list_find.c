#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
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

int	cmp_str(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

int	main(void)
{
	t_list	*list;
	t_list	*found;

	list = ft_create_elem("a");
	list->next = ft_create_elem("b");
	list->next->next = ft_create_elem("c");
	found = ft_list_find(list, "b", &cmp_str);
	printf("find b = %s\n", found ? (char *)found->data : "NULL");
	found = ft_list_find(list, "z", &cmp_str);
	printf("find z = %s\n", found ? (char *)found->data : "NULL");
	return (0);
}
