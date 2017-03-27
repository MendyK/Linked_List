#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
	void *word;
	struct node *next;
} node_t;

void append_node(node_t **head, void *word);
void removeAll(node_t **head);

void printList(node_t **head);

node_t *nodeAtIndex(node_t **head, int index);
int indexOfnode(node_t **head, node_t *node);
int listLength(node_t **head);

/**
Sorting
*/
void bubbleSort_word(node_t **head);
void merge_sort(node_t **head);

#endif /* LINKED_LIST_H */
