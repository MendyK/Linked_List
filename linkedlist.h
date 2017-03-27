#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
Only strings can be added to this list at the moment.
*/

typedef struct node {
	void *word;
	struct node *next;
} node_t;

void print_list(node_t **head);

/**
Appends a node to the node of the list.
Returns a negative value if you try to insert a duplicate, then does not add it to the list.
*/
int append_node(node_t **head, void *word);

/**
Removes all nodes from the list and frees all memory.
*/
void remove_all(node_t **head);

/**
Returns the node at the given index in the list.
Will return NULL if index is out of bounds.
*/
node_t *node_at_index(node_t **head, int index);

/**
Index of given node_t in list.
Returns a negative value if 'node' is not in the list.
*/
int index_of_node(node_t **head, node_t *node);

/**
Returns the length of the linked list.
*/
int list_length(node_t **head);

/**
Sorting
*/
void bubble_sort(node_t **head);
void merge_sort(node_t **head);

#endif /* LINKED_LIST_H */
