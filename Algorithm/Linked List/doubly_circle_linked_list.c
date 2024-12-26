#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <malloc.h>

struct node {
    int val;
    struct node *prev;
    struct node *next;
}*start;

typedef struct node *NODE;

void added_node(int num) {
    NODE temp, q;
    int i;
    temp = (NODE)malloc(sizeof(struct node));
    temp->val = num;

    if (start == NULL) {
        temp->prev = temp;
        temp->next = temp;
        start = temp;
    }
    if (start->next == start) {
        temp->prev = start;
        temp->next = start;
        start->next = temp;
        start->prev = temp;
    }
    else {
        temp->prev = start->prev;
        temp->next = start;
        start->prev->next = temp;
        start->prev = temp;
    }
}

void deleted_node(int num) {
    // Linked list is empty
    if (start == NULL) {
        printf("\nLinked List is empty.\n");
    }
    
    NODE temp, q;
    temp = (NODE)malloc(sizeof(struct node));
    q = start;
    // if start == num
    if (q->val == num) {
        printf("\nDeleted %d from linked list.\n", q->val);
        temp = q;
        q->prev->next = q->next;
        q->next->prev = q->prev;
        start = q->next;
        free(temp);
    }
    else {
        // check each node from 2nd node
        q = q->next;
        while (q != start) {
            if (q->val == num) {
                printf("\nDeleted %d from linked list.\n", q->val);
                temp = q;
                q->prev->next = q->next;
                q->next->prev = q->prev;
                free(temp);
                return;
            }
            q = q->next;
        }
        printf("Can find %d in Linked List.\n", num);
    }
}

void display() {
    NODE q;
    q = start;
    if (q == NULL) {
        printf("\nLinked List is empty.\n");
    }
    if (q->next == start && q->prev == start) {
        printf("%d", start->val);
    }
    else {
        while (q->next != start) {
            printf("%d ", q->val);
            q = q->next;
        }
        printf("%d", q->val);
    }
}

void main() {
    int choice, num;
    start = NULL;

    while (1) {
        system("cls");
        printf("\n1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the node value you want to add: ");
                scanf("%d", &num);
                added_node(num);
                break;
            case 2:
                printf("\nEnter the node value you want to delete: ");
                scanf("%d", &num);
                deleted_node(num);
                getch();
                break;
            case 3:
                display();
                getch();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong choice.\n");
                getch();
        }
    }
}
