
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Display the linked list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// a) Insert a node at the beginning
void insertBeginning(int data) {
    struct Node *newNode = createNode(data);

    newNode->next = head;
    head = newNode;

    printf("Node inserted at the beginning.\n");
}

// b) Insert a node at the middle
void insertMiddle(int data) {
    struct Node *newNode;
    struct Node *temp;
    int count = 0, position, i;

    if (head == NULL) {
        printf("List is empty. Inserting as the first node.\n");
        insertBeginning(data);
        return;
    }

    // Count the number of nodes
    temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Middle position
    position = count / 2;

    newNode = createNode(data);
    temp = head;

    // Move to the node before the middle
    for (i = 1; i < position; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted at the middle.\n");
}

// c) Insert a node at the end
void insertEnd(int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        printf("Node inserted at the end.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted at the end.\n");
}

// d) Delete the first node
void deleteBeginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("First node deleted.\n");
}

// e) Delete a node from the middle
void deleteMiddle() {
    struct Node *temp;
    struct Node *deleteNode;
    int count = 0, position, i;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // If there is only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Only node deleted.\n");
        return;
    }

    // Count the number of nodes
    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Middle position
    position = count / 2;

    temp = head;

    // Move to the node before the middle
    for (i = 1; i < position; i++) {
        temp = temp->next;
    }

    deleteNode = temp->next;
    temp->next = deleteNode->next;

    free(deleteNode);

    printf("Middle node deleted.\n");
}

// f) Delete the last node
void deleteEnd() {
    struct Node *temp;
    struct Node *deleteNode;

    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    // If there is only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = head;

    // Move to the second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    deleteNode = temp->next;
    temp->next = NULL;

    free(deleteNode);

    printf("Last node deleted.\n");
}

// Main function
int main() {
    int choice, data;

    while (1) {
        printf("\n===== SINGLY LINKED LIST =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle\n");
        printf("3. Insert at End\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Middle Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Display List\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertBeginning(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertMiddle(data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteMiddle();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

