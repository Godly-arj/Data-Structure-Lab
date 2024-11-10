#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }
    list->tail = newNode;
    printf("Element is added\n");
}

void addNodeAfter(LinkedList* list, int nextTo, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = list->head;

    while (temp != NULL && temp->data != nextTo) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position not found\n");
        return;
    }

    if (temp == list->tail) {
        list->tail->next = newNode;
        list->tail = newNode;
        printf("Element is added\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Element is added\n");
}

void deleteNode(LinkedList* list, int data) {
    Node* temp = list->head, *prev = NULL;
    if (temp != NULL && temp->data == data) {
        list->head = temp->next;
        printf("Element is deleted\n");
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element is not present to delete\n");
        return;
    }

    if (temp == list->tail) {
        list->tail = prev;
        list->tail->next = NULL;
        printf("Element is deleted\n");
        return;
    }

    prev->next = temp->next;
    printf("Element is deleted\n");
}

void display(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;

    int c;
    do {
        printf("Enter 1 to Add an element\n");
        printf("Enter 2 to Add an element after an element\n");
        printf("Enter 3 to Delete an element \n");
        printf("Enter 4 to Display\n");
        printf("Enter 5 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        if (c == 1) {
            int n;
            printf("Enter a number: ");
            scanf("%d", &n);
            addNode(&list, n);
            printf("\n");
        }

        if (c == 2) {
            int p, n;
            printf("Enter the element after which the new element should be added: ");
            scanf("%d", &p);
            printf("Enter a number which is to be added: ");
            scanf("%d", &n);
            addNodeAfter(&list, p, n);
            printf("\n");
        }

        if (c == 3) {
            int n;
            printf("Enter an element to delete: ");
            scanf("%d", &n);
            deleteNode(&list, n);
            printf("\n");
        }

        if (c == 4) {
            display(&list);
            printf("\n");
        }
    } while (c != 5);
    printf("Quiting!!!\n");
}