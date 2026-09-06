
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push a character into the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    stack[++top] = ch;
}

// Pop a character from the stack
char pop() {
    if (top == -1) {
        return '\0';
    }

    return stack[top--];
}

// Check whether brackets match
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

// Main function
int main() {
    char expression[MAX];
    char ch, popped;
    int i, balanced = 1;

    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Check each character
    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];

        // If opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }

        // If closing bracket, check the stack
        else if (ch == ')' || ch == '}' || ch == ']') {

            popped = pop();

            if (!isMatchingPair(popped, ch)) {
                balanced = 0;
                break;
            }
        }
    }

    // If stack is not empty, brackets are unbalanced
    if (top != -1) {
        balanced = 0;
    }

    if (balanced)
        printf("The expression is balanced.\n");
    else
        printf("The expression is not balanced.\n");

    return 0;
}

