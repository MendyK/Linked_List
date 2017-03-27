#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a > b ? a : b;
}

node_t *create_node(void *word, node_t *next) {
  node_t *new_node = malloc(sizeof(node_t));
  if (new_node == NULL) {
    fprintf(stderr, "ERROR: Unable to create new node\n");
    exit(EXIT_FAILURE);
  }
  new_node->word = strdup(word);
  new_node->next = next;
  return new_node;
}

void append_node(node_t **head, void *word)
{
  node_t *new_node = create_node(word, NULL);
  if (*head == NULL) {
    *head = new_node;
  } else {
    node_t *temp = *head;

    //Compare the first word to 'word' to avoid duplicates
    if(strncmp(temp->word, word, max(strlen(temp->word),strlen(word))) == 0){
      return;
    }

    while (temp->next != NULL) {
      // Avoid adding duplicates
      if(strncmp(temp->next->word, word, max(strlen(temp->next->word),strlen(word))) == 0){
        return;
      }
      temp = temp->next;
    }

    //If next was NULL the first time, we need to check temp and word to see if they match (again, to avoid duplicates)
    if(strncmp(temp->word, word, max(strlen(temp->word), strlen(word))) == 0){
      return;
    }
    temp->next = new_node;
  }
}

/**
Returns the length of the linked list.
*/
int listLength(node_t **head) {
  if(*head == NULL){
    return 0;
  }
  node_t *temp = *head;
  int length = 0;
  while(temp != NULL){
    length++;
    temp = temp->next;
  }
  return length;
}

/**
Returns the node at the given index in the list.
Will return NULL if index is out of bounds.
*/
node_t *nodeAtIndex(node_t **head, int index)
{
  if (index > listLength(head) || index < 0){
    return NULL;
  }

  int counter = 0;
  node_t *temp = *head;

  while(temp != NULL){
    if(counter == index){
      return temp;
    }
    temp = temp->next;
    counter++;
  }
  return NULL;
}

/**
Index of given node_t in list.
Returns a negative value if the node_t is not in the list.
*/
int indexOfnode(node_t **head, node_t *node)
{
  int counter = 0;
  node_t *temp = *head;

  while(temp != NULL){

    if (node == temp){
      return counter;
    }
    temp = temp->next;
    counter++;
  }
  return -1;
}

/**
Swaps the position of node_t with the next item in the list.
*/
void swapWithNext(node_t **head, node_t *nodeToSwap)
{
  //We are switching from node_1, nodeToSwap, node_next, node_4
  //To                    node_1, node_next, nodeToSwap, node_4

  node_t *nodeNext = nodeToSwap->next;
  if (nodeToSwap == NULL || nodeNext == NULL){ return; }

  node_t *node1 = nodeAtIndex(head, indexOfnode(head, nodeToSwap) - 1);
  node_t *node4 = nodeNext->next;
  nodeNext->next = nodeToSwap;
  nodeToSwap->next = node4;

  if(node1 == NULL){
    *head = nodeNext;
  }else{
    node1->next = nodeNext;
  }
}
/*
void bubbleSort_file()
{
int swapped = 0; //boolean
int index = 0;
int length = listLength();
while(index < length - 1){
swapped = 0;
int jIndex = 0;
while(jIndex < length - 1){
node_t *current = node_tAtIndex(jIndex);
int minLength = min(strlen(current->file), strlen(current->next->file));
int result = strncmp(current->file, current->next->file, minLength);
if(result > 0){
swapWithNext(current);
swapped = 1;
}
jIndex++;
}
if (swapped == 0){
break;
}
index++;
}
}
*/

void bubbleSort_word(node_t **head) {
  int swapped = 0; //boolean
  int index = 0;

  // printf("listLength(head): %i\n", listLength(head));
  int length = listLength(head);
  while(index < length - 1){
    swapped = 0;
    int jIndex = 0;
    while(jIndex < length - 1){
      node_t *current = nodeAtIndex(head, jIndex);
      int minLength = min(strlen(current->word), strlen(current->next->word));
      int result = strncmp(current->word, current->next->word, minLength);
      if(result > 0){
        swapWithNext(head, current);
        swapped = 1;
      }
      jIndex++;
    }
    if (swapped == 0){
      break;
    }
    index++;
  }
}

/**
 * Returns a pointer to a node near the middle of the list,
 * after having truncated the original list before that point.
 */
static node_t *bisectList(node_t *head)
{
    /* The fast pointer moves twice as fast as the slow pointer. */
    /* The prev pointer points to the node preceding the slow pointer. */
    node_t *fast = head, *slow = head, *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL;
    }
    return slow;
}

node_t * mergeList(node_t *list1, node_t *list2)
{
    node_t dummy_head = { 0, NULL };
    node_t *tail = &dummy_head;

    while ( (list1 != NULL) && (list2 != NULL) )
    {
        int minLength = min(strlen(list1->word), strlen(list2->word));
        int result = strncmp(list1->word, list2->word, minLength);

        node_t **min = (result < 0) ? &list1 : &list2;

        node_t *next = (*min)->next;
        tail = tail->next = *min;
        *min = next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy_head.next;
}

node_t *merge_sort_private(node_t **head)
{
    node_t *list1 = *head;
    if ( (list1 == NULL) || (list1->next == NULL) )
    {
        return list1;
    }

    node_t *list2 = bisectList(list1);
    return mergeList( merge_sort_private(&list1), merge_sort_private(&list2) );
}

void merge_sort(node_t **head)
{
  *head = merge_sort_private(head);
}

void printList(node_t **head)
{
  node_t *current = *head;
  while (current != NULL) {
    printf("%s\n", current->word);
    current = current->next;
  }
}

/**
Removes all nodes from the list and frees all memory/
Returns a negative value if unsuccessful
*/
void removeAll(node_t **head)
{
  node_t *current = *head;
  node_t *temp = NULL;
  while (current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *head = NULL;
}
