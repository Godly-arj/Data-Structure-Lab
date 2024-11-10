#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

struct BinaryTree {
    int data[MAX_SIZE]; 
    int size;
};

struct BinaryTree* createBinaryTree() {
    struct BinaryTree* tree = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    tree->size = 0;
    return tree;
}


void insert(struct BinaryTree* tree, int data) {
    if (tree->size >= MAX_SIZE) {
        printf("Tree is full, cannot insert %d\n", data);
        return;
    }
    tree->data[tree->size++] = data; // Insert at the end and increment size
}

int findIndex(struct BinaryTree* tree, int data) {
    for (int i = 0; i < tree->size; i++) {
        if (tree->data[i] == data) {
            return i;
        }
    }
    return -1;
}

void deleteNode(struct BinaryTree* tree, int data) {
    int index = findIndex(tree, data);
    if (index == -1) {
        printf("Node %d not found\n", data);
        return;
    }
    tree->data[index] = tree->data[--tree->size];
}

void inorder(struct BinaryTree* tree, int index) {
    if (index < tree->size) {
        inorder(tree, 2 * index + 1); 
        printf("%d ", tree->data[index]); 
        inorder(tree, 2 * index + 2); 
    }
}

void preorder(struct BinaryTree* tree, int index) {
    if (index < tree->size) {
        printf("%d ", tree->data[index]); 
        preorder(tree, 2 * index + 1); 
        preorder(tree, 2 * index + 2); 
    }
}

void postorder(struct BinaryTree* tree, int index) {
    if (index < tree->size) {
        postorder(tree, 2 * index + 1); 
        postorder(tree, 2 * index + 2); 
        printf("%d ", tree->data[index]); 
    }
}

int main() {
    struct BinaryTree* tree = createBinaryTree();

    int r;
    printf("Enter a root node: ");
    scanf("%d", &r);
    insert(tree, r);
    printf("\n");

    int c;
    do {
        printf("Enter '1' for Insertion\n");
        printf("Enter '2' for Deletion\n");
        printf("Enter '3' for Inorder traversal\n");
        printf("Enter '4' for Preorder traversal\n");
        printf("Enter '5' for Postorder traversal\n");
        printf("Enter '6' to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        if (c == 1) {
            int a;
            printf("Enter an element: ");
            scanf("%d", &a);
            insert(tree, a);
            printf("\n");
        }

        if (c == 2) {
            int a;
            printf("Enter an element: ");
            scanf("%d", &a);
            deleteNode(tree, a);
            printf("\n");
        }

        if (c == 3) {
            inorder(tree, 0);
            printf("\n\n");
        }

        if (c == 4) {
            preorder(tree, 0);
            printf("\n\n");
        }

        if (c == 5) {
            postorder(tree, 0);
            printf("\n\n");
        }
    } while (c != 6);
    
    printf("Quitting.....\n");
    free(tree);
}