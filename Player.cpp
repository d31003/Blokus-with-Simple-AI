#include "Player.h"
#include "Board.h"
#include "Piece_set.h"
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

int Player::check1(int row, int column, Board board)//check first round
{
    int i, j;
    
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(player_piece_set.pieces[current_piece]->piece_dir[current_dir].Piece_array[i][j]==1)//we only care 1
            {
                if(row-2+i<0||row-2+i>19)//piece should in the board
                    return 0;
                if(column-2+j<0||column-2+j>19)
                    return 0;
            }
        }
    }
    return 1;
}

int Player::check(int row, int column, Board board)
{
    int i, j, corner=0;
    
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(player_piece_set.pieces[current_piece]->piece_dir[current_dir].Piece_array[i][j]==1)//we only care 1
            {
                if(row-2+i<0||row-2+i>19)//piece should in the board
                    return 0;
                if(column-2+j<0||column-2+j>19)
                    return 0;
                if(board.board[row-2+i][column-2+j]=='.')
                {
                    if(corner==0)//check current chess contact same color chess at point
                    {
                        if(board.board[row-3+i][column-3+j]==player_alphabet&&row-3+i>=0&&row-3+i<20&&column-3+j>=0&&column-3+j<20)
                        {
                            corner=1;
                        }
                        if(board.board[row-3+i][column-1+j]==player_alphabet&&row-3+i>=0&&row-3+i<20&&column-1+j>=0&&column-1+j<20)
                        {
                            corner=1;
                        }
                        if(board.board[row-1+i][column-3+j]==player_alphabet&&row-1+i>=0&&row-1+i<20&&column-3+j>=0&&column-3+j<20)
                        {
                            corner=1;
                        }
                        if(board.board[row-1+i][column-1+j]==player_alphabet&&row-1+i>=0&&row-1+i<20&&column-1+j>=0&&column-1+j<20)
                        {
                            corner=1;
                        }
                    }
                    if(board.board[row-3+i][column-2+j]==player_alphabet&&row-3+i>=0&&row-3+i<20&&column-2+j>=0&&column-2+j<20)//current chess can't contact same color chess at side
                    {
                        return 0;
                    }
                    if(board.board[row-1+i][column-2+j]==player_alphabet&&row-1+i>=0&&row-1+i<20&&column-2+j>=0&&column-2+j<20)
                    {
                        return 0;
                    }
                    if(board.board[row-2+i][column-3+j]==player_alphabet&&row-2+i>=0&&row-2+i<20&&column-3+j>=0&&column-3+j<20)
                    {
                        return 0;
                    }
                    if(board.board[row-2+i][column-1+j]==player_alphabet&&row-2+i>=0&&row-2+i<20&&column-1+j>=0&&column-1+j<20)
                    {
                        return 0;
                    }
                }
                else
                    return 0;
            }
        }
    }
    if(corner==1)//chess can be put here
        return 1;
    else//chess can't be put
        return 0;
}

int Player::precheck(Board board)
{
    int i, j, t, k;
    
    for(k=0;k<21;k++)//check whether chess is viable when the new round start
    {
        if(player_piece_set.remain[k]==1)
        {
            current_piece=k;
            for(t=0;t<player_piece_set.pieces[k]->type_num;t++)
            {
                current_dir=t;
                player_piece_set.viable[k]=0;
                for(i=0;i<20;i++)
                {
                    for(j=0;j<20;j++)
                    {
                        if(check(i, j, board)==1)//if there exists a position, chess is viable
                            player_piece_set.viable[k]=1;
                        if(player_piece_set.viable[k]==1)
                            break;
                    }
                    if(player_piece_set.viable[k]==1)
                        break;
                }
                if(player_piece_set.viable[k]==1)
                    break;
            }
        }
    }
    
    for(i=0;i<21;i++)
    {
        if(player_piece_set.viable[i]==1)//if exists at least one chess viable, player can play
            return 1;
    }
    
    return 0;
}

void Player::calculate()
{
    int i;
    
    for(i=0;i<21;i++)//when player can't play, calculate player's remain pieces
    {
        if(player_piece_set.remain[i]==1)
            score-=player_piece_set.pieces[i]->size;
    }
}

void Player::putchess(int row, int column, Board &board)
{
    int i, j;
    

        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)//paste the chess on the board
            {
                if(player_piece_set.pieces[current_piece]->piece_dir[current_dir].Piece_array[i][j]==1)
                {
                    board.board[row-2+i][column-2+j]=player_alphabet;
                }
            }
        }
    player_piece_set.remain[current_piece]=0;
    player_piece_set.viable[current_piece]=0;
    
}

void Player::init_set()
{
    player_piece_set.initial_piece();
}

