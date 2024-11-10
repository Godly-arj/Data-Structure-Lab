#include <stdio.h>

int t=-1;
int n=5;
int s[5];

void push(int a,int n){
     if (t == n-1) {
        printf("Stack is full\n");
    } else {
        t++;
        s[t] = a;
        printf("Element is pushed \n");
    }
}

void pop(){
    if (t == -1) {
        printf("Stack is empty\n");
    } else {
        int a = s[t];
        t--;
        printf("Element is popped\n");
    }
}

void display(){
    if (t == -1) {
        printf("Stack is empty.\n");
    } else {
        for(int i=t; i>=0; i--){
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main() {
 int c;
 do{
  printf("Enter '1' for push \n");
  printf("Enter '2' for pop\n");
  printf("Enter '3' for display \n");
  printf("Enter '4' to exit \n");
  printf("Enter ur choice :");
  scanf("%d", &c);
 
  if(c == 1){
      int a;
      printf("Enter an element :");
      scanf("%d", &a);
      push(a, n);
  }
  
  if(c == 2){
      pop();
  } 
  
  if(c == 3){
      display();
  }
 }while(c!=4);
}