```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

// Return precedence of an operator
int precedence(char op) {
    switch (op) {
        case '^':
            return 3;

        case '*':
        case '/':
        case '%':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

// Check whether character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '%' || ch == '^');
}

// Push a string onto the stack
void push(char str[]) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    strcpy(stack[++top], str);
}

// Pop a string from the stack
void pop(char str[]) {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    strcpy(str, stack[top--]);
}

// Display stack contents
void displayStack() {
    int i;

    printf("Stack: ");

    if (top == -1) {
        printf("EMPTY");
    } else {
        for (i = 0; i <= top; i++) {
            printf("[%s] ", stack[i]);
        }
    }

    printf("\n");
}

// Main function
int main() {
    char postfix[MAX];
    char operand1[MAX], operand2[MAX];
    char prefix[MAX];
    char temp[MAX];
    char ch;
    int i;

    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    // Remove newline
    postfix[strcspn(postfix, "\n")] = '\0';

    printf("\n%-10s %-25s\n", "Symbol", "Stack");
    printf("------------------------------------------\n");

    for (i = 0; postfix[i] != '\0'; i++) {

        ch = postfix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // If operand, push it onto the stack
        if (isalnum(ch)) {
            temp[0] = ch;
            temp[1] = '\0';

            push(temp);

            printf("%-10c ", ch);
            displayStack();
        }

        // If operator, pop two operands
        else if (isOperator(ch)) {

            // Check if two operands are available
            if (top < 1) {
                printf("Invalid postfix expression!\n");
                return 1;
            }

            pop(operand2);
            pop(operand1);

            // Create prefix expression
            sprintf(prefix, "%c%s%s", ch, operand1, operand2);

            push(prefix);

            printf("%-10c ", ch);
            displayStack();
        }

        else {
            printf("Invalid character: %c\n", ch);
            return 1;
        }
    }

    // There should be exactly one expression left
    if (top != 0) {
        printf("Invalid postfix expression!\n");
        return 1;
    }

    pop(prefix);

    printf("\nPrefix Expression: %s\n", prefix);

    return 0;
}
```
