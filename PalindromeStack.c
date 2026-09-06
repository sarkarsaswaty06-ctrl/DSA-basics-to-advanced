
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        printf("Stack Underflow!\n");
        exit(1);
    }

    return stack[top--];
}

// Main function
int main() {
    char str[MAX];
    int i, length;
    int palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);

    // Convert to lowercase and push each character
    for (i = 0; i < length; i++) {
        push(tolower(str[i]));
    }

    // Compare original string with popped characters
    for (i = 0; i < length; i++) {
        if (tolower(str[i]) != pop()) {
            palindrome = 0;
            break;
        }
    }

    if (palindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}

