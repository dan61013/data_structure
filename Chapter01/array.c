#include <stdio.h>

void oneDimensionalArray() {
    int A[5] = {1, 2, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("One dimensional array:\n");
    for (int i = 0; i < n; i++) {
        printf("Value: %d, Memory address: %p\n", A[i], &A[i]);
    }
}

void twoDimensionalArray() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = sizeof(A) / sizeof(A[0]);
    int columns = sizeof(A[0]) / sizeof(A[0][0]);

    printf("Two dimensional array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Value: %d, Memory address: %p\n", A[i][j], &A[i][j]);
        }
    }
}

int main() {
    oneDimensionalArray();
    twoDimensionalArray();

    return 0;
}