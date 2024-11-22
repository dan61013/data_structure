#include <iostream>
#include <conio.h>
using namespace std;

void fact(int no, int facto) {
    if (no <= 1) {
        cout << "\nThe Factorial is = " << facto;
        return;
    }
    else {
        facto = facto * no;
        fact(--no, facto);
    }
}

int main() {
    system("cls");
    int number, factorial;

    factorial = 1;
    cout << "\nEnter the No = ";
    cin >> number;
    fact(number, factorial);
    getch();
}