#include <iostream>
#include "func.h"

using namespace std;

// extern template void Swap(int &a, int &b);
// extern template void Swap(double &a, double &b);

int main()
{
    int n1 = 10, n2 = 30;
    Swap(n1, n2);

    cout << n1 << endl
         << n2;

    double d1 = 1.2, d2 = 3.4;
    Swap(d1, d2);

    cout << endl;

    cout << "hello world" << endl;
    return 0;
}
