#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node {
int data;
int priority;
struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data, int priority) {
struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
temp->data = data;
temp->priority = priority;
temp->next = NULL;
return temp;
}

// Function to insert an element into the priority queue
void insert(struct Node** head, int data, int priority) {
struct Node* temp = newNode(data, priority);

// If the queue is empty or the new element has higher priority

if (*head == NULL || priority < (*head)->priority) {
temp->next = *head;
*head = temp;
} else {
struct Node* current = *head;
// Find the position to insert the new element
while (current->next != NULL && current->next->priority <= priority) {
current = current->next;
}
temp->next = current->next;
current->next = temp;
}
}

// Function to delete the element with the highest priority
void deleteHighestPriority(struct Node** head) {
if (*head == NULL) {
printf("Priority queue is empty.\n");
} else {
struct Node* temp = *head;
*head = (*head)->next;
free(temp);
}
}

// Function to display the elements of the priority queue
void display(struct Node* head) {
if (head == NULL) {

printf("Priority queue is empty.\n");
} else {
printf("Priority Queue: ");
while (head != NULL) {
printf("(%d, %d) ", head->data, head->priority);
head = head->next;
}
printf("\n");
}
}

int main() {
struct Node* pq = NULL;

insert(&pq, 5, 2);
insert(&pq, 10, 1);
insert(&pq, 15, 3);
insert(&pq, 25, 2);

display(pq);

deleteHighestPriority(&pq);

display(pq);

return 0;
}
