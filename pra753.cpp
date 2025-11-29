#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function to add element to the queue
void enqueue() {
    int value;
    if(rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue more elements.\n");
    } else {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        if(front == -1) front = 0;  // First element
        rear++;
        queue[rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove element from the queue
void dequeue() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow! No element to dequeue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
    }
}

// Function to display the queue
void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are:\n");
        for(int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n*** Queue Operations ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: 
                printf("Exiting program.\n");
                system("pause");
                exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
