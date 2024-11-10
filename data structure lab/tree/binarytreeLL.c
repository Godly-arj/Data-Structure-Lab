#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct Node* root = NULL;

    int r;
    printf("Enter a root node : ");
    scanf("%d", &r);
    root = insert(root, r);
    printf("\n");

    int c;
    do{
        printf("Enter '1' for Insertion \n");
        printf("Enter '2' for Deletion\n");
        printf("Enter '3' for Inorder traversal\n");
        printf("Enter '4' for Pre order traversal\n");
        printf("Enter '5' for Post order traversal\n");
        printf("Enter '6' to Exit\n");
        printf("Enter ur choice : ");
        scanf("%d", &c);

        if(c == 1){
            int a;
            printf("Enter an element : ");
            scanf("%d", &a);
            insert(root, a);
            printf("\n");
        }

        if(c == 2){
           int a ;
           printf("Enter an element : ");
           scanf("%d", &a);
           deleteNode(root, a);
           printf("\n");
        } 

        if(c == 3){
            inorder(root);
            printf("\n\n");
        }

        if(c == 4){
            preorder(root);
            printf("\n\n");
        }

        if(c == 5){
            postorder(root);
            printf("\n\n");
        }
    }while(c!=6);
    printf("Quiting.....");
}