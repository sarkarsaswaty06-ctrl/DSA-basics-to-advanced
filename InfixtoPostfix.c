
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
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

// Push an operator onto the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    stack[++top] = ch;
}

// Pop an operator from the stack
char pop() {
    if (top == -1)
        return '\0';

    return stack[top--];
}

// Display the current stack
void displayStack() {
    int i;

    printf("Stack: ");

    if (top == -1) {
        printf("EMPTY");
    } else {
        for (i = 0; i <= top; i++) {
            printf("%c ", stack[i]);
        }
    }

    printf("\n");
}

// Check whether character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '%' || ch == '^');
}

// Main function
int main() {
    char infix[MAX];
    char postfix[MAX];
    char ch;
    int i, k = 0;

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline
    infix[strcspn(infix, "\n")] = '\0';

    printf("\n%-10s %-20s %-20s\n",
           "Symbol", "Postfix", "Stack");
    printf("--------------------------------------------------\n");

    for (i = 0; infix[i] != '\0'; i++) {

        ch = infix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;

            printf("%-10c %-20s ", ch, postfix);
            displayStack();
        }

        // If opening parenthesis, push onto stack
        else if (ch == '(') {
            push(ch);

            printf("%-10c %-20s ", ch, postfix);
            displayStack();
        }

        // If closing parenthesis
        else if (ch == ')') {

            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }

            if (top != -1 && stack[top] == '(')
                pop();

            printf("%-10c %-20s ", ch, postfix);
            displayStack();
        }

        // If operator
        else if (isOperator(ch)) {

            /*
             * Pop operators having higher or equal precedence.
             *
             * Exception:
             * '^' is right associative, so operators with
             * equal precedence are not popped.
             */
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) &&
                    ch != '^'))) {

                postfix[k++] = pop();
            }

            push(ch);

            printf("%-10c %-20s ", ch, postfix);
            displayStack();
        }

        else {
            printf("Invalid character: %c\n", ch);
            return 1;
        }
    }

    // Pop remaining operators
    while (top != -1) {

        if (stack[top] == '(') {
            printf("Error: Unbalanced parentheses.\n");
            return 1;
        }

        postfix[k++] = pop();

        printf("%-10s %-20s ", "POP", postfix);
        displayStack();
    }

    postfix[k] = '\0';

    printf("\nPostfix Expression: %s\n", postfix);

    return 0;
}

