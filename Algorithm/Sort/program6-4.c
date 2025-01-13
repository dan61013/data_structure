#include <stdio.h>
#include <conio.h>
#include <malloc.h>

void selectionSort(int *a, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = i+1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void main() {
    int *a, n, *l, temp;
    system("cls");
    printf("\nEnter the number of elements: \n");
    scanf("%d", &n);

    // allocate the memory
    a = ((int *)malloc(n * sizeof(int)));
    // temp = the memory space (a)
    temp = a;
    // l = the latest element
    l = a + n;
    printf("\nEnter the elements: \n");
    while (a < l) {
        scanf("%d", a);
        a++;
    }

    selectionSort(temp, n);
    printf("\nSorted array: ");
    a = temp;
    while (a < l) {
        printf("%d ", *a);
        a++;
    }
    getch();
}