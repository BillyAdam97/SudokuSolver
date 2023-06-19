#include "Square.hpp"

Square::Square(int row, int col, int _width)
: width(_width), height(_width), number("_")
{
    x=row*width;
    y=col*width;
    color=WHITE;
}

Square::~Square()
{}

void Square::draw()
{
    DrawRectangle(x,y,width,height,color);
    DrawText(number.c_str(),x+(width/2),y+(height/2),28,BLACK);
}

void Square::updateNumber(std::string newNumber)
{
    number = newNumber;
}