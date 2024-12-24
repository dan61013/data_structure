// Doubly Linked List

#include <conio.h>
#include <stdio.h>
#include <malloc.h>
#include <process.h>

struct node {
    int val;
    struct node *next;
    struct node *prev;
}*start;
typedef struct node *NODE;

void create_list(int num) {
    NODE i, temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->val = num;
    temp->prev = NULL;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    }
    else {
        i = start;
        while (i->next != NULL) {
            i = i->next;
        }
        i->next = temp;
        temp->prev = i;
    }
}

void addAtBeg(int num) {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->val = num;
    temp->prev = NULL;
    temp->next = start;
    start->prev = temp;
    start = temp;
}

void addAfter(int num, int pos) {
    NODE temp, q;
    int i;

    q = start;
    for (i = 0; i < pos - 1; i++) {
        q = q->next;
        if (q == NULL) {
            printf("\nThere are less than %d elements\n", pos);
            return;
        }
    }
    temp = (NODE)malloc(sizeof(struct node));
    temp->val = num;
    q->next->prev = temp;
    temp->next = q->next;
    temp->prev = q;
    q->next = temp;
}

void del(int num) {
    NODE temp, q;
    if (start->val == num) {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        return;
    }

    q = start;
    while (q->next->next != NULL) {
        if (q->next->val == num) {
            temp = q->next;
            q->next = temp->next;
            temp->next->prev = q;
            free(temp);
            return;
        }
        q = q->next;
    }
    if (q->next->val == num) {
        temp = q->next;
        free(temp);
        q->next = NULL;
        return;
    }
    printf("\nElement %d not found\n", num);
}

void display() {
    NODE q;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    q = start;
    printf("\nList is: \n");
    while (q != NULL) {
        printf("%d ", q->val);
        q = q->next;
    }
    printf("\n");
}

void count() {
    NODE q = start;
    int cnt = 0;
    while (q != NULL) {
        q = q->next;
        cnt++;
    }
    printf("\nNumber of elements are %d\n", cnt);
}

void rev() {
    NODE p1, p2;
    // p1, p2 = start & start->next
    p1 = start;
    p2 = p1->next;
    // start will be the latest, so next will be NULL
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        // ge to next loop
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
}

void main() {
    int choice, n, m, po, i;
    start = NULL;
    while (1) {
        system("cls");
        printf("\n1. Create List\n");
        printf("2. Add at begging\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Count\n");
        printf("7. Reverse\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nHow many nodes you want: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("\nEnter the element: ");
                    scanf("%d", &m);
                    create_list(m);
                }
                break;
            case 2:
                printf("\nEnter the element: ");
                scanf("%d", &m);
                addAtBeg(m);
                break;
            case 3:
                printf("\nEnter the element: ");
                scanf("%d", &m);
                printf("\nEnter the position after which this element is inserted: ");
                scanf("%d", &po);
                addAfter(m, po);
                break;
            case 4:
                printf("\nEnter the element for deletion: ");
                scanf("%d", &m);
                del(m);
                break;
            case 5:
                display();
                getch();
                break;
            case 6:
                count();
                getch();
                break;
            case 7:
                rev();
                printf("Reverse is completed.");
                getch();
                break;
            case 8:
                exit(0);
            default:
                printf("\nWrong choice.\n");
                getch();
        }
    }
}
