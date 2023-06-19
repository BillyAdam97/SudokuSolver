#include "userInput.hpp"

void correctBound(Vector2& mousepos, int width, int height)
{
    if (mousepos.y<0) mousepos.y=0;
    if (mousepos.x<0) mousepos.x=0;
    if (mousepos.y>=width) mousepos.y=width-1;
    if (mousepos.x>=height) mousepos.x=height-1;
}

Vector2 getClicked(Vector2 mousepos, int rows, int width)
{
    Vector2 xy;
    int gap = width/rows;
    int y = mousepos.y;
    int x = mousepos.x;
    xy.x = y/gap;
    xy.y = x/gap;
    return xy;
}

std::string takeInput()
{
    int key = GetCharPressed();
    while (key>0) {
        if (key>=49 && key<=57) {
            return std::to_string(key-'0');
        }
        key = GetCharPressed();
    }
    return "0";
}