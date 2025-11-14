#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Detect cycle using Floyd's Algorithm
int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // move 1 step
        fast = fast->next->next;   // move 2 steps

        if (slow == fast) {
            return 1; // cycle detected
        }
    }
    return 0; // no cycle
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    // Creating a cycle manually (like a circular linked list)
    head->next->next->next->next = head;

    if (detectCycle(head))
        printf("Cycle detected!\n");
    else
        printf("No cycle found.\n");

    return 0;
}







// =====================================================================


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

// Insert at front
void insertFront(int val) {
    struct Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    head = newNode;
    temp->next = head;
}

// Delete from front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // Only one node
        head = NULL;
        free(temp);
        return;
    }
    struct Node* last = head;
    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if (head->next == head) { // Only one node
        head = NULL;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    insertEnd(10);
    insertEnd(20);
    insertFront(5);
    display();   // 5 10 20

    deleteFront();
    display();   // 10 20

    deleteEnd();
    display();   // 10

    return 0;
}


// ==========================================================================================



