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
    vector<int> demo{1, 3, 3, 4, 5, 3};
    auto iter = std::remove(demo.begin(), demo.end(), 3);

    demo.erase(iter, demo.end());

    cout << "size is: " << demo.size() << endl;
    cout << "capacity is: " << demo.capacity() << endl;

    for (auto first = demo.begin(); first < iter; first++)
    {
        cout << *first << " ";
    }
    cout << endl;
    for (auto &&i : demo)
    {
        cout << i << " ";
    }
    return 0;
}
