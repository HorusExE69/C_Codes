#include "ft_list.h"
#include <stdio.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = (*begin_list)->next;
		free_fct((*begin_list)->data);
		free(*begin_list);
		*begin_list = tmp;
	}
	current = *begin_list;
	while (current && current->next)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			free_fct(tmp->data);
			free(tmp);
		}
		else
			current = current->next;
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

void	free_data(void *data)
{
	(void)data;
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

	list = ft_create_elem("b");
	list->next = ft_create_elem("a");
	list->next->next = ft_create_elem("b");
	list->next->next->next = ft_create_elem("c");
	ft_list_remove_if(&list, "b", &cmp_str, &free_data);
	print_list(list);
	return (0);
}
