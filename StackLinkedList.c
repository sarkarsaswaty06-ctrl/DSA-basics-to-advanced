
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a stack node
struct Node {
    char data;
    struct Node *next;
};

struct Node *top = NULL;

// Push a character into the stack
void push(char ch) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow!\n");
        exit(1);
    }

    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}

// Pop a character from the stack
char pop() {
    struct Node *temp;
    char ch;

    if (top == NULL) {
        printf("Stack Underflow!\n");
        exit(1);
    }

    temp = top;
    ch = temp->data;
    top = top->next;

    free(temp);

    return ch;
}

// Main function
int main() {
    char str[100];
    int i, length;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);

    // Push every character into the stack
    for (i = 0; i < length; i++) {
        push(str[i]);
    }

    // Pop characters to get the reversed string
    printf("Reversed string: ");

    for (i = 0; i < length; i++) {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}

