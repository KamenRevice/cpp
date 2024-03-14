#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <deque>
#include <list>

using namespace std;

class testDemo
{
public:
    testDemo(int num) : num(num)
    {
        std::cout << "调用构造函数" << std::endl;
    }

    testDemo(const testDemo &other) : num(other.num)
    {
        std::cout << "调用拷贝构造函数" << std::endl;
    }

    testDemo(testDemo &&other) : num(other.num)
    {
        std::cout << "调用移动构造函数" << std::endl;
    }

private:
    int num;
};

int main()
{
    list<int> mylist1{1, 2, 3, 4}, mylist2{10, 20, 30};
    list<int>::iterator it = ++mylist1.begin();
    mylist1.splice(it, mylist2);
    mylist2.splice(mylist2.begin(), mylist1, it);
    // mylist2.splice(mylist2.begin(), mylist1, mylist1.begin(), mylist1.end());
    cout << "mylist1 包含" << mylist1.size() << "个元素：";
    cout << "mylist2 包含" << mylist2.size() << "个元素：";
    cout << "mylist2:";
    for (auto it = mylist2.begin(); it != mylist2.end(); ++it)
        cout << *it << " ";
    return 0;
}
