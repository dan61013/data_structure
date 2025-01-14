// insertion sort
#include <stdio.h>
#include <conio.h>
#define MAX 20

void main() {
    int arr[MAX], i, j, k, n;
    system("cls");
    // Type the number of elements
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    // Type the value of each element
    for (i = 0; i < n; i++) {
        printf("\nEnter the element: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Print the unsorted list
    printf("\nUnsorted list is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Insertion sort
    for (j = 1; j < n; j++) {
        // save the (i+1) element as k
        k = arr[j];
        // compare with the sorted list elements
        for (i = j - 1; i >= 0 && k < arr[i]; i--) {
            // move the arr[i] to next position
            arr[i+1] = arr[i];
        }
        // arr[i] = k(the saving element)
        arr[i+1] = k;
        printf("Pass %d, Element inserted in proper place: %d\n", j, k);
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    // Print sorted list
    printf("\nSorted list is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    getch();
}