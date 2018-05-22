#include "Polygon.h"

#include <iostream>

using namespace std;

/**
 * 以给定的顶点数量创建多边形
 * @note 点的数据会被请求输入
 * @param count - 多边形顶点数量
 */
Polygon::Polygon(int count) : count(count) {
    //根据顶点数量请求输入点的数据
    for (int i = 0; i < count; i++) {
        cout << "(" << i + 1 << "/" << count << ")";
        Point *p = Point::FromConsole();
        points.push_back(*p);
    }
}

/**
 * 从控制台输入创建一个多边形对象
 * @return 创建的多边形对象
 */
Polygon *Polygon::FromConsole() {
    cout << "Input Point count: ";
    int count;
    cin >> count;
    return new Polygon(count);
}

/**
 * 移动多边形中每一个点，然后输出移动后的所有顶点
 * @param dx - 在X方向移动的值
 * @param dy - 在Y方向移动的值
 */
void Polygon::Move(double dx, double dy) {
    //遍历每个点分别进行移动
    for (auto point:points)
        point.Move(dx, dy);
    Print();
}

/**
 * 从控制台读入X、Y两方向的移动值，并进行移动、输出
 */
void Polygon::MoveFromConsole() {
    double dx = 0, dy = 0;
    //输入
    cout << "Input 'dx dy' to Move: ";
    cin >> dx >> dy;
    //移动并输出
    cout << "After Move: " << endl;
    Move(dx, dy);
}

/**
 * 在顶点列表最后插入点，并输出操作后的顶点列表
 * @see InsertPoint(Point *p)
 * @param x - 被插入点的X坐标
 * @param y - 被插入点的Y坐标
 */
void Polygon::InsertPoint(double x, double y) {
    InsertPoint(new Point(x, y));
}

/**
 * 在顶点列表的最后插入点，并输出操作后的顶点列表
 * @param p - 被插入点的指针
 */
void Polygon::InsertPoint(Point *p) {
    points.push_back(*p);
    count++;
    Print();
}

/**
 * 从控制台中读取点，并插入在顶点列表的最后，然后输出更改后的所有顶点
 */
void Polygon::InsertPointFromConsole() {
    //输入
    cout << "Insert Point: " << endl;
    Point *new_point = Point::FromConsole();
    //插入并输出
    cout << "After Insert Point: " << endl;
    InsertPoint(new_point);
}

/**
 * 移除指定的顶点，并输出操作后的顶点列表
 * @see DeletePoint(Point *p)
 * @param x - 被移除点的X坐标
 * @param y - 被移除点的Y坐标
 */
void Polygon::DeletePoint(double x, double y) {
    DeletePoint(new Point(x, y));
}

/**
 * 移除指定的顶点，并输出操作后的顶点列表
 * @param p - 被移除点的指针
 * @note 只要X、Y值相同，即使指针地址不同，也代表同一个点
 * @note 如果未能找到这一个点，控制台将会输出错误
 */
void Polygon::DeletePoint(Point *p) {
    bool flag = false;//记录是否成功删除
    //使用迭代器对vector进行遍历
    for (auto iter = points.cbegin(); iter != points.cend(); iter++) {
        if (*p == *iter.base()) {
            //如果找到了指定的点
            points.erase(iter);
            count--;
            flag = true;
            break;
        }
    }
    if (!flag)//如果未能找到指定点
        cout << "Target Point not found." << endl;
    Print();
}

/**
 * 移除指定位置的顶点，并输出操作后的顶点列表
 * @param pos - 指定的位置(第pos个顶点) [0,count)
 * @note 如果输入的顶点不在合法的区间内，则会在控制台输出错误
 */
void Polygon::DeletePoint(int pos) {
    auto iter = points.cbegin() + pos;//获得指定位置的迭代器
    if (points.begin() <= iter && iter < points.end()) {
        //如果在合法的区间内，则直接移除
        points.erase(points.cbegin() + pos);
        count--;
    }else{
        //不合法的区间，此时控制台输出错误
        cout << "Target Point not found." << endl;
    }
    Print();
}

/**
 * 从控制台读入一个点，并从顶点列表中删除这个点后进行输出
 */
void Polygon::DeletePointFromConsole() {
    //输入
    cout << "Delete Point: " << endl;
    Point *new_point = Point::FromConsole();
    //删除并输出
    cout << "After Delete Point: " << endl;
    DeletePoint(new_point);
}

/**
 * 获取顶点的数量
 * @return 多边形拥有的顶点数量
 */
int Polygon::Count() {
    return count;
}

/**
 * 输出顶点的数量和具体的坐标
 */
void Polygon::Print() {
    cout << "Polygon has " << count << " points: " << endl;
    for (auto point: points)
        point.Print();
    cout << "----------" << endl;
}

/**
 * 在对象被销毁时，同时销毁存储的顶点
 */
Polygon::~Polygon() {
    //遍历存储的顶点，一一销毁
    for (auto point: points)
        delete &point;
    //最后销毁用于存储顶点的vector
    delete &points;
}
