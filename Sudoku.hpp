#ifndef Sudoku_hpp
#define Sudoku_hpp
#include <vector>
#include <memory>
#include "userInput.hpp"
#define WINDOWWIDTH 900
#define WINDOWHEIGHT 900

class Sudoku
{
private:
    std::vector<std::vector<std::shared_ptr<Square>>> board;
    std::vector<std::vector<std::shared_ptr<Square>>> createBoard();
    void drawGrid();
    bool checkValid(int r, int c, std::string& s);
    bool solve();
public:
    Sudoku();
    ~Sudoku();
    void drawBoard();
    void begin();
};

#endif