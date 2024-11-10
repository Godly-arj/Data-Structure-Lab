#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int top=-1;
int s[MAX];

int isEmpty(){
    return top == -1;
}

void push(char symbol){
    if(top >= MAX-1){
        printf("Stack Overflow \n");
        return;
    }
    s[++top] = symbol;
}

char pop() {
  if (isEmpty()) {
    printf("Stack Underflow!\n");
    exit(1);
  }
  return s[top--];
}

int precedence(char symbol){
    switch (symbol)
    {
    case '(' :
        return 0;
    case '+' :
    case '_' :
        return 1;
    case '*' :
    case '/' :
    case '%' :
        return 2;
    case '^' :
        return 3;
    default:
        return -1; //Returns a -ve value for non-operators
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    char symbol, next;
    int p = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (symbol == ' ' || symbol == '\t') {
        continue;
        }

        switch (symbol) {
        case '(':
            push(symbol);
            break;

        case ')':
            while ((next = pop()) != '(') {
                postfix[p++] = next;
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '^':
        while (!isEmpty() && precedence(s[top]) >= precedence(symbol)) {
            postfix[p++] = pop();
        }
        push(symbol);
        break;

        default:
        postfix[p++] = symbol;
    }
  }

  while (!isEmpty()) {
    postfix[p++] = pop();
  }
  postfix[p] = '\0';
}
void main(){
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // TO REMOVE NEWLINE CHARACTER FROM THE INPUT STRING
    size_t len = strlen(infix);
    if(len > 0 && infix[len - 1] == '\n'){
        infix[len - 1] = '\0';
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression is: %s\n", postfix);
}