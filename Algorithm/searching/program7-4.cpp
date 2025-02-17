// Fibonacci Search
#include <iostream>
#include <conio.h>
using namespace std;

// Implement Fibonacci
int fib(int n) {
    int f1, f2, temp;
    f1 = 0;
    f2 = 1;

    for (int i=0; i<n; i++) {
        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
    }
    return f2;
}

int fibonacciSearch(int list[], int n, int item) {
    int f1, f2, mid, t, j;

    for (int j=1; fib(j) < n; j++);
    f1 = fib(j-2);
    f2 = fib(j-3);
    mid = n - f1 + 1;

    while (item != list[mid]) {
        if (mid < 0 || item > list[mid]) {
            if (f1 == 1) {
                return (-1);
            }
            mid = mid + f2;
            f1 = f1 - f2;
            f2 = f2 - f1;
        }
        else {
            if (f2 == 0) {
                return (-1);
            }
            mid = mid - f2;
            t = f1 - f2;
            f1 = f2;
            f2 = t;
        }
        return mid;
    }
}

int main() {
    int loc, n, item, list[50];
    cout << "\n\nEnter the total number of list: ";
    cin >> n;

    cout << "\nEnter the elements in list: ";
    for (int i=0; i < n; i++) {
        cout << "\nInput " << i << " th number: ";
        cin >> list[i];
    }

    cout << "\nEnter the number to be searched: ";
    cin >> item;
    loc = fibonacciSearch(list, n, item);
    if (loc != -1) {
        cout << "\nThe number is in list.";
    }
    else {
        cout << "\nThe number is not in list.";
    }
    getch();

    return 0;
}