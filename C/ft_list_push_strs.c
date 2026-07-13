#include "ft_list.h"

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
