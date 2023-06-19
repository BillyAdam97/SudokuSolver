#ifndef userInput_hpp
#define userInput_hpp
#include <raylib.h>
#include <memory>
#include <string>
#include <iostream>
#include "Square.hpp"

void correctBound(Vector2& mousepos, int width, int height);
Vector2 getClicked(Vector2 mousepos, int rows, int width);
std::string takeInput();

#endif