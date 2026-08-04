#include "ft_btree.h"
#include <stdio.h>

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*found;

	if (!root)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmpf);
	if (found)
		return (found);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}

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

int	cmp_item(void *a, void *b)
{
	char	*x;
	char	*y;
	int		i;

	x = a;
	y = b;
	i = 0;
	while (x[i] && x[i] == y[i])
		i++;
	return (x[i] - y[i]);
}

int	main(void)
{
	t_btree	*root;
	char	*res;

	root = btree_create_node("m");
	root->left = btree_create_node("f");
	root->right = btree_create_node("t");
	res = btree_search_item(root, "f", &cmp_item);
	printf("search f = %s\n", res ? res : "NULL");
	res = btree_search_item(root, "z", &cmp_item);
	printf("search z = %s\n", res ? res : "NULL");
	return (0);
}
