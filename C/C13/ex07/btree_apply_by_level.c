#include "ft_btree.h"
#include <stdio.h>

typedef struct s_queue
{
	t_btree	**nodes;
	int		*levels;
	int		front;
	int		back;
}	t_queue;

static int	count_nodes(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

static void	enqueue(t_queue *q, t_btree *node, int lvl)
{
	if (!node)
		return ;
	q->nodes[q->back] = node;
	q->levels[q->back] = lvl;
	q->back++;
}

static void	run_levels(t_queue *q, void (*applyf)(void *, int, int))
{
	t_btree	*node;
	int		lvl;
	int		prev;

	prev = -1;
	while (q->front < q->back)
	{
		node = q->nodes[q->front];
		lvl = q->levels[q->front];
		q->front++;
		applyf(node->item, lvl, lvl != prev);
		prev = lvl;
		enqueue(q, node->left, lvl + 1);
		enqueue(q, node->right, lvl + 1);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue	q;
	int		total;

	if (!root)
		return ;
	total = count_nodes(root);
	q.nodes = malloc(sizeof(t_btree *) * total);
	q.levels = malloc(sizeof(int) * total);
	q.front = 0;
	q.back = 0;
	if (!q.nodes || !q.levels)
	{
		free(q.nodes);
		free(q.levels);
		return ;
	}
	enqueue(&q, root, 0);
	run_levels(&q, applyf);
	free(q.nodes);
	free(q.levels);
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

void	print_level(void *item, int level, int is_first)
{
	printf("[%s l%d f%d] ", (char *)item, level, is_first);
}

int	main(void)
{
	t_btree	*root;

	root = btree_create_node("m");
	root->left = btree_create_node("f");
	root->right = btree_create_node("t");
	root->left->left = btree_create_node("a");
	root->right->right = btree_create_node("z");
	btree_apply_by_level(root, &print_level);
	printf("\n");
	return (0);
}
