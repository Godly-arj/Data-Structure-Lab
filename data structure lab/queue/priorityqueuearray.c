#include<stdio.h>
int size,front,rear;


struct PQ{
    int item,priority;
}A[20];

void display(){
    int i;
    if(front==-1){
        printf("\nqueue is empty\n");
    }else {
        for(i=front;i<=rear;i++)
        printf("%d\t", A[i].item);
    }
}

void enqueue(int ITEM, int priority){
    int i,loc;
        if(front==0&&rear==size-1){
        printf("\nQueue is full\n");
    }else if(front==-1){
        front=rear=0;
        A[rear].item=ITEM;
        A[rear].priority=priority;
    }else{
        if(rear==size-1){
            for(i=front;i<=rear;i++)
            A[i-1]=A[i];
            front--;
            rear--;
        }
        for(i=rear;i>front;i--){ 
            if(A[i].priority<priority){
                break;
            }
        }
        loc=i+1;
        for(i=rear;i>=loc;i--){
            A[i+1]=A[i];
        }
        A[loc].item=ITEM;
        A[loc].priority=priority;
        rear++;
    }
}


void dequeue(){
    if(front==-1){
        printf("Queue is empty\n");
    }else if(front==rear){
        printf("Deleted item is %d\t", A[front].item);
        front=-1;
        rear=-1;
    }else{
        printf("Deleted item is %d\t", A[front].item);
        front++;
    }
}


void main(){
    int opt,item,prio;
    front=rear=-1;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    do{
        printf("\nEnter the options given below:\n");
        printf("\n1. Enqueue \n2. Dequeue \n\n3. Display \n4. Exit");
        printf("Enter ur choice :");
        scanf("%d", &opt);
    
        switch(opt){
            case 1: printf("Enter the item and priority :\t");
                scanf("%d%d", &item, &prio);
                enqueue(item,prio);
                break;
            case 2: 
                dequeue();break;
            case 3: 
                display(); break;
            case 4: 
                break;
            default: 
                printf("Enter a valid Option");
        }
    }while(opt!= 4);
}