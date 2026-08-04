#include "ft_btree.h"
#include <stdio.h>

int	btree_level_count(t_btree *root)
{
	int	left;
	int	right;

	if (!root)
		return (0);
	left = btree_level_count(root->left);
	right = btree_level_count(root->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
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

int	main(void)
{
	t_btree	*root;

	root = btree_create_node("m");
	root->left = btree_create_node("f");
	root->right = btree_create_node("t");
	root->left->left = btree_create_node("a");
	printf("level_count = %d\n", btree_level_count(root));
	printf("level_count (NULL) = %d\n", btree_level_count(NULL));
	return (0);
}
