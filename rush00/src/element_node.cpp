#include "element_node.hpp"

void elem_node_init(element_node_t *list) {
	list->next = NULL;
	list->prev = NULL;
	list->elem = NULL;
}

void elem_node_add_tail(element_node_t *new_node, element_node_t *head) {

	element_node_t	*curr;

	curr = head;
	while (curr->next)
		curr = curr->next;

	curr->next = new_node;
	new_node->next = NULL;
	new_node->prev = curr;
}

element_node_t	*elem_node_new(Element *_elem) {
	element_node_t	*node;

	node = new element_node_t();
	node->elem = _elem;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

void	elem_node_del_node(element_node_t *node, element_node_t **head) {

	element_node_t	*prev;
	element_node_t	*next;

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

void	elem_node_del_list(element_node_t *head) {
	element_node_t	*curr;
	element_node_t	*next;

	curr = head;
	while (curr) {
		next = curr->next;
		delete curr->elem;
		delete curr;
		curr = next;
	}
}
