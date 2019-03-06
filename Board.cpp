#include "Board.h"
#include <iostream>
#include <iomanip>
using namespace std;

Board::Board()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            board[i][j]='.';
        }
    }
}

void Board::printboard()
{
    int i,j;
    for(int i=-2;i<0;i++)
    {
        for(j=-2;j<20;j++)
        {
            if(i==-2) //print the coordinate numbers on the screen
            {
                if(j<10)
                cout<<" ";
                else
                {
                    cout<<1;
                }

            }
            if(i==-1) //print the coordinate numbers on the screen
            {
                if(j<0)
                cout<<" ";
                else
                {
                   cout<<j%10;
                }
            }
        }
        cout<<endl;
    }
    for(i=0;i<20;i++)
    {
        cout<<setw(2)<<i;
        for(j=0;j<20;j++) //print the board on the game
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

