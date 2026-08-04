#include "ft_btree.h"
#include <stdio.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}

int	main(void)
{
	t_btree	*node;

	node = btree_create_node("root");
	printf("item = %s\n", (char *)node->item);
	printf("left = %p right = %p\n", (void *)node->left, (void *)node->right);
	free(node);
	return (0);
}
