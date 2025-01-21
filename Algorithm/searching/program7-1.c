// Sequential Searching
#include <conio.h>
#include <stdio.h>

void main() {
    char opt;
    int arr[20], n, i, item;
    system("cls");
    printf("\nHow many elements you want to enter in array: ");
    scanf("%d", &n);

    for (i=0; i < n; i++) {
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n\nPress any key to continue...");
    getch();

    do {
        system("cls");
        printf("\nEnter the element to be searched: ");
        scanf("%d", &item);

        for (i=0; i < n; i++) {
            if (item == arr[i]) {
                printf("\n%d found at position %d\n", item, i+1);
                break;
            }
        }
        if (i == n) {
            printf("\nItem %d not found in array.\n", item);
        }
        printf("\n\nPress (Y/y) to continue: ");
        fflush(stdin);
        scanf("%c", &opt);
    }while (opt == 'Y' || opt == 'y');
}