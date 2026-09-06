
#include <stdio.h>
#include <stdlib.h>

// Structure of a stack node
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// Push operation
void push(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into the stack.\n", value);
}

// Pop operation
int pop() {
    struct Node *temp;
    int value;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }

    temp = top;
    value = temp->data;
    top = top->next;

    free(temp);

    return value;
}

// Display the stack
void display() {
    struct Node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Reverse the stack without creating a second linked list
void reverseStack() {
    struct Node *prev = NULL;
    struct Node *current = top;
    struct Node *next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move prev and current one step forward
        prev = current;
        current = next;
    }

    // Update top
    top = prev;
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n===== STACK USING LINKED LIST =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Reverse Stack\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                display();
                break;

            case 2:
                if (top != NULL) {
                    value = pop();
                    printf("%d popped from the stack.\n", value);
                    display();
                } else {
                    printf("Stack Underflow! Stack is empty.\n");
                }
                break;

            case 3:
                display();
                break;

            case 4:
                if (top == NULL) {
                    printf("Stack is empty. Cannot reverse.\n");
                } else {
                    reverseStack();
                    printf("Stack reversed successfully.\n");
                    display();
                }
                break;

            case 5:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

