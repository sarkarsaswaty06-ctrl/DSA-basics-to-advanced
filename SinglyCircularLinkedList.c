
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
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
    newNode->next = NULL;

    return newNode;
}

// Display the circular linked list
void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d", temp->data);
        temp = temp->next;

        if (temp != head)
            printf(" -> ");

    } while (temp != head);

    printf(" -> HEAD\n");
}

// Insert a node at any position
void insertAtPosition(int data, int position) {
    struct Node *newNode;
    struct Node *temp;
    int i;

    newNode = createNode(data);

    // Case 1: Empty list
    if (head == NULL) {
        if (position != 1) {
            printf("Invalid position!\n");
            free(newNode);
            return;
        }

        head = newNode;
        newNode->next = head;

        printf("Node inserted successfully.\n");
        display();
        return;
    }

    // Case 2: Insert at beginning
    if (position == 1) {
        temp = head;

        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        newNode->next = head;
        head = newNode;
        temp->next = head;

        printf("Node inserted successfully.\n");
        display();
        return;
    }

    // Move to the node before the required position
    temp = head;

    for (i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // Check for invalid position
    if (i != position - 1) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
    display();
}

// Delete a node from any position
void deleteAtPosition(int position) {
    struct Node *temp;
    struct Node *deleteNode;
    int i;

    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    // Case 1: Only one node
    if (head->next == head) {
        if (position == 1) {
            free(head);
            head = NULL;

            printf("Node deleted successfully.\n");
            display();
        } else {
            printf("Invalid position!\n");
        }

        return;
    }

    // Case 2: Delete first node
    if (position == 1) {
        temp = head;

        // Find the last node
        while (temp->next != head) {
            temp = temp->next;
        }

        deleteNode = head;
        head = head->next;
        temp->next = head;

        free(deleteNode);

        printf("Node deleted successfully.\n");
        display();
        return;
    }

    // Move to the node before the required position
    temp = head;

    for (i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // Check for invalid position
    if (temp->next == head || i != position - 1) {
        printf("Invalid position!\n");
        return;
    }

    // Delete the node
    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Node deleted successfully.\n");
    display();
}

// Main function
int main() {
    int choice, data, position;

    while (1) {
        printf("\n===== SINGLY CIRCULAR LINKED LIST =====\n");
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

