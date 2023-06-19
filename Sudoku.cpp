#include "Sudoku.hpp"

Sudoku::Sudoku()
{
    InitWindow(WINDOWWIDTH,WINDOWHEIGHT,"Sudoku Solver");
    board = createBoard();
}

Sudoku::~Sudoku()
{
    CloseWindow();
}

std::vector<std::vector<std::shared_ptr<Square>>> Sudoku::createBoard()
{
    std::vector<std::vector<std::shared_ptr<Square>>> board;
    std::vector<std::shared_ptr<Square>> row;

    int gap = WINDOWWIDTH/9;
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            row.emplace_back(std::make_shared<Square>(i,j,gap));
        }
        board.emplace_back(std::move(row));
    }
    return board;
}

void Sudoku::drawGrid()
{
    int gap = WINDOWWIDTH/9;
    for (int i=0; i<9; i++) {
        DrawLine(0, (i*gap), WINDOWWIDTH, (i*gap), GRAY);
        DrawLine((i*gap), 0, (i*gap), WINDOWWIDTH, GRAY);
    }
    for (int i=3; i<9; i+=3) {
        DrawLineEx((Vector2){0,(i*gap)},(Vector2){WINDOWWIDTH,(i*gap)},3.0,BLACK);
        DrawLineEx((Vector2){(i*gap),0},(Vector2){(i*gap),WINDOWWIDTH},3.0,BLACK);
    }
}

bool Sudoku::checkValid(int r, int c, std::string& s)
{
    for (int i=0; i<9; i++) {
        if (board[r][i]->number==s) return false;
    }
    for (int i=0; i<9; i++) {
        if (board[i][c]->number==s) return false;
    }
    int boxRow = r-r%3;
    int boxCol = c-c%3;
    for (int i=boxRow; i<boxRow+3; i++) {
        for (int j=boxCol; j<boxCol+3; j++) {
            if (board[i][j]->number==s) return false;
        }
    }
    return true;
}

bool Sudoku::solve()
{
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            if (board[i][j]->number=="_") {
                for (int k=1; k<=9; k++) {
                    std::string s = std::to_string(k);
                    if (checkValid(i,j,s)) {
                        board[i][j]->number=s;
                        if (solve()) return true;
                        else board[i][j]->number="_";
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void Sudoku::drawBoard()
{
    ClearBackground(WHITE);
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            board[i][j]->draw();
        }
    }
    drawGrid();
}

void Sudoku::begin()
{
    Vector2 mousepos;
    Vector2 xy;
    std::shared_ptr<Square> ptr=nullptr;
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        drawBoard();
        EndDrawing();

        if (ptr) {
            std::string s = takeInput();
            if (s!="0" && checkValid(xy.y,xy.x,s)) {
                ptr->updateNumber(s);
                ptr->color=WHITE;
                ptr=nullptr;
            } 
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !ptr) {
            mousepos=GetMousePosition();
            correctBound(mousepos,WINDOWWIDTH,WINDOWHEIGHT);
            xy = getClicked(mousepos,9,WINDOWWIDTH);
            board[xy.y][xy.x]->color=YELLOW;
            ptr = board[xy.y][xy.x];
        }

        if (IsKeyPressed(KEY_SPACE)) {
            if (solve()) std::cout << "Done" << std::endl;
            else std::cout << "Unsolvable" << std::endl;
        }
    }
}