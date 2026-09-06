
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Return precedence of operators */
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;

    return 0;
}

/* Push an element into stack */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }

    stack[++top] = value;
}

/* Pop an element from stack */
int pop()
{
    if (top == -1)
    {
        printf("Invalid Postfix Expression\n");
        exit(1);
    }

    return stack[top--];
}

/* Display stack */
void displayStack()
{
    int i;

    printf("Stack: ");

    if (top == -1)
    {
        printf("Empty");
    }
    else
    {
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }

    printf("\n");
}

int main()
{
    char postfix[MAX];
    int i;
    int operand1, operand2, result;
    char ch;

    printf("Enter postfix expression: ");
    fgets(postfix, MAX, stdin);

    printf("\n--- Evaluation Steps ---\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        /* Ignore spaces */
        if (ch == ' ' || ch == '\n')
            continue;

        /* If operand, push it */
        if (isdigit(ch))
        {
            push(ch - '0');

            printf("Read %c -> ", ch);
            displayStack();
        }

        /* If operator, perform operation */
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '%' || ch == '^')
        {
            operand2 = pop();
            operand1 = pop();

            switch (ch)
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    if (operand2 == 0)
                    {
                        printf("Error: Division by zero\n");
                        return 1;
                    }
                    result = operand1 / operand2;
                    break;

                case '%':
                    if (operand2 == 0)
                    {
                        printf("Error: Modulo by zero\n");
                        return 1;
                    }
                    result = operand1 % operand2;
                    break;

                case '^':
                    result = (int)pow(operand1, operand2);
                    break;
            }

            push(result);

            printf("Apply %c -> %d %c %d = %d -> ",
                   ch, operand1, ch, operand2, result);

            displayStack();
        }

        else
        {
            printf("Invalid character: %c\n", ch);
            return 1;
        }
    }

    /* Final stack should contain exactly one value */
    if (top != 0)
    {
        printf("\nInvalid Postfix Expression\n");
        return 1;
    }

    printf("\nFinal Result = %d\n", pop());

    return 0;
}

