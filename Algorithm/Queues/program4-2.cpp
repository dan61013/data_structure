#include <iostream>
#include <conio.h>
#include <process.h>
using namespace std;

#define MAX 50

class circular_queue {
    int cqueue_arr[MAX];
    int front, rear;
    public:
        circular_queue() {
            front = -1;
            rear = -1;
        }
        void insert();
        void del();
        void display();
};

void circular_queue::insert() {
    int added_item;

    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        cout << "\nQueue Overflow \n";
        getch();
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        if (rear == MAX - 1) {
            rear = 0;
        }
        else {
            rear += 1;
        }
        cout << "\nInput the element for insertion in queue:";
        cin >> added_item;
        cqueue_arr[rear] = added_item;
    }
}

void circular_queue::del() {
    if (front == -1) {
        cout << "\nQueue Underflow\n";
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        if (front == MAX - 1) {
            front = 0;
        }
        else {
            front += 1;
        }
    }
}

void circular_queue::display() {
    int front_pos = front, rear_pos = rear;

    if (front == -1) {
        cout << "\nQueue is empty\n";
        return;
    }
    cout << "\nQueue elements:\n";
    if (front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            cout << cqueue_arr[front_pos] << ",";
            front_pos++;
        }
    }
    else {
        while (front_pos <= MAX - 1) {
            cout << cqueue_arr[front_pos] << ",";
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos) {
            cout << cqueue_arr[front_pos] << ",";
            front_pos++;
        }
    }
    cout << "\n";
}

int main(void) {
    int choice;

    circular_queue co;
    while (1)
    {
        system("cls");

        cout << "\n1. Insert\n";
        cout << "\n2. Delete\n";
        cout << "\n3. Display\n";
        cout << "\n4. Quit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                co.insert();
                break;
            case 2:
                co.del();
                getch();
                break;
            case 3:
                co.display();
                getch();
                break;
            case 4:
                exit(1);
            default:
                cout << "\nWrong choice\n";
                getch();
        }
    }
}