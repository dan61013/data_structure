#include <iostream>
#include <conio.h>
using namespace std;

#define MAXSIZE 100

struct STACK_ARRAY {
    int stack[MAXSIZE];
    int Top;

    public:
        STACK_ARRAY() {
            Top = -1;
        }
        void push();
        void pop();
        void traverse();
};

void STACK_ARRAY::push() {
    int item;

    if (Top == MAXSIZE - 1) {
        cout << "\nThe Stack is full.";
        getch();
    }
    else {
        cout << "\nEnter the element to be inserted = ";
        cin >> item;
        stack[++Top] = item;
    }
}

void STACK_ARRAY::pop() {
    int item;

    if (Top == -1) {
        cout << "\nThe Stack is empty.";
    }
    else {
        item = stack[Top--];
        cout << "\nThe deleted element is = " << item;
    }
}

void STACK_ARRAY::traverse() {
    int i;
    
    if (Top == -1) {
        cout << "\nThe Stack is empty.";
    }
    else {
        cout << "\n\nThe element(s) in the Stack(s) is/are...";
        for (i = Top; i >= 0; i--) {
            cout << "\n " << stack[i];
        }
    }
}

int main() {
    int choice;
    char ch;
    STACK_ARRAY ps;

    do {
        system("cls");
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Traverse";
        cout << "\nEnter your choice = ";
        cin >> choice;
        switch (choice) {
            case 1:
                ps.push();
                break;
            case 2:
                ps.pop();
                break;
            case 3:
                ps.traverse();
                break;
            default:
                cout << "\n\nYou entered the wrong choice.";
        }
        cout << "\n\nPress (Y/y) to continue = ";
        cin >> ch;
    }while (ch == 'Y' || ch == 'y');
}
