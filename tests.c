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
    char *r_string = malloc(sizeof(char) * string_length);;
    rand_str(r_string, string_length);

    append_node(&head, r_string);
  }
  print_list(&head);
  merge_sort(&head);
  printf("List after merge sort:\n");
  print_list(&head);
}

void test_append_node()
{
  node_t *head = NULL;
  int string_length = 4;
  int i = 0;
  for(; i < 10; i++){
    char *r_string = malloc(sizeof(char) * string_length);;
    rand_str(r_string, string_length);

    printf("Appending: %s\n",r_string );
    append_node(&head, r_string);
  }
  printf("List:\n");
  print_list(&head);

  printf("TEST#2: Attempting to insert duplicates...\n");
  for(; i < 100; i++){
    node_t *random_node = node_at_index(&head, rand() % list_length(&head));

    printf("Attempting to append: %s\n", random_node->word);
    int result = append_node(&head, random_node->word);
    if(result < 0){
      printf("Unsuccessful. Great!\n");
    }else{
      printf("Successful. There is an issue with append_node\n");

    }
  }

  printf("List:\n");
  print_list(&head);

}

void test_bubble_sort()
{
  node_t *head = NULL;

  //Create a random string of fixed length
  int string_length = 4;
  int i = 0;
  for(; i < 10; i++){
    char *r_string = malloc(sizeof(char) * string_length);;
    rand_str(r_string, string_length);

    append_node(&head, r_string);
  }
  print_list(&head);
  bubble_sort(&head);
  printf("List after bubble sort:\n");
  print_list(&head);
}

int main(int argc, char const *argv[])
{
  // test_merge_sort();
  // test_append_node();
  // test_bubble_sort();

  return 0;
}
