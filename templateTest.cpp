#include <iostream>

using namespace std;

template <typename T>
void Swap(T &a, T &b); // 模板1:交换基本类型的值

template <typename T>
void Swap(T a[], T b[], int len); // 模板2:交换两个数组

void printArray(int arr[], int size);

int main()
{
    // 交换基本类型的值
    int m = 10, n = 99;
    Swap(m, n); // 匹配模板1
    cout << "m=" << m << ",n=" << n << endl;

    // 交换两个数组
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    int len = sizeof(arr1) / sizeof(int);
    Swap(arr1, arr2, len); // 匹配模板2
    printArray(arr1, len);
    printArray(arr2, len);

    return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[], int len)
{
    T temp;
    for (int i = 0; i < len; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            cout << arr[i] << endl;
        }
        else
        {
            cout << arr[i] << ",";
        }
    }
}