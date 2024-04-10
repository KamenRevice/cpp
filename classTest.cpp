/*
 * @Description: 类学习
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2023-07-18 15:50:50
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-10 14:41:02
 */

#include <iostream>

using namespace std;

class Box
{
public:
    double length;
    double breadth;
    double height;

    double get(void);
    void set(double len, double bre, double hei);
};

// 成员函数定义
double Box::get(void)
{
    return length * breadth * height;
}

void Box::set(double len, double bre, double hei)
{
    length = len;
    breadth = bre;
    height = hei;
}

int main()
{
    Box Box1;
    Box Box2;
    double volume = 0.0;

    Box1.length = 2.0;
    Box1.breadth = 3.0;
    Box1.height = 4.0;

    Box2.set(4.0, 6.0, 8);

    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Box1的体积：" << volume << endl;

    volume = Box2.get();
    cout << "Box2的体积：" << volume << endl;

    return 0;
}