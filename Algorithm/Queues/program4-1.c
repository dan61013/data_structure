// Using Array
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

#define MAX 50

int queue_arr[MAX];
int rear = -1;
int front = -1;

void insert() {
    int add_item;
    if (rear == MAX - 1) {
        // if rear = MAX-1, means this array is full(the maximum value is (n-1)).
        printf("\nQueue Overflow\n");
        getch();
        return;
    }
    else {
        if (front == -1) {
            // set the front = 0, since array started position is from 0.
            front = 0;
        }
        printf("\nInput the element for adding in queue: ");
        // get the add item
        scanf("%d", &add_item);
        // the rear + 1
        rear += 1;
        queue_arr[rear] = add_item;
    }
}

void del() {
    // front == -1, means this array is empty.
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow\n");
        return;
    }
    else {
        printf("\nElement deleted from queue is : %d\n", queue_arr[front]);
        front += 1;
    }
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("\nQueue is empty.\n");
        return;
    }
    else {
        printf("\nQueue is :\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue_arr[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice;
    while (1) {
        system("cls");
        printf("\n1. Insert\n");
        printf("\n2. Delete\n");
        printf("\n3. Display\n");
        printf("\n4. Quit\n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                del();
                getch();
                break;
            case 3:
                display();
                getch();
                break;
            case 4:
                exit(1);
            default:
                printf("\n Wrong choice\n");
                getch();
        }
    }
}