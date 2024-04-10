/*
 * @Description:杨辉三角 计算和展示
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-04-02 21:09:02
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-02 21:09:13
 */

#include <iostream>
#include <iomanip>
using namespace std;

int *YangHuiData(int n);             // n是杨辉三角形的行数
void YangHuiShow(int *pData, int n); // 在屏幕上打印杨辉三角形
int main()
{
    int n;
    cout << "请输入杨辉三角形的行数";
    cin >> n;
    // 计算杨辉三角并保存到二维数组
    int *pData = YangHuiData(n);
    // 在屏幕上打印等腰三角形的杨辉三角
    YangHuiShow(pData, n);
    // n是杨辉三角形的行数
}

int *YangHuiData(int n)
{
    int *a = new int[n * n];
    // 完成杨辉三角形的计算，没有显示的位置填0
    int i, j;
    for (i = 0; i < n * n; i++)
    {
        a[i] = 0; // 填0操作
    }

    a[0] = 1;
    a[n] = 1;
    a[n + 1] = 1;

    for (i = 2; i < n; i++)
    {
        a[i * n] = 1;
        a[i * n + i] = 1;
        for (j = 1; j < i; j++)
        {
            a[i * n + j] = a[(i - 1) * n + j - 1] + a[(i - 1) * n + j]; // 通过a[i*n+j]来访问第(i*n+j)个数据,根据杨辉三角的特性求值
        }
    }

    return a;
}
void YangHuiShow(int *a, int n)
{
    // 根据数据a指向的二维数组在屏幕上打印
    // 杨辉三角形，每行前面填充合适的空格
    // 以显示成等腰三角形，左右对称
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
            cout << setw(3) << " "; // 前导空格，为单个数据的一半宽度
        for (j = 0; j <= i; j++)
            cout << setw(6) << a[i * n + j];
        cout << endl;
    }
}
