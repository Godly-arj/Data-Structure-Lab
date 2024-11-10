#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 50

char stack[max -1];
int Stack[max -1];
int top=-1;

void Push(int n){ 
    if(top==max -1){
        printf("\nOverflow");
    }else{
        top++;
        Stack[top]=n;
    }
}

int Pop(){ 
    int temp;
    if(top==-1){
        printf("\nUnderflow");
    }else{
        temp=Stack[top];
        top--;
        return temp;
    }
}

int priority(char ch){
    if(ch == '^'){
        return 3;
    }else if(ch == '/' || ch=='*'){
        return 2;
    }else if(ch == '+' || ch == '-'){
        return 1;
    }else{
        return -1;
    }
}

void main(){ 
    int i,len,k=0,p=0;
    char exp[max],temp,temp2,num[5];{
        top=-1;
        printf("\nEnter the Postfix expression: ");
        scanf(" %[^\n]",exp);
        for(i=0;exp[i]!='\0';i++){
            if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-'||exp[i]=='^'){ 
                temp=Pop();
                temp2=Pop();
                switch(exp[i]){
                    case '*':
                        Push(temp2*temp);
                        break;
                    case '/':
                        Push(temp2/temp);
                        break;
                    case '+':
                        Push(temp2+temp);
                        break;
                    case '^':
                        Push(temp2^temp);
                        break;
                    case '-':
                        Push(temp2-temp);
                        break;
                }
                i++;
            }else if(exp[i]==' '){
                num[k]='\0';
                temp=atoi(num);
                Push(temp);
                k=0;
            }else{
                num[k++]=exp[i];
            }
        }
        printf("\nResult: %d",Pop());
    }
}