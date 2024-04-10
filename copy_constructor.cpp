/*
 * @Description:C++拷贝构造函数
 * 拷贝构造函数是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：
 * 通过使用另一个同类型的对象来初始化新创建的对象。
 * 复制对象把它作为参数传递给函数。
 * 复制对象，并从函数返回这个对象
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-07-18 16:16:09
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-10 14:41:38
 */
// 2023.07.18

// https://www.runoob.com/cplusplus/cpp-copy-constructor.html
#include <iostream>

using namespace std;

class Line
{
public:
    int getLength(void);
    Line(int len);         // 简单的构造函数
    Line(const Line &obj); // 拷贝构造函数
    ~Line();               // 析构函数

private:
    int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针ptr分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}
Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
int Line::getLength(void)
{
    return *ptr;
}
void display(Line obj)
{
    cout << "line 大小:" << obj.getLength() << endl;
}

// 程序的主函数
int main()
{
    Line line(10);
    display(line);

    return 0;
}