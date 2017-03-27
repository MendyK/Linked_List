#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void rand_str(char *dest, size_t length) {
    char charset[] = "abcdefghijklmnopqrstuvwxyz";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}

void test_merge_sort()
{
  node_t *head = NULL;

  //Create a random string of fixed length
  int string_length = 4;
  int i = 0;
  for(; i < 10; i++){
    char *r_string = malloc(sizeof(char) * string_length);
    rand_str(r_string, string_length);

    append_node(&head, r_string);
  }
  printList(&head);
  merge_sort(&head);
  printf("List after merge sort:\n");
  printList(&head);
}

int main(int argc, char const *argv[])
{
  test_merge_sort();
  return 0;
}
