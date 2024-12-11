// Queue using two Stacks
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct stack {
    int value;
    struct stack *next;
};
typedef struct stack *NODE;

NODE push(NODE top) {
    // set NewNode next == top(since NewNode will be top node)
    // if top == NULL, there is one element in this stack(NewNode)
    NODE NewNode;
    NewNode = (NODE)malloc(sizeof(struct stack));
    NewNode->next = top;

    printf("\nEnter the no: to be pushed = ");
    scanf("%d", &NewNode->value);
    // set NewNode be top node
    top = NewNode;
    return (top);
}

NODE pop(NODE top1) {
    if (top1 == NULL) {
        printf("\nThe Queue is empty.");
        return (top1);
    }

    if (top1->next == NULL) {
        printf("\nThe popped element is = %d", top1->value);
        free(top1);
        top1 = NULL;
        return (top1);
    }

    NODE NewNode, top2, temp;
    top2 = NULL;
    while (top1 != NULL) {
        temp = top1;
        NewNode = (NODE)malloc(sizeof(struct stack));
        NewNode->next = top2;
        NewNode->value = top1->value;
        top2 = NewNode;
        top1 = top1->next;
        free(temp);
    };
    
    printf("\nThe popped element is = %d", top2->value);
    top2 = top2->next;

    top1 = NULL;
    while (top2 != NULL) {
        temp = top2;
        NewNode = (NODE)malloc(sizeof(struct stack));
        NewNode->next = top1;
        NewNode->value = top2->value;
        top1 = NewNode;
        top2 = top2->next;
        free(temp);
    };
    return (top1);
}

void traverse(NODE top) {
    if(top == NULL) {
        printf("\nThe Queue is empty.");
        return;
    }
    printf("\nThe element(s) in the Queue is/are =");
    do {
        printf(" %d", top->value);
        top = top->next;
    }while (top != NULL);
    return;
}

void main() {
    int choice;
    char ch;
    NODE top;
    top = NULL;
    do {
        system("cls");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                traverse(top);
                break;
            case 4:
                exit(1);
            default:
                printf("\nYou enter the wrong choice.");
                break;
        }
        printf("\n\nPress (Y/y) to continue = ");
        fflush(stdin);
        scanf("%c", &ch);
    }while ((ch == 'Y') || (ch == 'y'));
}
