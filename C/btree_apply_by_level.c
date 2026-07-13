#include "ft_btree.h"

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
