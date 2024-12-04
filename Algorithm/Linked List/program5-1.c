#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <process.h>

struct node {
    // the value of current node
    int value;
    // link to next node
    struct node *link;
}*start;

void Create_List(int data) {
    struct node *q, *temp;
    {
        // save input value into temp node
        temp = (struct node*)malloc(sizeof(struct node));
        temp->value = data;
        temp->link = NULL;

        // start is null (empty Linked List)
        if (start == NULL) {
            // set temp as start
            start = temp;
        }
        else {
            // if start is not NULL
            q = start;
            // find the latest node
            while (q->link != NULL) {
                q = q->link;
            }
            // add the input value at the latest position
            q->link = temp;
        }
    };
}

void AddAtBeg(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    // save input value into temp
    temp->value = data;
    // set the next node of temp is start node
    temp->link = start;
    // let start == temp(modify the start pointer)
    start = temp;
}

void AddAfter(int data, int pos) {
    struct node *temp, *q;
    int i;
    q = start;

    for (i = 0; i < pos - 1; i++) {
        // traversal all the nodes of the Linked List
        q = q->link;
        // if the position > length of Linked List, then print the message and return
        if (q == NULL) {
            printf("\n\n There are less than %d elements", pos);
            getch();
            return;
        }
    }
    // execute below statements when find the position (i = position - 1)
    temp = (struct node*)malloc(sizeof(struct node));
    // save q->link(node) as temp->linn
    temp->link = q->link;
    // temp->value = input value(data)
    temp->value = data;
    // let the node of position (q+1) == temp, means q's next node is temp(input value)
    q->link = temp;
}

void Del(int data) {
    struct node *temp, *q;
    // if start value == data, let temp == start, and start->link as start.
    if (start->value == data) {
        temp = start;
        start = start->link;
        // free temp(original start node)
        free(temp);
        return;
    }
    q = start;
    while (q->link->link != NULL) {
        if (q->link->value == data) {
            temp = q->link;
            q->link = temp->link;
            free(temp);
            return;
        }
        q = q->link;
    }
    if (q->link->value == data) {
        temp = q->link;
        free(temp);
        q->link = NULL;
        return;
    }
    printf("\n\nElement %d not found", data);
    getch();
}

void Display() {
    struct node *q;
    if (start == NULL) {
        printf("\n\nList is empty");
        return;
    }
    q = start;
    printf("\n\nList is : ");
    while (q != NULL) {
        printf("%d ", q->value);
        q = q->link;
    }
    printf("\n");
    getch();
}

void Count() {
    struct node *q = start;
    int cnt = 0;
    while (q != NULL) {
        q = q->link;
        cnt++;
    }
    printf("Number of elements are %d\n", cnt);
    getch();
}

void Rev() {
    struct node *p1, *p2, *p3;
    if (start->link == NULL) {
        return;
    }
    p1 = start;
    p2 = p1->link;
    p3 = p2->link;
    p1->link = NULL;
    p2->link = p1;
    while (p3 != NULL) {
        p1 = p2;
        p2 = p3;
        p3 = p3->link;
        p2->link = p1;
    }
    start = p2;
}

void Search(int data) {
    struct node *ptr = start;
    int pos = 1;

    while (ptr != NULL) {
        if (ptr->value == data) {
            printf("\n\nItem %d found at position %d", data, pos);
            getch();
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    if (ptr == NULL) {
        printf("\n\nItem %d not found in list", data);
    }
    getch();
}

void main() {
    int choice, n, m, position, i;
    start = NULL;

    while (1) {
        system("cls");
        printf("1. Create List\n");
        printf("2. Add at begging\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Count\n");
        printf("7. Reverse\n");
        printf("8. Search\n");
        printf("9. Quit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\n\nHow many nodes you want: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("\nEnter the element: ");
                    scanf("%d", &m);
                    Create_List(m);
                }
                break;
            case 2:
                printf("\n\nEnter the element: ");
                scanf("%d", &m);
                AddAtBeg(m);
                break;
            case 3:
                printf("\nEnter the element:" );
                scanf("%d", &m);
                printf("\nEnter the position after which this element is inserted: ");
                scanf("%d", &position);
                AddAfter(m, position);
                break;
            case 4:
                if (start == NULL) {
                    printf("\n\nList is empty");
                    continue;
                }
                printf("\n\nEnter the element for deletion: ");
                scanf("%d", &m);
                Del(m);
                break;
            case 5:
                Display();
                break;
            case 6:
                Count();
                break;
            case 7:
                Rev();
                break;
            case 8:
                printf("\n\nEnter the element to be searched: ");
                scanf("%d", &m);
                Search(m);
                break;
            case 9:
                exit(0);
            default:
                printf("\n\nWrong choice");
        }
    }
}
