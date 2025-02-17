// Interpolation Search
#include <iostream>
#include <conio.h>
using namespace std;

class Interpolation {
    int key;
    int low, high, mid;

    public:
        void interSearch(int*, int);
};

void Interpolation::interSearch(int *arr, int no) {
    int key;
    low = 0;
    high = no - 1;

    cout << "\n\nEnter the number to be searched: ";
    cin >> key;

    while (low < high) {
        // formula
        mid = low + (high - low) * ((key - arr[low]) / (arr[high] - arr[low]));
        if (key < arr[mid]) {
            high = mid - 1;
        }
        else if (key > arr[mid]) {
            low = mid + 1;
        }
        else {
            cout << "\nThe key " << key << " is found at location " << mid;
            return;
        }
    };
    cout << "\n\nThe key " << key << " is NOT found";
}

int main() {
    int *a, n, *b;
    char opt;
    Interpolation ob;
    system("cls");
    cout << "\n\nEnter the number of elements: ";
    cin >> n;

    a = new int[n];
    b = a;
    for (int i=0; i < n; i++) {
        cout << "Enter the " << i << " element: ";
        cin >> *a;
        a++;
    }
    do {
        ob.interSearch(b, n);
        cout << "\n\nPress (Y/y) to continue: ";
        cin >> opt;
        getch();
    }while (opt == 'Y' || opt == 'y');
    
    return 0;
}