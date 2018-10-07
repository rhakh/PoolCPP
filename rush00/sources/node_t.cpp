#include "node_t.hpp"

void node_init(node_t *list) {
	list->next = NULL;
	list->prev = NULL;
	list->obj = NULL;
}

void node_add_tail(node_t *new_node, node_t *head) {

	node_t	*curr;

	curr = head;
	while (curr->next)
		curr = curr->next;

	curr->next = new_node;
	new_node->next = NULL;
	new_node->prev = curr;
}

node_t	*node_new(Object *obj) {
	node_t	*node;

	node = new node_t();
	node->obj = obj;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

void	node_del_node(node_t *node, node_t **head) {

	node_t	*prev;
	node_t	*next;

	if (!node || !*head)
		return ;

	prev = node->prev;
	next = node->next;

	if (*head == node)
		*head = next;

	if (prev)
		prev->next = next;

	if (next)
		next->prev = prev;
}

void	node_del_list(node_t *head) {
	node_t	*curr;
	node_t	*next;

	curr = head;
	while (curr) {
		next = curr->next;
		delete curr->obj;
		delete curr;
		curr = next;
	}
}
