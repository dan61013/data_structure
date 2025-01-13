// Bubble sort using array
#include <conio.h>
#include <stdio.h>
#define MAX 20

void main() {
    int arr[MAX], i, j, k, temp, n, xchanges;
    system("cls");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted list is : \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble Sort
    for (i = 0; i < n - 1; i++) {
        xchanges = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                xchanges++;
            }
        }
        if (xchanges == 0) {
            break;
        }
        printf("\nAfter Pass %d elements are: ", i + 1);
        for (k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
    printf("\nSorted list is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    getch();
}