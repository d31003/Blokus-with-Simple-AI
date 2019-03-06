#ifndef Player_h
#define Player_h
#include <string>
#include <iostream>
#include "Piece_set.h"
#include "Board.h"
using namespace std;



class Player
{
public:
    string name="boham";
    int order_num=0, score=0, current_piece=0, current_dir=0;
    char player_alphabet='O';
    bool AI=0;
    Piece_set player_piece_set;
    
    int check1(int, int, Board);
    int check(int, int, Board);
    int precheck(Board);
    void calculate();
    void putchess(int, int, Board &);
    void init_set();
};

#endif
