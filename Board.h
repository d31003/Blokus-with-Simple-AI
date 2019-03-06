#ifndef BOARD_H
#define BOARD_H
#include<iostream>
using namespace std;

class Board
{
    public:
    Board();
    char board[20][20];
    void printboard(); //print the board on the screen
};
#endif
