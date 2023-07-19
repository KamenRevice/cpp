#include <iostream>

using namespace std;

double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
double &setValues(int i)
{
    double &ref = vals[i];
    return ref;
}

int main()
{
    const int x = 10;
    // itn
    int y;
    cout << "改变前的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "]" << vals[i] << endl;
    }

    setValues(1) = 22.22;
    setValues(3) = 44.44;

    cout << "改变后的值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "]" << vals[i] << endl;
    }

    return 0;
}