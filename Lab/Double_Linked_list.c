#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* prev;
struct Node* next;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
return newNode;
}
void insertAtBeginning(struct Node** head, int data) {
struct Node* newNode = createNode(data);
newNode->next = *head;
if (*head != NULL)
(*head)->prev = newNode;
*head = newNode;
}
void insertAtEnd(struct Node** head, int data) {
struct Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode;
return;
}
struct Node* last = *head;
while (last->next != NULL)
last = last->next;
last->next = newNode;
newNode->prev = last;
}
void deleteNode(struct Node** head, int key) {
struct Node* temp = *head;
while (temp != NULL && temp->data != key)
temp = temp->next;
if (temp == NULL)
return;
if (temp->prev != NULL)
temp->prev->next = temp->next;
else
*head = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;
free(temp);
}
void traverseForward(struct Node* head) {
while (head != NULL) {
printf("%d ", head->data);
head = head->next;
}
printf("\n");
}
void traverseBackward(struct Node* head) {
struct Node* last = head;
while (last->next != NULL)
last = last->next;
while (last != NULL) {
printf("%d ", last->data);
last = last->prev;
}
printf("\n");
}
void printList(struct Node* head) {
printf("Doubly Linked List: ");
traverseForward(head);
}
int main() {
struct Node* head = NULL;
int choice, data;
// Predefined inputs
insertAtEnd(&head, 10);
insertAtEnd(&head, 20);
insertAtBeginning(&head, 5);
do {
printf("\n1. Insert at the Beginning\n2. Insert at the End\n3. Delete Node\n4. Print List\n5.Traverse Forward\n6. Traverse Backward\n0. Exit\n");

printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter data to insert at the beginning: ");
scanf("%d", &data);
insertAtBeginning(&head, data);
break;
case 2:
printf("Enter data to insert at the end: ");
scanf("%d", &data);
insertAtEnd(&head, data);
break;
case 3:
printf("Enter data to delete: ");
scanf("%d", &data);
deleteNode(&head, data);
break;
case 4:
printList(head);
break;
case 5:
printf("Doubly Linked List (Forward): ");
traverseForward(head);
break;
case 6:
printf("Doubly Linked List (Backward): ");
traverseBackward(head);
break;
case 0:
printf("Exiting program.\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 0);
return 0;
}
