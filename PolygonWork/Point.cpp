#include "Point.h"

#include <iostream>

using namespace std;

/**
 * 以给定的坐标创建Point对象
 * @param x - X坐标
 * @param y - Y坐标
 */
Point::Point(double x, double y) : x(x), y(y) {}

/**
 * 从控制台中获取一个点的坐标，并动态创建这个点
 * @return 通过这一过程创建的点
 */
Point *Point::FromConsole() {
    double x = 0, y = 0;
    //输入数据
    cout << "Input Point with 'x y': ";
    cin >> x >> y;
    //创建并返回
    return new Point(x, y);
}

/**
 * 在X、Y两个方向上移动点
 * @param dx - X方向上的移动值
 * @param dy - Y方向上的移动值
 */
void Point::Move(double dx, double dy) {
    x += dx;
    y += dy;
}

/**
 * 获得X坐标
 * @return 点的X坐标
 */
double Point::GetX() const {
    return x;
}

/**
 * 获得Y坐标
 * @return 点的Y坐标
 */
double Point::GetY() const {
    return y;
}

/**
 * 输出点的坐标
 * @note 格式为 (x,y)
 */
void Point::Print() const {
    cout << "(" << x << "," << y << ")" << endl;
}

/**
 * 判断另一个点与当前点是否相等
 * @param p - 另一个点
 * @return 另一个点与当前点的坐标是否一致
 * @note 仅比较坐标，不比较对象
 */
bool Point::operator==(const Point p) {
    return p.x == x && p.y == y;
}
