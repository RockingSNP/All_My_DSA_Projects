
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_SIZE 100


char stack[MAX_SIZE];
int top = -1;


void push(char item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}


char pop() {
    if (top == -1) {
        printf("Invalid Expresion\n");
        return '\0';
    }
    char item = stack[top];
    top--;
    return item;
}


bool isOpeningParenthesis(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}


bool isClosingParenthesis(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}


bool parenthesesMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isValidExpression(const char *expression) {
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        char ch = expression[i];
        
        if (isOpeningParenthesis(ch)) {
            push(ch);
        } else if (isClosingParenthesis(ch)) {
            if (top == -1 || !parenthesesMatch(stack[top], ch)) {
                return false;
            }
            pop();
        }
    }
    
    return top == -1;  
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an infix expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strlen(expression) - 1] = '\0'; 

    if (isValidExpression(expression)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is not valid.\n");
    }

    return 0;
}
