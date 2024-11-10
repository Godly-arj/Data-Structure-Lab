#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char data;
  struct Node *next;
} Node;



int main() {
  int size;
  char *arr = NULL;

  Node *list = (Node *)malloc(sizeof(Node));
  list->data = 'a';

  list->next = (Node *)malloc(sizeof(Node));
  list->next->data = 'b';

  list->next->next = (Node *)malloc(sizeof(Node));
  list->next->next->data = 'b';

  list->next->next->next = (Node *)malloc(sizeof(Node));
  list->next->next->next->data = 'a';
  list->next->next->next->next = NULL;

  Node *ptr = list;

  while (ptr != NULL) {
    size++;
    arr = (char *)realloc(arr, size * sizeof(char));
    arr[size - 1] = ptr->data;
    ptr = ptr->next;
  }

  char *reversedArr = (char *)malloc(size * sizeof(char));
  reversedArr = strrev(arr);

  if (arr == reversedArr) {
    printf("%s is a palindrome!\n", arr);
  } else {
    printf("%s is not a palindrome\n", arr);
  }
}