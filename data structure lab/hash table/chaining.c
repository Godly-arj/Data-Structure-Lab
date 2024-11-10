#include <stdio.h>
#include <stdlib.h>
#define N 9
struct node {
int info;
struct node *next;
} *top[N] = {NULL}, *ptr, *temp;
void insert(int v, int w) {
ptr = malloc(sizeof

(struct node));

ptr->info = w;
ptr->next = NULL
;
if (top[v] == NULL) {
top[v] = ptr;
} else {
temp = top[v];
while (temp->next != NULL) {
temp = temp->next; }
temp->next = ptr; }}
void display(int k) {
temp = top[k];
printf("Index %d: ", k);
if (temp == NULL) {
printf("Empty\n");

} else {
while (temp != NULL) {
printf(
"%d -> ", temp->info);
temp = temp->next; }
printf("NULL\n");
}}
int main() {
int i, key, no, index;
printf("Enter the number of keys: ");
scanf("%d", &no);
for (i =0; i < no; i++)
 {
printf("Enter key %d: ", i +1);
scanf("%d", &key);
index = key % N;
insert(index, key); }
printf(
"\nHash Table (Separate Chaining):\n");
for (i =0; i < N; i++)
 {
display(i); 
}
return 0;
}