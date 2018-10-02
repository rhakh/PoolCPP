#ifndef ELEMENT_NODE_HPP
#define ELEMENT_NODE_HPP

#include "Element.hpp"

typedef struct element_node_s {
	Element					*elem;
	struct element_node_s	*next;
	struct element_node_s	*prev;
}				element_node_t;

void	elem_node_init(element_node_t *node);
void	elem_node_add_tail(element_node_t *new_node, element_node_t *head);
void	elem_node_del_list(element_node_t *head);
void	elem_node_del_node(element_node_t *node, element_node_t **head);
element_node_t	*elem_node_new(Element *_elem);

#endif // ELEMENT_NODE_HPP
