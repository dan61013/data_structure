#include <iostream>
using namespace std;

int main() {
    int *Var1 = new int;
    float *Var2 = new float;

    cout << &Var1 << endl;

    delete Var1;
    delete Var2;

    return 0;
}