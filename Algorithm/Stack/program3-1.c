#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXSIZE 100

// The stack array and top variables in a structure
struct stack {
    int stack[MAXSIZE];
    int Top;
};

// Defined "struct stack" to "NODE"
typedef struct stack NODE;

void push(NODE *pu) {
    int item;

    if (pu->Top == MAXSIZE - 1) {
        printf("\nThe Stack is full.");
        getch();
    }
    else {
        printf("\nEnter the element to be inserted = ");
        scanf("%d", &item);
        pu->stack[++pu->Top] = item;
    }
}

void pop(NODE *po) {
    int item;

    if (po->Top == -1) {
        printf("\nThe Stack is empty.");
    }
    else {
        item = po->stack[po->Top--];
        printf("\nThe Deleted Element is = %d", item);
    }
}

void traverse(NODE *pt) {
    int i;

    if (pt->Top == -1) {
        printf("\nThe Stack is empty.");
    }
    else {
        printf("\n\nThe Element(s) in the Stack(s) is/are...");
        for (i = pt->Top; i >= 0; i--) {
            printf("\n %d", pt->stack[i]);
        }
    }
}

void main() {
    int choice;
    char ch;
    // Declare an pointer variable to the structure
    // Need to allocate the memory space to *ps, or can't execute
    NODE *ps = (NODE *)malloc(sizeof(NODE));
    if (ps == NULL) {
        printf("Memory allocation is failed\n");
        exit(0);
    }
    ps->Top = -1;
    
    do {
        system("cls");
        // Menu for the Stack operations
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traversal");
        printf("\nEnter Your Choice = ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push(ps);
                break;
            case 2:
                pop(ps);
                break;
            case 3:
                traverse(ps);
                break;
            
            default:
                printf("\nYou entered wrong choice.");
        }
        printf("\n\nPress (Y/y) to continue = ");
        fflush(stdin);
        scanf("%c", &ch);
    }while (ch == 'Y' || ch == 'y');
}