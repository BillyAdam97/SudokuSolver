#ifndef Square_hpp
#define Square_hpp
#include <raylib.h>
#include <string>

class Square
{
private:
    int x;
    int y;
    int width;
    int height;
public:
    std::string number;
    Color color;
    Square(int row, int col, int _width);
    ~Square();
    void draw();
    void updateNumber(std::string newNumber);
};

#endif