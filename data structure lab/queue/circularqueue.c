#include<stdio.h>

#define SIZE 5

typedef struct{
	int data[SIZE];
	int front;
	int rear; 
	int count;
}CircularQueue;

void initQueue(CircularQueue *q){
	q->front = 0;
	q->rear = 0;
	q->count = 0;
}

int isFull(CircularQueue *q){
	return q->count == SIZE;
}

int isEmpty(CircularQueue *q){
	return q->count == 0;
}

void enqueue(CircularQueue *q, int data){
	if(isFull(q)){
		printf("Queue is full\n\n");
		return;
	}else{
		q->data[q->rear] = data;
		q->rear = (q->rear + 1)%SIZE;
		q->count++;
		printf("Element is added \n\n");
	}
}

int dequeue(CircularQueue *q){
	if(isEmpty(q)){
		printf("Queue is emptyt\n\n");
		return -1;
	}else{
		int data = q->data[q->front];
		q->front = (q->front + 1)%SIZE;
		q->count--;
		printf("Element dequeued \n\n");
	}
}

void dispaly(CircularQueue *q){
	if(isEmpty(q)){
		printf("Queue is empty\n\n");
		return;
	}
	int i;
	printf("Queue contents :-");
	for(int i = 0; i<q->count; i++){
		printf(" %d", q->data[(q->front+i)%SIZE]);
	}
	printf("\n\n");
}

int main(){
	CircularQueue q;
	initQueue(&q);
	
	int c;
	do{
		printf("Enter 1 for Enqueue \n");
		printf("Enter 2 for Dequeue \n");
		printf("Enter 3 for Display \n");
		printf("Enter 4 for Exit \n");
		printf("Enter ur choice : ");
		scanf("%d", &c);
		
		if(c==1){
			int data;
			printf("Enter a no :");
			scanf("%d", &data);
			enqueue(&q,data);
		}
		
		if(c==2){
			dequeue(&q);
		}
		
		if(c==3){
			dispaly(&q);
		}
	}while(c!=4);
    printf("Quitting...");
}