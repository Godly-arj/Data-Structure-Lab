#include <stdio.h>
#include <stdlib.h>

struct Node {
    int priority;
    int data;
    struct Node *next;
};

struct Node *front;

void initializeQueue() {
    front = NULL;
}

int isEmpty() {
    if (front == NULL) {
        return 1;
    }

    return 0;
}

void insert(int element, int priority) {
    struct Node *temp, *p;

    temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Queue\n");
        return;
    }

    temp->data = element;
    temp->priority = priority;

    if (isEmpty() || priority < front->priority) {
        temp->next = front;
        front = temp;
    }

    else {
        p = front;

        while (p->next != NULL && p->next->priority <= priority) {
            p = p->next;
        }

        temp->next = p->next;
        p->next = temp;
    }
}

void display() {
    if (isEmpty()) {
        printf("Empty Queue!\n");
        return;
    }

    else {
        struct Node *ptr = front;

        printf("Queue is: \n");
        printf("Priority     Data\n");

        while (ptr != NULL) {
            printf("%d             %d\n", ptr->priority, ptr->data);
            ptr = ptr->next;
        }
    }
}

void delete() {
    struct Node *temp;
    int data;

    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    else {
        temp = front;
        data = temp->data;
        front = front->next;
        free(temp);
    }
    printf("Element removed");
}

int main() {
    int n, data, prior;

    int c;
    initializeQueue();
    do
    {
        printf("Enter 1 for Enqueue\n");
        printf("Enter 2 for Dequeue\n");
        printf("Enter 3 for Display\n");
        printf("Enter 4 for exit\n");
        printf("Enter ur choice :");
        scanf("%d", &c);
        if(c==1){
            int a;
            printf("Enter the data : ");
            scanf("%d", &data);
            printf("Enter the priority :");
            scanf("%d", &prior);
            insert(data, prior);
            printf("\n");
        }
        if(c==2){
            delete();
            printf("\n");
        }
        if(c==3){
            display();
            printf("\n");
        }
    }while (c!=4);
    printf("Quitting...");
}