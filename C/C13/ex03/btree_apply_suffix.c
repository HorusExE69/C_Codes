#include "ft_btree.h"
#include <stdio.h>

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
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

void	print_item(void *item)
{
	printf("%s ", (char *)item);
}

int	main(void)
{
	t_btree	*root;

	root = btree_create_node("m");
	root->left = btree_create_node("f");
	root->right = btree_create_node("t");
	btree_apply_suffix(root, &print_item);
	printf("\n");
	return (0);
}
