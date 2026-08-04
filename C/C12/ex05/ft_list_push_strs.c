#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*elem;
	int		i;

	list = NULL;
	i = 0;
	while (i < size)
	{
		elem = ft_create_elem((void *)strs[i]);
		if (!elem)
			return (list);
		elem->next = list;
		list = elem;
		i++;
	}
	return (list);
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
	char	*strs[] = {"one", "two", "three"};
	t_list	*list;

	list = ft_list_push_strs(3, strs);
	print_list(list);
	return (0);
}
