
#include <stdio.h>
#include <stdlib.h>

// Structure of a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Display the list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }

    printf("\n");
}

// Insert a node at any position
void insertAtPosition(int data, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    newNode = createNode(data);

    // Insertion at beginning
    if (position == 1) {
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;

        printf("Node inserted successfully.\n");
        display();
        return;
    }

    // If list is empty and position is not 1
    if (head == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    temp = head;

    // Move to the node before the required position
    for (i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // Position is invalid
    if (i != position - 1) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    // Insert the new node
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Node inserted successfully.\n");
    display();
}

// Delete a node from any position
void deleteAtPosition(int position) {
    struct Node *temp;
    int i;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    temp = head;

    // Move to the node at the required position
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    // Position is invalid
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // If deleting the first node
    if (temp->prev == NULL) {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Node deleted successfully.\n");
    display();
}

// Main function
int main() {
    int choice, data, position;

    while (1) {
        printf("\n===== DOUBLY LINKED LIST =====\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                if (position <= 0) {
                    printf("Invalid position!\n");
                } else {
                    insertAtPosition(data, position);
                }
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);

                if (position <= 0) {
                    printf("Invalid position!\n");
                } else {
                    deleteAtPosition(position);
                }
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

