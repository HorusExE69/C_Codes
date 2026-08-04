#include "ft_list.h"
#include <stdio.h>

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

int	main(void)
{
	t_list	*elem;

	elem = ft_create_elem("hello");
	printf("data = %s\n", (char *)elem->data);
	printf("next = %p\n", (void *)elem->next);
	free(elem);
	return (0);
}
