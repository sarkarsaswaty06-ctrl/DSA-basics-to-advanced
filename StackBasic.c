```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

// Display the stack
void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");

    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }

    top++;
    stack[top] = value;

    printf("%d pushed into the stack.\n", value);
    display();
}

// Pop operation
void pop() {
    int value;

    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }

    value = stack[top];
    top--;

    printf("%d popped from the stack.\n", value);
    display();
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n===== STACK USING ARRAY =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter element to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
```
