// Radix sort with Linked list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node {
    int info;
    struct node *link;
}*start = NULL;

void display() {
    struct node *p = start;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n");
}

int largeDigit(struct node *p) {
    int large = 0, ndigit = 0;

    // compare each element and get the largest number
    while (p != NULL) {
        if (p->info > large) {
            large = p->info;
        }
        p = p->link;
    }
    printf("\nLargest Element is: %d ", large);
    // get the digit of the large number
    while (large != 0) {
        ndigit++;
        large = large / 10;
    }
    printf("\nNumber of digits in it are %d\n", ndigit);
    return ndigit;
}

int digit(int num, int k) {
    int digit, i;
    // get the digit with iteration
    for (i = 1; i <= k; i++) {
        digit = num % 10;
        num = num / 10;
    }
    return digit;
}

void radixSort() {
    int i, k, dig, maxDig, minDig, leastSig, mostSig;
    struct node *p, *rear[10], *front[10];

    leastSig = 1;
    mostSig = largeDigit(start);

    for (k = leastSig; k <= mostSig; k++) {
        printf("\nPass %d: Examining %dth from right ", k, k);
        for (i = 0; i <= 9; i++) {
            rear[i] = NULL;
            front[i] = NULL;
        }
        maxDig = 0;
        minDig = 9;
        p = start;
        
        // find the max and min digit
        while (p != NULL) {
            dig = digit(p->info, k);
            if (dig > maxDig) {
                maxDig = dig;
            }
            if (dig < minDig) {
                minDig = dig;
            }

            if (front[dig] == NULL) {
                front[dig] = p;
            }
            else {
                rear[dig]->link = p;
            }
            rear[dig] = p;
            
            p = p->link;
        }
        printf("\nminDig=%d maxDig=%d\n", minDig, maxDig);
        start = front[minDig];
        // merge all
        for (i = minDig; i < maxDig; i++) {
            // if next rear[i+1] != null, and then link current list rear node to next list front node
            if (rear[i+1] != NULL) {
                rear[i]->link = front[i+1];
            }
            // if next rear[i+1] == null, and then keep the previous rear[i] node
            else {
                rear[i+1] = rear[i];
            }
        }
        rear[maxDig]->link = NULL;
        printf("\nNew list: ");
        display();
    }
}

void main() {
    struct node *temp, *q;
    int i, n, item;
    system("cls");
    printf("\nEnter the number of elements in the list: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &item);

        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = item;
        temp->link = NULL;

        if (start == NULL) {
            start = temp;
        }
        else {
            q = start;
            while (q->link != NULL) {
                q = q->link;
            }
            q->link = temp;
        }
    }

    printf("\nUnsorted list is: \n");
    display();
    radixSort();
    printf("\nSorted list is: \n");
    display();
    getch();
}