#include <stdio.h>
#include <conio.h>
#define MAX 20

void main() {
    int arr[MAX], i, j, k, n, temp, smallest;
    system("cls");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted list is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Selection sort
    for (i = 0; i < n - 1; i++) {
        smallest = i;
        for (k = i + 1; k < n; k++) {
            if (arr[smallest] > arr[k]) {
                smallest = k;
            }
        }
        // change the position between arr[smallest] and arr[i]
        if (i != smallest) {
            temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
        }
        printf("\nAfter Pass %d elements are: ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    printf("\nSorted list is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    getch();
}