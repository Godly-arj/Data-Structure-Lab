#include <stdio.h>
#include <stdlib.h>
struct Node {
int row;
int col;
int value;
struct Node* next;
};
struct SparseMatrix {
struct Node* head;
int rows;
int cols;
};
void insert(struct SparseMatrix* matrix, int row, int col, int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->row = row;
newNode->col = col;
newNode->value = value;
newNode->next = matrix->head;
matrix->head = newNode;
}
void display(struct SparseMatrix* matrix) {
struct Node* current;
printf("Sparse Matrix Representation:\n");
for (int i = 0; i < matrix->rows; i++) {
for (int j = 0; j < matrix->cols; j++) {
current = matrix->head;
int found = 0;
while (current != NULL) {
if (current->row == i && current->col == j) {
printf("%d ", current->value);
found = 1;
break;
}
current = current->next;
}
if (!found) {
printf("0 "); // Print 0 if no value is found
}
}
printf("\n");
}
}
int main() {
struct SparseMatrix matrix;
matrix.head = NULL;
printf("Enter the number of rows and columns of the matrix: ");
scanf("%d %d", &matrix.rows, &matrix.cols);
int nonZeroCount;
printf("Enter the number of non-zero elements: ");
scanf("%d", &nonZeroCount);
for (int i = 0; i < nonZeroCount; i++) {
int row, col, value;
printf("Enter row, column and value of non-zero element %d: ", i + 1);
scanf("%d %d %d", &row, &col, &value);
if (row < matrix.rows && col < matrix.cols) {
insert(&matrix, row, col, value);
} else {printf("Invalid position! Please enter values within matrix dimensions.\n");
i--; // Decrement i to repeat this iteration
}
}
display(&matrix);
// Free memory
struct Node* current = matrix.head;
struct Node* nextNode;
while (current != NULL) {
nextNode = current->next;
free(current);
current = nextNode;
}
return 0;
}