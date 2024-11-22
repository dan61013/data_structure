// Tower of Hanoi
#include <iostream>
#include <conio.h>
using namespace std;

class tower {
    // Private variables
    int NoDisk;
    char FromTower, ToTower, AuxTower;

    public:
        void hanoi(int, char, char, char);
};

void tower::hanoi(int NoDisk, char FromTower, char ToTower, char AuxTower) {
    if (NoDisk == 1) {
        cout << "\nMove from disk 1 from tower " << FromTower << " to tower " << ToTower;
        return;
    }

    hanoi(NoDisk - 1, FromTower, AuxTower, ToTower);
    cout << "\nMove from disk " << NoDisk << " from tower " << FromTower << " to tower" << ToTower;
    hanoi(NoDisk - 1, AuxTower, ToTower, FromTower);
    return;
}

int main() {
    int No;
    tower Ob;
    system("cls");
    cout << "\n\t\t\t--- Tower of Hanoi ---\n";
    cout << "\n\nEnter the number of disks = ";
    cin >> No;
    Ob.hanoi(No, 'X', 'Y', 'Z');
    cout << "\n\nPress any key to continue...";
    getch();
}