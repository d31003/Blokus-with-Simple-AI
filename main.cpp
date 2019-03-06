#include<iostream>
#include<string>
#include<cstdlib>
#include "Board.h"
#include "Player.h"
#include "Piece.h"
#include "Piece_set.h"
#include <iomanip>
#include <ctime>
using namespace std;

void print_pieceArray(Piece* pin, int dir_, int i)
{

        for(int j = 1; j<=5; j++)
        {
            if(i==3&&j==3)
                cout<<'@';
            else
            {
                int c =pin->piece_dir[dir_].Piece_array[i-1][j-1];
                (c==1?cout<<"*":cout<<' ');
            }
        }
        cout<<' ';

}

int main()
{
    Board board;
    /*for(int am=2;am<18;am++)  debug purpose
    {
        for(int pm=1;pm<16;pm++)
        {
            board.board[am][pm]='B';
        }
    }*/

    Player P[5];
    int i, t, w, row, column, last[5]={0}, rank[5]={0}, playernum, canput;
    P[1].player_alphabet='A';
    P[2].player_alphabet='B';
    P[3].player_alphabet='C';
    P[4].player_alphabet='D';
    
    do{
        cout<<"please enter number of players(0~4):";
        cin>>playernum;
        if(playernum>=0&&playernum<=4)
            break;
    }while(1);
        
    for(i=1;i<=playernum;i++)
    {
        cout<<"Please enter player "<<i<<"'s name:";
        cin>>P[i].name;
    }
    
    if(playernum==0)
    {
        P[1].name="AI1";
        P[1].AI=1;
        P[2].name="AI2";
        P[2].AI=1;
        P[3].name="AI3";
        P[3].AI=1;
        P[4].name="AI4";
        P[4].AI=1;
    }
    if(playernum==1)
    {
        P[2].name="AI1";
        P[2].AI=1;
        P[3].name="AI2";
        P[3].AI=1;
        P[4].name="AI3";
        P[4].AI=1;
    }
    if(playernum==2)
    {
        P[3].name="AI1";
        P[3].AI=1;
        P[4].name="AI2";
        P[4].AI=1;
    }
    if(playernum==3)
    {
        P[4].name="AI1";
        P[4].AI=1;
    }
    

    P[1].init_set();
    P[2].init_set();
    P[3].init_set();
    P[4].init_set();

    system("PAUSE");
    system("cls");

    srand(time(NULL));
    for(i=1;i<5;i++) // turn 1
    {
        if(P[i].AI==1)//AI
        {
            int randpiece;
            
            
            randpiece=rand()%9+9;
            if(randpiece==14)
                randpiece=18;
            if(randpiece==17)
                randpiece=20;
            
            P[i].current_piece=randpiece;
            do{
                P[i].current_dir=rand()%(P[i].player_piece_set.pieces[P[i].current_piece]->type_num);
                canput=0;
                for(row=0;row<20;row++)
                {
                    for(column=0;column<20;column++)
                    {
                        if(P[i].check1(row,column,board)==1)
                        {
                            if(i==1)
                            {
                                if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[2-row][2-column]==1&&2-row>=0&&2-row<5&&2-column>=0&&2-column<5)
                                {
                                    canput=1;
                                }
                            }
                            else if(i==2)
                            {
                                if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[2-row][21-column]==1&&2-row>=0&&2-row<5&&21-column>=0&&21-column<5)
                                {
                                    canput=1;
                                }
                            }
                            else if(i==3)
                            {
                                if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[21-row][21-column]==1&&21-row>=0&&21-row<5&&21-column>=0&&21-column<5)
                                {
                                    canput=1;
                                }
                            }
                            else if(i==4)
                            {
                                if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[21-row][2-column]==1&&21-row>=0&&21-row<5&&2-column>=0&&2-column<5)
                                {
                                    canput=1;
                                }
                            }
                        }
                        if(canput==1)
                            break;
                    }
                    if(canput==1)
                        break;
                }
                
                if(canput==1)
                {
                    P[i].putchess(row,column,board);
                    break;
                }
                
            }while(1);
            
            board.printboard();
            system("PAUSE");
            system("cls");
            continue;
            
        }
        cout<<P[i].name<<"'s turn! (the first piece has to be on the \nP1:upper-left, P2:upper-right, P3:lower-right, P4:lower-left corner)\n";
        do{
            board.printboard();
            P[i].player_piece_set.printremain();
            do{
                cin>>P[i].current_piece;
                if(P[i].current_piece>=0&&P[i].current_piece<21)
                {
                    break;
                }
                cout<<"This is not a piece!\n";
            }while(1);

            if( P[i].player_piece_set.viable[P[i].current_piece]==1)
            {
                cout<<"Please choose a direction.\n";
                for(int k=0;k<P[i].player_piece_set.pieces[P[i].current_piece]->type_num;k++)
                    cout<<left<<setw(6)<<k;cout<<right;cout<<right;
                cout<<endl;
                for(int k=1;k<=5;k++)
                {
                for(t=0;t<P[i].player_piece_set.pieces[P[i].current_piece]->type_num;t++)
                {
                    print_pieceArray(P[i].player_piece_set.pieces[P[i].current_piece],t, k);
                }
                    cout<<endl;
                }
                cin>>P[i].current_dir;
                if(P[i].current_dir>=0 && P[i].current_dir<P[i].player_piece_set.pieces[P[i].current_piece]->type_num )
                {
                    cout<<"Please enter row, column.";
                    cin>>row>>column;
                    if(P[i].check1(row,column,board)==1)
                    {
                        if(i==1)
                        {
                            if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[2-row][2-column]==1&&2-row>=0&&2-row<5&&2-column>=0&&2-column<5)
                            {
                                P[i].putchess(row,column,board);
                                system("cls");
                                break;
                            }
                        }
                        else if(i==2)
                        {
                            if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[2-row][21-column]==1&&2-row>=0&&2-row<5&&21-column>=0&&21-column<5)
                            {
                                P[i].putchess(row,column,board);
                                system("cls");
                                break;
                            }
                        }
                        else if(i==3)
                        {
                            if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[21-row][21-column]==1&&21-row>=0&&21-row<5&&21-column>=0&&21-column<5)
                            {
                                P[i].putchess(row,column,board);
                                system("cls");
                                break;
                            }
                        }
                        else if(i==4)
                        {
                            if(P[i].player_piece_set.pieces[P[i].current_piece]->piece_dir[P[i].current_dir].Piece_array[21-row][2-column]==1&&21-row>=0&&21-row<5&&2-column>=0&&2-column<5)
                            {
                                P[i].putchess(row,column,board);
                                system("cls");
                                break;
                            }
                        }
                    }
                }
            }
            cout<<"Invalid input!\n";
            system("PAUSE");
            system("cls");
            cout<<P[i].name<<" please enter again.\n";
        }while(1);
    }

    for(w=2;w<21;w++) // turn 2-20
    {
        for(i=1;i<5;i++)
        {
            if(P[i].AI==1)//AI
            {
                int randpiece, test, x;
                
                if(P[i].precheck(board)==0)
                {
                    cout<<P[i].name<<" no more moves!\n";
                    system("PAUSE");
                    system("cls");
                    continue;
                }
                
                test=0;
                for(x=9;x<=20;x++)
                {
                    if(P[i].player_piece_set.viable[x]==1)
                    {
                        test=1;
                        break;
                    }
                }
                if(test==1)
                {
                    do{
                        randpiece=rand()%12+9;
                        if(P[i].player_piece_set.viable[randpiece]==1)
                            break;
                    }while(1);
                }
                else
                {
                    for(x=4;x<=8;x++)
                    {
                        if(P[i].player_piece_set.viable[x]==1)
                        {
                            test=1;
                            break;
                        }
                    }
                    if(test==1)
                    {
                        do{
                            randpiece=rand()%5+4;
                            if(P[i].player_piece_set.viable[randpiece]==1)
                                break;
                        }while(1);
                    }
                    else
                    {
                        for(x=2;x<=3;x++)
                        {
                            if(P[i].player_piece_set.viable[x]==1)
                            {
                                test=1;
                                break;
                            }
                        }
                        if(test==1)
                        {
                            do{
                                randpiece=rand()%2+2;
                                if(P[i].player_piece_set.viable[randpiece]==1)
                                    break;
                            }while(1);
                        }
                        else
                        {
                            if(P[i].player_piece_set.viable[1]==1)
                            {
                                test=1;
                            }
                            if(test==1)
                            {
                                randpiece=1;
                            }
                            else
                                randpiece=0;
                            
                        }
                    }
                }
                
                P[i].current_piece=randpiece;
                do{
                    P[i].current_dir=rand()%(P[i].player_piece_set.pieces[P[i].current_piece]->type_num);
                    canput=0;
                    for(row=0;row<20;row++)
                    {
                        for(column=0;column<20;column++)
                        {
                            if(P[i].check(row,column,board)==1)
                            {
                                canput=1;
                            }
                            if(canput==1)
                                break;
                        }
                        if(canput==1)
                            break;
                    }
                    
                    if(canput==1)
                    {
                        P[i].putchess(row,column,board);
                        break;
                    }
                    
                }while(1);
                
                board.printboard();
                system("PAUSE");
                system("cls");
                continue;
                
            }
            
            cout<<P[i].name<<"'s turn!\n";
            if(P[i].precheck(board)==0)
            {
                cout<<"No more moves!\n";
                system("PAUSE");
                system("cls");
            }
            else{
            do{
                board.printboard();
                P[i].player_piece_set.printviable();
                P[i].player_piece_set.printremainbutnotviable();
                do{
                cin>>P[i].current_piece;
                if(P[i].current_piece>=0&&P[i].current_piece<21)
                {
                    break;
                }
                cout<<"This is not a piece!\n";
                }while(1);
                if( P[i].player_piece_set.viable[P[i].current_piece]==1)
                {
                    cout<<"Please choose a direction.\n";
                    for(int k=0;k<P[i].player_piece_set.pieces[P[i].current_piece]->type_num;k++)
                        cout<<left<<setw(6)<<k;cout<<right;
                    cout<<endl;
                    for(int k=1;k<=5;k++)
                    {
                        for(t=0;t<P[i].player_piece_set.pieces[P[i].current_piece]->type_num;t++)
                        {
                            print_pieceArray(P[i].player_piece_set.pieces[P[i].current_piece],t, k);
                        }
                        cout<<endl;
                    }
                    cin>>P[i].current_dir;
                    if(P[i].current_dir>=0 && P[i].current_dir<P[i].player_piece_set.pieces[P[i].current_piece]->type_num )
                    {
                        cout<<"Please enter row, column.";
                        cin>>row>>column;
                        if(P[i].check(row,column,board)==1) // to be changed
                        {

                        	P[i].putchess(row,column,board);
                            system("cls");
                            break;

                        }
                    }
                }
                cout<<"Invalid input!\n";
            system("PAUSE");
            system("cls");
            cout<<P[i].name<<" please enter again.\n";
            }while(1);
        }
        }
    }

    for(i=1;i<5;i++) //turn 21
    {
        if(P[i].AI==1)//AI
        {
            int randpiece, test, x;
            
            if(P[i].precheck(board)==0)
            {
                cout<<P[i].name<<" no more moves!\n";
                system("PAUSE");
                system("cls");
                continue;
            }
            
            test=0;
            for(x=9;x<=20;x++)
            {
                if(P[i].player_piece_set.viable[x]==1)
                {
                    test=1;
                    break;
                }
            }
            if(test==1)
            {
                do{
                    randpiece=rand()%12+9;
                    if(P[i].player_piece_set.viable[randpiece]==1)
                        break;
                }while(1);
            }
            else
            {
                for(x=4;x<=8;x++)
                {
                    if(P[i].player_piece_set.viable[x]==1)
                    {
                        test=1;
                        break;
                    }
                }
                if(test==1)
                {
                    do{
                        randpiece=rand()%5+4;
                        if(P[i].player_piece_set.viable[randpiece]==1)
                            break;
                    }while(1);
                }
                else
                {
                    for(x=2;x<=3;x++)
                    {
                        if(P[i].player_piece_set.viable[x]==1)
                        {
                            test=1;
                            break;
                        }
                    }
                    if(test==1)
                    {
                        do{
                            randpiece=rand()%2+2;
                            if(P[i].player_piece_set.viable[randpiece]==1)
                                break;
                        }while(1);
                    }
                    else
                    {
                        if(P[i].player_piece_set.viable[1]==1)
                        {
                            test=1;
                        }
                        if(test==1)
                        {
                            randpiece=1;
                        }
                        else
                            randpiece=0;
                        
                    }
                }
            }
            
            P[i].current_piece=randpiece;
            if(P[i].current_piece==0) //special rule: if piece one is the last piece, +5 points
            {
                last[i]=1;
            }
            else
            {
                last[i]=0;
            }
            do{
                P[i].current_dir=rand()%(P[i].player_piece_set.pieces[P[i].current_piece]->type_num);
                canput=0;
                for(row=0;row<20;row++)
                {
                    for(column=0;column<20;column++)
                    {
                        if(P[i].check(row,column,board)==1)
                        {
                            canput=1;
                        }
                        if(canput==1)
                            break;
                    }
                    if(canput==1)
                        break;
                }
                
                if(canput==1)
                {
                    P[i].putchess(row,column,board);
                    break;
                }
                
            }while(1);
            
            board.printboard();
            system("PAUSE");
            system("cls");
            continue;
            
        }
        
        cout<<P[i].name<<"'s turn!\n";
        if(P[i].precheck(board)==0)
        {
            cout<<"No more moves!\n";
            system("PAUSE");
            system("cls");
        }
        else
        {do{
            board.printboard();
            P[i].player_piece_set.printviable();
            P[i].player_piece_set.printremainbutnotviable();
            do{
                cin>>P[i].current_piece;
                if(P[i].current_piece>=0&&P[i].current_piece<21)
                {
                    break;
                }
                cout<<"This is not a piece!\n";
            }while(1);
            if(P[i].current_piece==0) //special rule: if piece one is the last piece, +5 points
            {
                last[i]=1;
            }
            else
            {
                last[i]=0;
            }
            if( P[i].player_piece_set.viable[P[i].current_piece]==1)
            {
                cout<<"Please choose a direction.\n";
                for(int k=0;k<P[i].player_piece_set.pieces[P[i].current_piece]->type_num;k++)
                    cout<<left<<setw(6)<<k;cout<<right;
                cout<<endl;
                for(int k=1;k<=5;k++)
                {
                    for(t=0;t<P[i].player_piece_set.pieces[P[i].current_piece]->type_num;t++)
                    {
                        print_pieceArray(P[i].player_piece_set.pieces[P[i].current_piece],t, k);
                    }
                    cout<<endl;
                }
                cin>>P[i].current_dir;
                if(P[i].current_dir>=0 && P[i].current_dir<P[i].player_piece_set.pieces[P[i].current_piece]->type_num )
                {
                    cout<<"Please enter row, column.";
                    cin>>row>>column;
                    if(P[i].check(row,column,board)==1) // to be changed
                    {
                		P[i].putchess(row,column,board);
                    	system("cls");
                        break;
                    }
                }
            }
            cout<<"Invalid input!\n";
            system("PAUSE");
            system("cls");
            cout<<P[i].name<<" please enter again.\n";
        }while(1);
        }
    }
    board.printboard();
    cout<<endl;
    for(i=1;i<=4;i++)
    {
        cout<<P[i].name<<" remain:\n";
        P[i].player_piece_set.printremain();
    }
    
    cout<<"\n";
    for(w=1;w<5;w++)
    {
        P[w].calculate();
        if(last[w]==1)
        {
            P[w].score=P[w].score+5;
        }
        cout<<P[w].name<<": "<<P[w].score<<"points.\n";
    }

    int a,b, score[5]={0};
    for(i=1;i<5;i++)
    {
        score[i]=P[i].score;
    }
    for(w=1;w<5;w++)
    {
        a=-1000;
        b=-1000;
        for(i=1;i<5;i++)
        {
            if(a<score[i])
            {
                a=score[i];
                b=i;
            }
        }
        rank[w]=b;
        score[b]=-20000;
    }


    cout<<"\n\tRanking: \n";
    for(i=1;i<5;i++)
    {
        int a;
        a=i;
        cout<<i<<". "<<P[rank[a]].name<<endl;
        for(int j=a+1;j<=4;j++)
        {
            if(P[rank[j]].score==P[rank[a]].score)
            {
                cout<<a<<". "<<P[rank[j]].name<<endl;
                i++;
            }
            
        }
        
    }

    return 0;
}
