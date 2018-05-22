# 多边形对象组合
设计一个多边形类Polygon，包含n个顶点，实现在二维平面中通过移动每个顶点实现移动整个多边形，要求如下：  
(1)多边形的顶点也封装为类，包含x和y坐标，用构造函数进行初始化，用Move成员函数进行位置移动，根据需要设计其他成员函数；  
(2)多边形通过构造函数进行初始化，顶点个数由参数传递，然后动态创建顶点对象，顶点不要用固定长度的数组保存；  
(3)在多边形的析构函数中删除和释放顶点对象；  
(4)在多边形类中设置Move成员函数，实现位置的整体移动，并输出各个顶点的新位置；  
(5)为多边形类设计InsertPoint和RemovePoint成员函数，动态增加或删除顶点，并输出更改后的顶点列表；  
(6)设计main函数和测试数据验证上述功能，可以尝试在网上查阅C++的画线函数，实现多边形的图形化输出。