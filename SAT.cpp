/*
 * @Description:分离轴定理SAT ，用于检测两个凸多边形是否相交
 * @Version: 0.1
 * @Autor: kaiju
 * @Date: 2024-04-12 15:04:40
 * @LastEditors: kaiju
 * @LastEditTime: 2024-04-12 15:15:02
 */

#include <iostream>  
#include <cmath> 
#include <algorithm>

using namespace std;
// 定义点结构  
struct Point {
    double x;
    double y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

// 定义矩形结构，包含四个顶点的坐标  
struct RotatedRectangle {
    Point topLeft;
    Point topRight;
    Point bottomRight;
    Point bottomLeft;
};

// 计算点p在轴axis上的投影  
double project(const Point& p, const Point& axis) {
    return (p.x * axis.x + p.y * axis.y) / std::sqrt(axis.x * axis.x + axis.y * axis.y);
}

// 检查两个区间是否重叠  
bool doIntervalsOverlap(double min1, double max1, double min2, double max2) {
    return !(max1 < min2 || max2 < min1);
}

// 判断两个旋转矩形是否相交  
bool doRotatedRectanglesIntersect(const RotatedRectangle& rect1, const RotatedRectangle& rect2) {
    // 定义可能的分离轴：矩形的四条边和垂直于边的四条轴  
    Point axes[] = {
        {rect1.topRight.x - rect1.topLeft.x, rect1.topRight.y - rect1.topLeft.y},     // rect1的一条边  
        {rect1.bottomRight.x - rect1.bottomLeft.x, rect1.bottomRight.y - rect1.bottomLeft.y}, // rect1的另一条边  
        {rect2.topRight.x - rect2.topLeft.x, rect2.topRight.y - rect2.topLeft.y},     // rect2的一条边  
        {rect2.bottomRight.x - rect2.bottomLeft.x, rect2.bottomRight.y - rect2.bottomLeft.y}, // rect2的另一条边  
        {-rect1.topRight.y + rect1.topLeft.y, rect1.topRight.x - rect1.topLeft.x},     // 垂直于rect1的一条边  
        {-rect1.bottomRight.y + rect1.bottomLeft.y, rect1.bottomRight.x - rect1.bottomLeft.x}, // 垂直于rect1的另一条边  
        {-rect2.topRight.y + rect2.topLeft.y, rect2.topRight.x - rect2.topLeft.x},     // 垂直于rect2的一条边  
        {-rect2.bottomRight.y + rect2.bottomLeft.y, rect2.bottomRight.x - rect2.bottomLeft.x}  // 垂直于rect2的另一条边  
    };

    // 对于每条轴，计算两个矩形在该轴上的投影，并检查投影是否重叠  
    for (const Point& axis : axes) {
        double min1 = std::min({ project(rect1.topLeft, axis), project(rect1.topRight, axis),project(rect1.bottomRight, axis), project(rect1.bottomLeft, axis) });
        double max1 = std::max({ project(rect1.topLeft, axis), project(rect1.topRight, axis), project(rect1.bottomRight, axis), project(rect1.bottomLeft, axis) });
        double min2 = std::min({ project(rect2.topLeft, axis), project(rect2.topRight, axis), project(rect2.bottomRight, axis), project(rect2.bottomLeft, axis) });
        double max2 = std::max({ project(rect2.topLeft, axis), project(rect2.topRight, axis),project(rect2.bottomRight, axis), project(rect2.bottomLeft, axis) });

        if (!doIntervalsOverlap(min1, max1, min2, max2)) {
            return false; // 如果在某个轴上投影不重叠，则矩形不相交
        }
    }
    return true; // 如果所有轴上的投影都重叠，则矩形相交
}

int main() {
    // 创建两个旋转矩形
    RotatedRectangle rect1{ {0, 0}, {2, 0}, {2, 2}, {0, 2} };
    RotatedRectangle rect2{ {1, 1}, {3, 1}, {3, 3}, {1, 3} };

    // 判断两个矩形是否相交并输出结果
    if (doRotatedRectanglesIntersect(rect1, rect2)) {
        std::cout << "The rectangles intersect." << std::endl;
    }
    else {
        std::cout << "The rectangles do not intersect." << std::endl;
    }

    return 0;
}
