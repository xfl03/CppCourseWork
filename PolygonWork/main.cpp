#include <iostream>
#include "Point.h"
#include "Polygon.h"

using namespace std;
/**
 * 程序主入口
 * @return 程序状态值，0 - 正常退出
 */
int main() {
    //从控制台读取顶点数量和具体值，创建一个多边形对象
    Polygon *polygon = Polygon::FromConsole();
    //输出这一对象的所有顶点
    polygon->Print();
    //从控制台输入dx dy，并进行移动、输出
    polygon->MoveFromConsole();
    //从控制台读入一个点，增加这一个点后输出
    polygon->InsertPointFromConsole();
    //从控制台读入一个点，删除这一个点后进行输出
    polygon->DeletePointFromConsole();
    //优雅结束程序
    return 0;
}
