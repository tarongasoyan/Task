#include <iostream>

class Rectangle
{
public:
    virtual void draw() = 0;
};

class LegRectangle
{
public:
    LegRectangle(int x1, int x2, int y1, int y2) {
        _x1 = x1;
        _x2 = x2;
        _y1 = y1;
        _y2 = y2;
        std::cout << "LegRectangle" << std::endl; 
    }
    void oldDraw() {
        std::cout << "Old Draw" << std::endl;
    }
private:
    int _x1;
    int _x2;
    int _y1;
    int _y2;
};

class RectangleAdapter:public Rectangle, public LegRectangle
{
public:
    RectangleAdapter(int x, int y, int a, int b):
        LegRectangle(x, y, x + a, y + b) {
            std::cout << "RectangleAdapter" << std::endl;
        }
    void draw() {
        std::cout << "Rectangle adapter(draw())" << std::endl;
        oldDraw();
    }
};

int main() {
    int x = 10;
    int y = 20;
    int a = 100;
    int b = 200;
    Rectangle* ptr = new RectangleAdapter(x, y, a, b);
    ptr->draw();

    return 0; 
}
