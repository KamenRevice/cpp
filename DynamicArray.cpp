/*
 * @Description: 实现动态数组类Array，该类具有如下功能：
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-08-30 16:58:10
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-10 14:42:56
 */
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

template <typename T, int N>
class Array
{
public:
    Array();
    ~Array();

public:
    T &operator[](int i);                    // 重载[]运算符
    int length() const { return m_length; }; // 返回数组长度
    bool capacity(int n);                    // 改变数组容量
private:
    int m_length;   // 数组的当前长度
    int m_capacity; // 当前内存的容量,能容纳的元素的个数
    T *m_p;         // 指向数组内存的指针
};
template <typename T, int N>
Array<T, N>::Array()
{
    m_p = new T[N];
    m_capacity = m_length = N;
}
template <typename T, int N>
Array<T, N>::~Array()
{
    delete[] m_p;
}
template <typename T, int N>
T &Array<T, N>::operator[](int i)
{
    if (i < 0 || i >= m_length)
    {
        cout << "Exception:Array index out of bounds!" << endl;
        exit(0);
    }
    return m_p[i];
}
template <typename T, int N>
bool Array<T, N>::capacity(int n)
{
    if (n > 0) // 增大数组
    {
        int len = m_length + n; // 增大后数组的长度
        if (len <= m_capacity)
        { // 现有内存足以容纳增大后的数组
            m_length = len;
            return true;
        }
        else
        {                                                   // 现有内存不能容纳增大后的数组
            T *pTemp = new T[m_length + 2 * n * sizeof(T)]; // 增加的内存足以容纳2*n
            if (pTemp == NULL)                              // 内存分配失败
            {
                cout << "Exception:Faild to allocate memory!" << endl;
                return false;
            }
            else
            {                                             // 内存分配成功
                memcpy(pTemp, m_p, m_length * sizeof(T)); // 复制原数组元素到新数组
                delete[] m_p;                             // 释放原数组内存
                m_p = pTemp;                              // 指向新数组
                m_capacity = m_length = len;
                return true;
            }
        }
    }
    else
    {
        int len = m_length - abs(n); // 收缩后的数组长度
        if (len < 0)
        {
            cout << "Exception:Array length is too small!" << endl;
            return false;
        }
        else
        {
            m_length = len;
            return true;
        }
    }
}

int main()
{
    Array<int, 5> arr;
    // 为数组赋值
    for (int i = 0, len = arr.length(); i < len; i++)
    {
        arr[i] = 2 * i;
    }

    // 第一次打印数组
    for (int i = 0, len = arr.length(); i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 增大数组容量
    arr.capacity(8);
    for (int i = 5, len = arr.length(); i < len; i++)
    {
        arr[i] = 2 * i;
    }
    // 第二次打印数组
    for (int i = 0, len = arr.length(); i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 收缩数组容量
    arr.capacity(-3);
    // 第三次打印数组
    for (int i = 0, len = arr.length(); i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}