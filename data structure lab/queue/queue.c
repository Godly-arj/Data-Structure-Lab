#include<stdio.h>
int n=5; //Max size
int q[5];//Array
int f=-1,r=-1;

int isEmpty(){
    return f==-1;
}
int isFull(){
    return r == n-1;
}

void enqueue(int a){
    if(isFull()){
        printf("Queue is full\n\n");
        return;
    }else if(isEmpty()){
        f=0;
        q[++r] = a;
    }else{
        q[++r] = a;
    }
    printf("\n");
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n\n");
    }else{
        printf("Element is removed\n\n");
    }
    int a = q[f];
    if(f==r){
        f=-1;
        r=-1;
    }else{
        f++;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n\n");
    }else{
        printf("Queue Contents :");
        for(int i=f; i<=r; i++){
            printf("%d ", q[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void main(){
    int c;
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
            printf("Enter an element :");
            scanf("%d", &a);
            enqueue(a);
        }
        if(c==2){
            dequeue();
        }
        if(c==3){
            display();
        }
    }while (c!=4);
}