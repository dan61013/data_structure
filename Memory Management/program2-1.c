#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <process.h>

#define NULL ((void *)0)

void main() {
    int i, n, sum;
    int *ptr, *ele;
    
    // clrscr();
    system("cls");  // in Windows, clear the terminal
    printf("\nEnter the number of element(s) to be add = ");
    scanf("%d", &n);

    // allocate the memory space, as n * size of integer
    ptr = (int *)malloc(n * sizeof(int));
    // Check if the ptr is available
    if (ptr == NULL) {
        printf("\n\nMemory allocation is failed.");
        exit(0);
    }

    // Let user type "n" numbers
    for (ele = ptr, i = 1; ele < (ptr + n); ele++, i++) {
        printf("Enter the %d element = ", i);
        scanf("%d", ele);
    }

    // sum of all numbers
    for (ele = ptr, sum = 0; ele < (ptr + n); ele++) {
        sum += *ele;
    }
    
    printf("\n\nThe SUM of no(s) is = %d", sum);
    getch();
}