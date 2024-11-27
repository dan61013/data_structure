// Infix to Postfix notation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Definition the maximum stack size
#define MAXSIZE 100

// the stack structure
struct stack {
    char stack[MAXSIZE];
    int Top;
};
typedef struct stack NODE;

void push(NODE *pu, char item) {
    if (pu->Top == MAXSIZE - 1) {
        printf("\nThe Stack is full.");
        getch();
    }
    else {
        pu->stack[++pu->Top] = item;
    }
}

char pop(NODE *po) {
    char item = '#';

    if (po->Top == -1) {
        printf("\n\nThe Stack is empty. Invalid infix expression.");
    }
    else {
        item = po->stack[po->Top--];
    }
    return(item);
}

int prec(char symbol) {
    switch(symbol) {
        case '(':
            return(1);
        case ')':
            return(2);
        case '+':
        case '-':
            return(3);
        case '*':
        case '/':
        case '%':
            return(4);
        case '^':
            return(5);
        default:
            return(0);
    }
}

void Infix_Postfix(char infix[]) {
    int len, priority;
    char postfix[MAXSIZE], ch;
    // Allocate memory space
    NODE *ps = (NODE *)malloc(sizeof(NODE));
    ps->Top = -1;
    len = strlen(infix);
    infix[len++] = ')';
    push(ps, '(');
    int j = 0;
    for (int i = 0; i < len; i++) {
        switch(prec(infix[i])) {
            case 1:
                push(ps, infix[i]);
                break;
            case 2:
                ch = pop(ps);
                while(ch != '(') {
                    postfix[j++] = ch;
                    ch = pop(ps);
                }
                break;
            case 3:
                ch = pop(ps);
                while(prec(ch) >= 3) {
                    postfix[j++] =ch;
                    ch = pop(ps);
                }
                push(ps, ch);
                push(ps, infix[i]);
                break;
            case 4:
                ch = pop(ps);
                while(prec(ch) >= 4) {
                    postfix[j++] = ch;
                    ch = pop(ps);
                }
                push(ps, ch);
                push(ps, infix[i]);
                break;
            case 5:
                ch = pop(ps);
                while(prec(ch) == 5) {
                    postfix[j++] = ch;
                    ch = pop(ps);
                }
                push(ps, ch);
                push(ps, infix[i]);
                break;
            default:
                postfix[j++] = infix[i];
                break;
        }
    }
    postfix[j] = '\0';
    printf("\nThe Postfix expression = ");
    printf("%s", postfix);
}

void main() {
    char choice, infix[MAXSIZE];
    do {
        system("cls");
        printf("\n\nEnter the infix notation = ");
        fflush(stdin);
        fgets(infix, 100, stdin);
        infix[strlen(infix) - 1] = '\0';
        Infix_Postfix(infix);
        printf("\n\nDo you want to continue (Y/y) = ");
        fflush(stdin);
        scanf("%c", &choice);
    }
    while(choice == 'Y' || choice == 'y');
}
