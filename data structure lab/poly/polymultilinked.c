#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int c, int p){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> coeff = c;
    newNode -> pow = p;
    newNode -> next = NULL;
    return newNode;
}

struct Node* multiplyPoly(struct Node* head1, struct Node* head2){
    struct Node* result = NULL;
    struct Node* prev = NULL;

    struct Node* cur1 = head1;
    while(cur1 != NULL){
        struct Node* cur2 = head2;
        while(cur2 != NULL){
            int coeff = cur1->coeff * cur2->coeff;
            int pow = cur1->pow + cur2->pow;

            struct Node* newNode = createNode(coeff, pow);

            if(result == NULL){
                result = newNode;
                prev = newNode;
            }else{
                prev->next = newNode;
                prev = newNode;
            }

            cur2 = cur2->next;
        }
        cur1 = cur1->next;
    }

    struct Node* temp = result;
    while(temp != NULL){
        struct Node* next = temp->next;
        while(next != NULL){
            if(temp->pow == next->pow){
                temp->coeff += next->coeff;
                temp->next = next->next;
                free(next);
                next = temp->next;
            }else{
                next = next->next;
            }
        }
        temp = temp->next;
    }

    return result;
}

void display(struct Node* head){
    struct Node* cur = head;

    while(cur != NULL){
        printf("%dx^%d ", cur->coeff, cur->pow);
        cur = cur->next;

        if(cur != NULL){
            printf("+ ");
        }
    }

    printf("\n");
}

struct Node* getPoly(){
    int n;
    printf("Enter the no. of terms in the Polynomial: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* prev = NULL;

    for(int i = 0; i < n; i++){
        int coeff, pow;
        printf("\nEnter the coefficient :");
        scanf("%d", &coeff);
        printf("Enter the exponent :");
        scanf("%d", &pow);

        struct Node* newNode = createNode(coeff, pow);

        if(head == NULL){
            head = newNode;
        }else{
            prev->next = newNode;
        }
        prev = newNode;
    }
    return head;
}

void main(){
    printf("Enter the 1st Polynomial  \n");
    struct Node* head1 = getPoly();

    display(head1);

    printf("\nEnter the 2nd Polynomial  \n");
    struct Node* head2 = getPoly();

    display(head2);

    struct Node* head = multiplyPoly(head1, head2);

    printf("\nResultant Polynomial :\n");
    display(head);
}