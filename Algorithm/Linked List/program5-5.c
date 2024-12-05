#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct queue {
    int value;
    struct queue *next;
};
typedef struct queue *NODE;

NODE push(NODE rear) {
    NODE NewNode;
    NewNode = (NODE)malloc(sizeof(struct queue));
    printf("\nEnter the no to be pushed = ");
    scanf("%d", &NewNode->value);
    NewNode->next = NULL;
    if (rear != NULL) {
        rear->next = NewNode;
    }
    rear = NewNode;
    return (rear);
}

// NODE f=front, r=rear
NODE pop(NODE f, NODE r) {
    if (f == NULL) {
        printf("\nThe Queue is empty.");
    }
    else {
        printf("\nThe popped element is = %d", f->value);
        if (f != r) {
            f = f->next;
        }
        else {
            f = NULL;
        }
    }
    return (f);
}

void traversal(NODE fr, NODE re) {
    if (fr == NULL) {
        printf("\nThe Queue is empty.");
    }
    else {
        printf("\nThe element(s) is/are = \n");
        while (fr != re) {
            printf("%d\n", fr->value);
            fr = fr->next;
        };
        printf("%d", fr->value);
    }
}

void main() {
    int choice;
    char option;
    NODE front, rear;
    front = rear = NULL;
    do {
        system("cls");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traversal");
        printf("\n4. Exit");
        printf("\n\nEnter your choice = ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                rear = push(rear);
                if (front == NULL) {
                    front = rear;
                }
                break;
            case 2:
                front = pop(front, rear);
                if (front == NULL) {
                    rear = NULL;
                }
                break;
            case 3:
                traversal(front, rear);
                break;
            case 4:
                exit(1);
            default:
                printf("\nWrong choice");
        }
        printf("\n\n Press (Y/y) to continue = ");
        fflush(stdin);
        scanf("%c", &option);
    }while ((option == 'Y') || (option == 'y'));
}
