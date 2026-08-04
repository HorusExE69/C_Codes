#include "ft_list.h"
#include <stdio.h>

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	void	*tmp;
	int		swapped;

	if (!begin_list || !*begin_list)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		current = *begin_list;
		while (current->next)
		{
			if (cmp(current->data, current->next->data) > 0)
			{
				tmp = current->data;
				current->data = current->next->data;
				current->next->data = tmp;
				swapped = 1;
			}
			current = current->next;
		}
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

	list = ft_create_elem("cherry");
	list->next = ft_create_elem("apple");
	list->next->next = ft_create_elem("banana");
	ft_list_sort(&list, &cmp_str);
	print_list(list);
	return (0);
}
