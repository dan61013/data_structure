#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

struct node {
    float coef;
    int expo;
    struct node *link;
};
typedef struct node *NODE;

NODE insert(NODE start, float coef, int expo) {
    NODE ptr, temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->coef = coef;
    temp->expo = expo;

    if (start == NULL || expo > start->expo) {
        temp->link = start;
        start = temp;
    }
    else {
        ptr = start;
        while (ptr->link != NULL && ptr->link->expo > expo) {
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
        if (ptr->link == NULL) {
            temp->link = NULL;
        }
    }
    return start;
}

NODE poly_add(NODE p1, NODE p2) {
    NODE p3_start, p3, temp;
    p3_start = NULL;
    if (p1 == NULL && p2 == NULL) {
        return p3_start;
    }
    
    while (p1 != NULL && p2 != NULL) {
        temp = (NODE)malloc(sizeof(struct node));
        if (p3_start == NULL) {
            p3_start = temp;
            p3 = p3_start;
        }
        else {
            p3->link = temp;
            p3 = p3->link;
        }
        if (p1->expo > p2->expo) {
            temp->coef = p1->coef;
            p1 = p1->link;
        }
        else {
            if (p2->expo > p1->expo) {
                temp->coef = p2->coef;
                temp->expo = p2->expo;
                p2 = p2->link;
            }
            else {
                if (p1->expo == p2->expo) {
                    temp->coef = p1->coef + p2->coef;
                    temp->expo = p1->expo;
                    p1 = p1->link;
                    p2 = p2->link;
                }
            }
        }
    }
    while (p1 != NULL) {
        temp = (NODE)malloc(sizeof(struct node));
        temp->coef = p1->coef;
        temp->expo = p1->expo;
        if (p3_start == NULL) {
            p3_start = temp;
            p3 = p3_start;
        }
        else {
            p3->link = temp;
            p3 = p3->link;
        }
        p1 = p1->link;
    }
    while (p2 != NULL) {
        temp = (NODE)malloc(sizeof(struct node));
        temp->coef = p2->coef;
        temp->expo = p2->expo;
        if (p3_start == NULL) {
            p3_start = temp;
            p3 = p3_start;
        }
        else {
            p3->link = temp;
            p3 = p3->link;
        }
        p2 = p2->link;
    }
    p3->link = NULL;
    return p3_start;
}

NODE enter(NODE start) {
    int i, n, expo;
    float coef;
    printf("\nHow many terms u want to enter: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        printf("\nEnter coefficient for term %d:", i);
        scanf("%f", &coef);
        printf("Enter exponent for term %d:", i);
        scanf("%d", &expo);
        start = insert(start, coef, expo);
    }
    return start;
}

void display(NODE ptr) {
    if (ptr == NULL) {
        printf("\nEmpty\n");
        return;
    }
    while (ptr != NULL) {
        printf("(%.1fx^%d) + ", ptr->coef, ptr->expo);
        ptr = ptr->link;
    }
    printf("\b\b\n");
}

void main() {
    NODE p1_start, p2_start, p3_start;

    p1_start = NULL;
    p2_start = NULL;
    p3_start = NULL;

    printf("\nPolynomial 1 :\n");
    p1_start = enter(p1_start);

    printf("\nPolynomial 2 :\n");
    p2_start = enter(p2_start);
    p3_start = poly_add(p1_start, p2_start);

    system("cls");
    printf("\nPolynomial 1 is: ");
    display(p1_start);
    printf("\nPolynomial 2 is: ");
    display(p2_start);
    printf("\nPolynomial 3 is: ");
    display(p3_start);
    getch();
}
