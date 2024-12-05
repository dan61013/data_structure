#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
    int value;
    struct node *link;
};
// define NODE as the pointer of struct node
typedef struct node *NODE;

// NODE: return type is NODE, and the parameter type also is NODE
NODE push(NODE top) {
    /*
    1. create the NewNode for saving the input value
    2. Memory allocate -> NewNode
    3. input value
    4. set the NewNode->value = input value
    5. set the NewNode->link = original top node
    */
    NODE NewNode;
    int pushed_item;
    NewNode = (NODE)malloc(sizeof(struct node));
    printf("\nInput the new value to be pushed on the stack: ");
    scanf("%d", &pushed_item);
    NewNode->value = pushed_item;
    NewNode->link = top;
    top = NewNode;
    return (top);
}

NODE pop(NODE top) {
    NODE temp;
    if (top == NULL) {
        printf("\nStack is empty.");
    }
    else {
        temp = top;
        printf("\nPopped item is %d\n", temp->value);
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
    return (top);
}

void display(NODE top) {
    if (top == NULL) {
        printf("\nStack is empty.");
    }
    else {
        printf("\nStack element: \n");
        while (top != NULL) {
            printf("%d\n", top->value);
            top = top->link;
        }
    }
}

void main() {
    char opt;
    int choice;
    NODE Top = NULL;
    do {
        system("cls");
        printf("\n1. Push\n");
        printf("\n2. Pop\n");
        printf("\n3. Display\n");
        printf("\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Top = push(Top);
                break;
            case 2:
                Top = pop(Top);
                break;
            case 3:
                display(Top);
                break;
            case 4:
                exit(1);
            default:
                printf("\nWrong choice\n");
        }
        printf("\n\nDo you want to continue (Y/y) = ");
        fflush(stdin);
        scanf("%c", &opt);
    }while ((opt == 'Y') || (opt == 'y'));
}
