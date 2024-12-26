// Implement priority queue

#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <process.h>

struct node {
    int priority;
    int val;
    struct node *link;
};

typedef struct node *NODE;

NODE insert (NODE front) {
    NODE temp, q;
    int added_item, item_priority;

    temp = (NODE)malloc(sizeof(struct node));
    printf("\nInput the item value to be added in the queue: ");
    scanf("%d", &added_item);
    printf("\nEnter its priority: ");
    scanf("%d", &item_priority);

    temp->val = added_item;
    temp->priority = item_priority;

    // set temp as front when queue is empty or temp priority < front
    if (front == NULL || item_priority < front->priority) {
        temp->link = front;
        front = temp;
    }
    else {
        q = front;
        // loop queue to find next q is not NULL and next q priority < temp
        while (q->link != NULL && q->link->priority <= item_priority) {
            q = q->link;
        }
        // insert q
        temp->link = q->link;
        q->link = temp;
    }
    return front;
}

NODE del(NODE front) {
    NODE temp;
    // if front is null, it means queue is empty
    if (front == NULL) {
        printf("Queue is underflow.\n");
    }
    else {
        // let temp point to front
        temp = front;
        // display the front value
        printf("\nDeleted item is %d.\n", temp->val);
        // set 2nd node as new front
        front = front->link;
        // free original front node
        free(temp);
    }
    return front;
}

void display(NODE front) {
    NODE ptr;
    ptr = front;
    if (front == NULL) {
        printf("Queue is empty.\n");
    }
    else {
        printf("\nQueue is: \n");
        printf("\nPriority item\n");
        while (ptr != NULL) {
            printf("%5d %5d\n", ptr->priority, ptr->val);
            ptr = ptr->link;
        }
    }
}

void main() {
    int choice;
    NODE front = NULL;
    while (1) {
        system("cls");
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                front = insert(front);
                break;
            case 2:
                front = del(front);
                getch();
                break;
            case 3:
                display(front);
                getch();
                break;
            case 4:
                exit(1);
            default:
                printf("\nWrong choice.\n");
        }
    }
}
