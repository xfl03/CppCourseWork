/**
 * 关于Point类的具体文档请参阅cpp中的内容
 * @headerfile
 * @see Point.cpp
 */
#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double= 0, double= 0);

    static Point *FromConsole();

    void Move(double, double);

    double GetX() const;

    double GetY() const;

    void Print() const;

    bool operator==(Point);

private:
    double x;
    double y;
};

#endif
