/**
 * 关于Polygon类的具体文档请参阅cpp中的内容
 * @headerfile
 * @see Polygon.cpp
 */
#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Point.h"

using namespace std;

class Polygon {
public:

    Polygon(int=0);

    static Polygon *FromConsole();

    void Move(double, double);

    void MoveFromConsole();

    void InsertPoint(double, double);

    void InsertPoint(Point *);

    void InsertPointFromConsole();

    void DeletePoint(double, double);

    void DeletePoint(Point *);

    void DeletePoint(int);

    void DeletePointFromConsole();

    int Count();

    void Print();

    ~Polygon();

private:
    int count;
    vector<Point> points;
};

#endif
