#ifndef OBJECT_NODE_HPP
#define OBJECT_NODE_HPP

#include "Object.hpp"

typedef struct node_s {
	Object			*obj;
	struct node_s	*next;
	struct node_s	*prev;
}				node_t;

void	node_init(node_t *node);
void	node_add_tail(node_t *new_node, node_t *head);
void	node_del_list(node_t *head);
void	node_del_node(node_t *node, node_t **head);
node_t	*node_new(Object *obj);

#endif // OBJECT_NODE_HPP
