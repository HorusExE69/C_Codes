#include "ft_btree.h"
#include <stdio.h>

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
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

void	infix(t_btree *root)
{
	if (!root)
		return ;
	infix(root->left);
	printf("%s ", (char *)root->item);
	infix(root->right);
}

int	main(void)
{
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "m", &cmp_item);
	btree_insert_data(&root, "f", &cmp_item);
	btree_insert_data(&root, "t", &cmp_item);
	btree_insert_data(&root, "a", &cmp_item);
	btree_insert_data(&root, "z", &cmp_item);
	infix(root);
	printf("\n");
	return (0);
}
