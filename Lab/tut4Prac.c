#include<stdio.h>
#define MAX 7

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is Full\n");
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = element;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("The queue is Empty\n");
    } else if (front == rear) {
        printf("The dequeued element is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("The dequeued element is %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("The queue is Empty\n");
    } else {
        printf("Elements in the queue are: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    int choice = 1, x;

    while (choice < 4 && choice != 0) {
        printf("\nPress 1: Insert an element");
        printf("\nPress 2: Delete an element");
        printf("\nPress 3: Display the elements");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element which is to be inserted\n");
                scanf("%d", &x);  // Removed extra space
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
