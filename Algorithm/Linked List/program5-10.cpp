// Implement Circular Singly Linked List
#include <iostream>
#include <process.h>
#include <conio.h>
using namespace std;

class Circular_Linked {
    struct node {
        int info;
        struct node *link;
    };
    struct node *last;
    typedef struct node *NODE;

    public:
        Circular_Linked() {
            last = NULL;
        }

        void create_list(int);
        void addAtBeg(int);
        void addAfter(int, int);
        void del();
        void display();
};

void Circular_Linked::create_list(int num) {
    NODE q, temp;
    temp = (NODE)new(struct node);
    temp->info = num;
    if (last == NULL) {
        last = temp;
        temp->link = last;
    }
    else {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}

void Circular_Linked::addAtBeg(int num) {
    NODE temp;
    temp = (NODE)new(struct node);
    temp->info = num;
    temp->link = last->link;
    last->link = temp;
}

void Circular_Linked::addAfter(int num, int pos) {
    NODE temp, q;
    int i;
    q = last->link;

    for (i = 0; i < pos - 1; i++) {
        q = q->link;
        if (q == last->link) {
            cout << "There are less than " << pos << " elements\n";
            return;
        }
    }
    temp = (NODE)new(struct node);
    temp->link = q->link;
    temp->info = num;
    q->link = temp;
    if (q == last) {
        last = temp;
    }
}

void Circular_Linked::del() {
    int num;
    if (last == NULL) {
        cout << "\nList underflow.\n";
        return;
    }
    cout << "\nEnter the number for deletion: ";
    cin >> num;

    NODE temp, q;
    // only a element in Linked List
    if (last->link == last && last->info == num) {
        temp = last;
        last = NULL;
        delete(temp);
        return;
    }
    // q = start
    q = last->link;
    // if start value == num
    if (q->info == num) {
        temp = q;
        // last->next = q(start)->link (second node)
        last->link = q->link;
        // free temp(original start node)
        delete(temp);
        return;
    }
    // while there are more than two nodes in Linked List
    while (q->link != last) {
        // if q->next value == num
        if (q->link->info == num) {
            temp = q->link;
            // q->link to q->next->next node(skip q->next)
            q->link = temp->link;
            // free q->link
            delete(temp);
            cout << "\n" << num << " deleted\n";
            return;
        }
        q = q->link;
    }
    // if the second node value == num
    if (q->link->info == num) {
        // save the second node in temp
        temp = q->link;
        // 
        q->link = last->link;
        delete(temp);
        last = q;
        return;
    }
    cout << "\nElement " << num << " not found\n";
}

void Circular_Linked::display() {
    NODE q;
    if (last == NULL) {
        cout << "\nList is empty.\n";
        return;
    }
    q = last->link;
    cout << "\nList is: ";
    while (q != last) {
        cout << q->info << " ";
        q = q->link;
    }
    cout << "\n" << last->info << endl;
}

int main() {
    int choice, n, m, po, i;
    Circular_Linked co;
    while (1) {
        system("cls");
        cout << "\n1. Create List\n";
        cout << "2. Add at beginning\n";
        cout << "3. Add after\n";
        cout << "4. Delete\n";
        cout << "5. Display\n";
        cout << "6. Quit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nHow many nodes you want: ";
                cin >> n;
                for (i = 0; i < n; i++) {
                    cout << "\nEnter the element: ";
                    cin >> m;
                    co.create_list(m);
                }
                break;
            case 2:
                cout << "\nEnter the element: ";
                cin >> m;
                co.addAtBeg(m);
                break;
            case 3:
                cout << "\nEnter the element: ";
                cin >> m;
                cout << "\nEnter the position after which this element is inserted: ";
                cin >> po;
                co.addAfter(m, po);
                break;
            case 4:
                co.del();
                break;
            case 5:
                co.display();
                getch();
                break;
            case 6:
                exit(0);
            default:
                cout << "\nWrong choice\n";
        }
    }
}
