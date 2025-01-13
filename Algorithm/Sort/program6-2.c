// Bubble sort using Dynamic Memory ALlocation
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void bubbleSort(int *a, int n) {
    int i, j, k, temp;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void main() {
    int *a, n, *l, *temp;
    system("cls");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    a = ((int*)malloc(n * sizeof(int)));
    temp = a;
    // compare the memory address
    l = a + n;
    printf("\nEnter the elements:\n");
    while (a < l) {
        scanf("%d", a);
        a++;  // move the pointer to next
    }
    bubbleSort(temp, n);
    printf("\nSorted array is: ");
    a = temp;
    while (a < l) {
        printf("%d ", *a);
        a++;
    }
    getch();
}