// Quick Sort using Recursion
#include <conio.h>
#include <stdio.h>
#define MAX 30

enum bool {
    FALSE,
    TRUE
};

void display(int arr[], int low, int up) {
    int i;
    for (i = low; i <= up; i++) {
        printf("%d ", arr[i]);
    }
}

void quick(int arr[], int low, int up) {
    int piv, right, left, temp;
    enum bool pivot_placed = FALSE;
    
    left = low;
    right = up;
    piv = low;
    if (low >= up) {
        return;
    }
    printf("\nSublist: ");
    display(arr, low, up);

    while (pivot_placed == FALSE) {
        // Right
        while (arr[piv] <= arr[right] && piv != right) {
            right = right - 1;
        }
        if (piv == right) {
            pivot_placed = TRUE;
        }
        if (arr[piv] > arr[right]) {
            temp = arr[piv];
            arr[piv] = arr[right];
            arr[right] = temp;
            piv = right;
        }
        // Left
        while (arr[piv] >= arr[left] && left != piv) {
            left = left + 1;
        }
        if (piv == left) {
            pivot_placed = TRUE;
        }
        if (arr[left] > arr[piv]) {
            temp = arr[piv];
            arr[piv] = arr[left];
            arr[left] = temp;
            piv = left;
        }
    }

    printf("-> Pivot Placed is %d -> ", arr[piv]);
    display(arr, low, up);
    printf("\n");
    quick(arr, low, piv-1);
    quick(arr, piv+1, up);
}

void main() {
    int arr[MAX], n, i;
    system("cls");
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nUnsorted list is: \n");
    display(arr, 0, n - 1);
    printf("\n");

    quick(arr, 0, n - 1);
    printf("\nSorted list is: \n");
    display(arr, 0, n - 1);
    getch();
}
