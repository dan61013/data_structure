// Binary Search
#include <conio.h>
#include <stdio.h>

void main() {
    char opt;
    int arr[20], start, end, middle, n, i, item;
    system("cls");

    // Create array
    printf("\nHow many elements you want to enter in the array: ");
    scanf("%d", &n);

    for (i=0; i < n; i++) {
        printf("\nEnter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n\nPress any key to continue...");
    getch();


    do {
        system("cls");
        // enter the searched number
        printf("\nEnter the element to be searched: ");
        scanf("%d", &item);

        start = 0;
        end = n - 1;
        middle = (start + end) / 2;
        
        // check the item is on the left or right subarray
        while (item != arr[middle] && start <= end) {
            if (item > arr[middle]) {
                start = middle + 1;
            }
            else {
                end = middle - 1;
            }
            middle = (start + end) / 2;
        }
        // find the position of item in array
        if (item == arr[middle]) {
            printf("\n%d found at position %d\n", item, middle + 1);
        }
        if (start > end) {
            printf("\n%d not found in array\n", item);
        }
        printf("\n\nPress (Y/y) to continue: ");
        fflush(stdin);
        scanf("%c", &opt);
    }while (opt == 'Y' || opt == 'y');
}