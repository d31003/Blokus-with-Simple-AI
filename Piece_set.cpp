//Piece_set.cpp
#include "Piece_set.h"
#include "Piece.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


int Piece_set::piece_type[21];
int Piece_set::piece_size[21];
void print_piece_Array(Piece* pin, int dir_)
{
    for(int i = 1; i <= 5; i++)
    {

            for(int j = 1; j<=5; j++)
            {	int c =  pin->piece_dir[dir_].Piece_array[i-1][j-1];
                (c==1?cout<<c:cout<<" ")<<" ";
            }
        cout<<endl;
        }
        cout<<endl;

}

void print_piece_Array7(Piece* pin, int dir_, int i)
{
      for(int j = 1; j<=5; j++)
        {	int c =  pin->piece_dir[dir_].Piece_array[i][j-1];
            (c==1?cout<<'*':cout<<' ');
            //cout<<' ';
        }
        cout<<"   ";


}


//originally, i want:
// 		initial_piece();    in constructor
//but , at that time, the data member pieces[] has not created
//      initial_piece(); after any Piece_set instead

Piece_set::Piece_set()
{
	if(piece_size[0] != 1)
	{
		initial_size();
	}


	if(piece_type[00] != 1)
	{initial_type();
	}

	for(int i = 0 ; i < 21 ; i++)
	{
		viable[i] = true;
		remain[i] = true;
		pieces[i] = new Piece(i, piece_size[i], piece_type[i]);
	}

}

Piece_set::~Piece_set()
{
	for(int i = 0 ; i <21; i++)
	{
		delete pieces[i];
	}
}

void Piece_set::printremain()
{
	//cout<<"Hoho.";
	cout<<"Your piece_set : \n";
	for(int i = 0 ; i < 7; i++)
	{
		if(remain[i] == true)
		{
			cout<<"Piece"<<setw(2)<<i<<" ";
		}

	}
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 0 ; i < 7; i++)
        {
        if(remain[i] == true)
        {
            print_piece_Array7(pieces[i],0, k);
        }
        }
        cout<<endl;
    }

    for(int i = 7 ; i < 14; i++)
    {
        if(remain[i] == true)
        {
            cout<<"Piece"<<setw(2)<<i<<" ";
        }

    }
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 7 ; i < 14; i++)
        {
            if(remain[i] == true)
            {
                print_piece_Array7(pieces[i],0, k);
            }
        }
        cout<<endl;
    }


    for(int i = 14 ; i < 21; i++)
    {
        if(remain[i] == true)
        {
            cout<<"Piece"<<setw(2)<<i<<" ";
        }

    }
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 14 ; i < 21; i++)
        {
            if(remain[i] == true)
            {
                print_piece_Array7(pieces[i],0, k);
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void Piece_set::printremainbutnotviable()
{
	//cout<<"Hoho.";
	cout<<"remain but not viable pieces: \n";
	for(int i = 0 ; i < 7; i++)
	{
		if(remain[i] == true&&viable[i]==0)
		{
			cout<<"Piece"<<setw(2)<<i<<" ";
		}

	}
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 0 ; i < 7; i++)
        {
        if(remain[i] == true&&viable[i]==0)
        {
            print_piece_Array7(pieces[i],0, k);
        }
        }
        cout<<endl;
    }

    for(int i = 7 ; i < 14; i++)
    {
        if(remain[i] == true&&viable[i]==0)
        {
            cout<<"Piece"<<setw(2)<<i<<" ";
        }

    }
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 7 ; i < 14; i++)
        {
            if(remain[i] == true&&viable[i]==0)
            {
                print_piece_Array7(pieces[i],0, k);
            }
        }
        cout<<endl;
    }


    for(int i = 14 ; i < 21; i++)
    {
        if(remain[i] == true&&viable[i]==0)
        {
            cout<<"Piece"<<setw(2)<<i<<" ";
        }

    }
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 14 ; i < 21; i++)
        {
            if(remain[i] == true&&viable[i]==0)
            {
                print_piece_Array7(pieces[i],0, k);
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void Piece_set::printviable()
{
	cout<<"Your viable pieces : \n";
	for(int i = 0 ; i < 7; i++)
	{
		if(viable[i] == true)
		{
			cout<<"Piece"<<setw(2)<<i<<" ";
		}

	}
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 0 ; i < 7; i++)
        {
        if(viable[i] == true)
        {
            print_piece_Array7(pieces[i],0, k);
        }
        }
        cout<<endl;
    }

    for(int i = 7 ; i < 14; i++)
    {
        if(viable[i] == true)
        {
            cout<<"Piece"<<setw(2)<<i<<" ";
        }

    }
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 7 ; i < 14; i++)
        {
            if(viable[i] == true)
            {
                print_piece_Array7(pieces[i],0, k);
            }
        }
        cout<<endl;
    }


    for(int i = 14 ; i < 21; i++)
    {
        if(viable[i] == true)
        {
            cout<<"Piece"<<setw(2)<<i<<" ";
        }

    }
    cout<<endl;
    for(int k=0;k<5;k++)
    {
        for(int i = 14 ; i < 21; i++)
        {
            if(viable[i] == true)
            {
                print_piece_Array7(pieces[i],0, k);
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

////////piece_size record
void Piece_set::initial_size()
{
	Piece_set::piece_size[0]  =  1;
	Piece_set::piece_size[1]  =  2;
	Piece_set::piece_size[2]  =  3;
	Piece_set::piece_size[3]  =  3;
	Piece_set::piece_size[4]  =  4;
	Piece_set::piece_size[5]  =  4;
	Piece_set::piece_size[6]  =  4;
	Piece_set::piece_size[7]  =  4;
	Piece_set::piece_size[8]  =  4;
	Piece_set::piece_size[9]  =  5;
	Piece_set::piece_size[10] =  5;
	Piece_set::piece_size[11] =  5;
	Piece_set::piece_size[12] =  5;
	Piece_set::piece_size[13] =  5;
	Piece_set::piece_size[14] =  5;
	Piece_set::piece_size[15] =  5;
	Piece_set::piece_size[16] =  5;
	Piece_set::piece_size[17] =  5;
	Piece_set::piece_size[18] =  5;
	Piece_set::piece_size[19] =  5;
	Piece_set::piece_size[20] =  5;
}

// piece_type record
void Piece_set::initial_type()
{
	piece_type[00] =   1;
	piece_type[01] =   2;
	piece_type[02] =   4;
	piece_type[03] =   2;
	piece_type[04] =   1;
	piece_type[05] =   4;
	piece_type[06] =   2;
	piece_type[07] =   8;
	piece_type[ 8] =   4;
	piece_type[ 9] =   8;
	piece_type[10] =   4;
	piece_type[11] =   4;
	piece_type[12] =   8;
	piece_type[13] =   4;
	piece_type[14] =   2;
	piece_type[15] =   8;
	piece_type[16] =   4;
	piece_type[17] =   4;
	piece_type[18] =   8;
	piece_type[19] =   1;
	piece_type[20] =   8;
}

void Piece_set::initial_piece()
{
pieces[0]->piece_dir[0].Piece_array[2][2]=1;


pieces[1]->piece_dir[0].Piece_array[2][1]=1;
pieces[1]->piece_dir[0].Piece_array[2][2]=1;

pieces[1]->piece_dir[1].Piece_array[2][2]=1;
pieces[1]->piece_dir[1].Piece_array[1][2]=1;


pieces[2]->piece_dir[0].Piece_array[2][1]=1;
pieces[2]->piece_dir[0].Piece_array[2][2]=1;
pieces[2]->piece_dir[0].Piece_array[3][2]=1;

pieces[2]->piece_dir[1].Piece_array[3][2]=1;
pieces[2]->piece_dir[1].Piece_array[2][2]=1;
pieces[2]->piece_dir[1].Piece_array[2][3]=1;

pieces[2]->piece_dir[2].Piece_array[2][1]=1;
pieces[2]->piece_dir[2].Piece_array[2][2]=1;
pieces[2]->piece_dir[2].Piece_array[1][2]=1;

pieces[2]->piece_dir[3].Piece_array[1][2]=1;
pieces[2]->piece_dir[3].Piece_array[2][2]=1;
pieces[2]->piece_dir[3].Piece_array[2][3]=1;


pieces[3]->piece_dir[0].Piece_array[2][1]=1;
pieces[3]->piece_dir[0].Piece_array[2][2]=1;
pieces[3]->piece_dir[0].Piece_array[2][3]=1;

pieces[3]->piece_dir[1].Piece_array[1][2]=1;
pieces[3]->piece_dir[1].Piece_array[2][2]=1;
pieces[3]->piece_dir[1].Piece_array[3][2]=1;


pieces[4]->piece_dir[0].Piece_array[2][1]=1;
pieces[4]->piece_dir[0].Piece_array[2][2]=1;
pieces[4]->piece_dir[0].Piece_array[3][1]=1;
pieces[4]->piece_dir[0].Piece_array[3][2]=1;


pieces[5]->piece_dir[0].Piece_array[1][2]=1;
pieces[5]->piece_dir[0].Piece_array[2][2]=1;
pieces[5]->piece_dir[0].Piece_array[2][1]=1;
pieces[5]->piece_dir[0].Piece_array[2][3]=1;

pieces[5]->piece_dir[1].Piece_array[3][2]=1;
pieces[5]->piece_dir[1].Piece_array[2][2]=1;
pieces[5]->piece_dir[1].Piece_array[2][1]=1;
pieces[5]->piece_dir[1].Piece_array[2][3]=1;

pieces[5]->piece_dir[2].Piece_array[2][1]=1;
pieces[5]->piece_dir[2].Piece_array[2][2]=1;
pieces[5]->piece_dir[2].Piece_array[1][2]=1;
pieces[5]->piece_dir[2].Piece_array[3][2]=1;

pieces[5]->piece_dir[3].Piece_array[2][3]=1;
pieces[5]->piece_dir[3].Piece_array[2][2]=1;
pieces[5]->piece_dir[3].Piece_array[1][2]=1;
pieces[5]->piece_dir[3].Piece_array[3][2]=1;


pieces[6]->piece_dir[0].Piece_array[2][1]=1;
pieces[6]->piece_dir[0].Piece_array[2][2]=1;
pieces[6]->piece_dir[0].Piece_array[2][3]=1;
pieces[6]->piece_dir[0].Piece_array[2][4]=1;

pieces[6]->piece_dir[1].Piece_array[1][2]=1;
pieces[6]->piece_dir[1].Piece_array[2][2]=1;
pieces[6]->piece_dir[1].Piece_array[3][2]=1;
pieces[6]->piece_dir[1].Piece_array[4][2]=1;


pieces[7]->piece_dir[0].Piece_array[2][1]=1;
pieces[7]->piece_dir[0].Piece_array[2][2]=1;
pieces[7]->piece_dir[0].Piece_array[2][3]=1;
pieces[7]->piece_dir[0].Piece_array[1][3]=1;

pieces[7]->piece_dir[1].Piece_array[2][1]=1;
pieces[7]->piece_dir[1].Piece_array[2][2]=1;
pieces[7]->piece_dir[1].Piece_array[2][3]=1;
pieces[7]->piece_dir[1].Piece_array[3][3]=1;

pieces[7]->piece_dir[2].Piece_array[2][1]=1;
pieces[7]->piece_dir[2].Piece_array[2][2]=1;
pieces[7]->piece_dir[2].Piece_array[2][3]=1;
pieces[7]->piece_dir[2].Piece_array[1][1]=1;

pieces[7]->piece_dir[3].Piece_array[2][1]=1;
pieces[7]->piece_dir[3].Piece_array[2][2]=1;
pieces[7]->piece_dir[3].Piece_array[2][3]=1;
pieces[7]->piece_dir[3].Piece_array[3][1]=1;

pieces[7]->piece_dir[4].Piece_array[1][2]=1;
pieces[7]->piece_dir[4].Piece_array[2][2]=1;
pieces[7]->piece_dir[4].Piece_array[3][2]=1;
pieces[7]->piece_dir[4].Piece_array[1][3]=1;

pieces[7]->piece_dir[5].Piece_array[1][2]=1;
pieces[7]->piece_dir[5].Piece_array[2][2]=1;
pieces[7]->piece_dir[5].Piece_array[3][2]=1;
pieces[7]->piece_dir[5].Piece_array[1][1]=1;

pieces[7]->piece_dir[6].Piece_array[1][2]=1;
pieces[7]->piece_dir[6].Piece_array[2][2]=1;
pieces[7]->piece_dir[6].Piece_array[3][2]=1;
pieces[7]->piece_dir[6].Piece_array[3][3]=1;

pieces[7]->piece_dir[7].Piece_array[1][2]=1;
pieces[7]->piece_dir[7].Piece_array[2][2]=1;
pieces[7]->piece_dir[7].Piece_array[3][2]=1;
pieces[7]->piece_dir[7].Piece_array[3][1]=1;


pieces[8]->piece_dir[0].Piece_array[2][1]=1;
pieces[8]->piece_dir[0].Piece_array[2][2]=1;
pieces[8]->piece_dir[0].Piece_array[1][2]=1;
pieces[8]->piece_dir[0].Piece_array[1][3]=1;

pieces[8]->piece_dir[1].Piece_array[2][3]=1;
pieces[8]->piece_dir[1].Piece_array[2][2]=1;
pieces[8]->piece_dir[1].Piece_array[1][1]=1;
pieces[8]->piece_dir[1].Piece_array[1][2]=1;

pieces[8]->piece_dir[2].Piece_array[1][2]=1;
pieces[8]->piece_dir[2].Piece_array[2][2]=1;
pieces[8]->piece_dir[2].Piece_array[2][1]=1;
pieces[8]->piece_dir[2].Piece_array[3][1]=1;

pieces[8]->piece_dir[3].Piece_array[3][2]=1;
pieces[8]->piece_dir[3].Piece_array[2][2]=1;
pieces[8]->piece_dir[3].Piece_array[1][1]=1;
pieces[8]->piece_dir[3].Piece_array[2][1]=1;


pieces[9]->piece_dir[0].Piece_array[1][2]=1;
pieces[9]->piece_dir[0].Piece_array[2][2]=1;
pieces[9]->piece_dir[0].Piece_array[3][2]=1;
pieces[9]->piece_dir[0].Piece_array[4][2]=1;
pieces[9]->piece_dir[0].Piece_array[1][1]=1;

pieces[9]->piece_dir[1].Piece_array[1][2]=1;
pieces[9]->piece_dir[1].Piece_array[2][2]=1;
pieces[9]->piece_dir[1].Piece_array[3][2]=1;
pieces[9]->piece_dir[1].Piece_array[4][2]=1;
pieces[9]->piece_dir[1].Piece_array[1][3]=1;

pieces[9]->piece_dir[2].Piece_array[1][2]=1;
pieces[9]->piece_dir[2].Piece_array[2][2]=1;
pieces[9]->piece_dir[2].Piece_array[3][2]=1;
pieces[9]->piece_dir[2].Piece_array[4][2]=1;
pieces[9]->piece_dir[2].Piece_array[4][1]=1;

pieces[9]->piece_dir[3].Piece_array[1][2]=1;
pieces[9]->piece_dir[3].Piece_array[2][2]=1;
pieces[9]->piece_dir[3].Piece_array[3][2]=1;
pieces[9]->piece_dir[3].Piece_array[4][2]=1;
pieces[9]->piece_dir[3].Piece_array[4][3]=1;

pieces[9]->piece_dir[4].Piece_array[2][1]=1;
pieces[9]->piece_dir[4].Piece_array[2][2]=1;
pieces[9]->piece_dir[4].Piece_array[2][3]=1;
pieces[9]->piece_dir[4].Piece_array[2][4]=1;
pieces[9]->piece_dir[4].Piece_array[1][1]=1;

pieces[9]->piece_dir[5].Piece_array[2][1]=1;
pieces[9]->piece_dir[5].Piece_array[2][2]=1;
pieces[9]->piece_dir[5].Piece_array[2][3]=1;
pieces[9]->piece_dir[5].Piece_array[2][4]=1;
pieces[9]->piece_dir[5].Piece_array[3][1]=1;

pieces[9]->piece_dir[6].Piece_array[2][1]=1;
pieces[9]->piece_dir[6].Piece_array[2][2]=1;
pieces[9]->piece_dir[6].Piece_array[2][3]=1;
pieces[9]->piece_dir[6].Piece_array[2][4]=1;
pieces[9]->piece_dir[6].Piece_array[1][4]=1;

pieces[9]->piece_dir[7].Piece_array[2][1]=1;
pieces[9]->piece_dir[7].Piece_array[2][2]=1;
pieces[9]->piece_dir[7].Piece_array[2][3]=1;
pieces[9]->piece_dir[7].Piece_array[2][4]=1;
pieces[9]->piece_dir[7].Piece_array[3][4]=1;


pieces[10]->piece_dir[0].Piece_array[2][1]=1;
pieces[10]->piece_dir[0].Piece_array[2][2]=1;
pieces[10]->piece_dir[0].Piece_array[2][3]=1;
pieces[10]->piece_dir[0].Piece_array[0][2]=1;
pieces[10]->piece_dir[0].Piece_array[1][2]=1;

pieces[10]->piece_dir[1].Piece_array[2][1]=1;
pieces[10]->piece_dir[1].Piece_array[2][2]=1;
pieces[10]->piece_dir[1].Piece_array[2][3]=1;
pieces[10]->piece_dir[1].Piece_array[3][2]=1;
pieces[10]->piece_dir[1].Piece_array[4][2]=1;

pieces[10]->piece_dir[2].Piece_array[1][2]=1;
pieces[10]->piece_dir[2].Piece_array[2][2]=1;
pieces[10]->piece_dir[2].Piece_array[3][2]=1;
pieces[10]->piece_dir[2].Piece_array[2][0]=1;
pieces[10]->piece_dir[2].Piece_array[2][1]=1;

pieces[10]->piece_dir[3].Piece_array[1][2]=1;
pieces[10]->piece_dir[3].Piece_array[2][2]=1;
pieces[10]->piece_dir[3].Piece_array[3][2]=1;
pieces[10]->piece_dir[3].Piece_array[2][3]=1;
pieces[10]->piece_dir[3].Piece_array[2][4]=1;


pieces[11]->piece_dir[0].Piece_array[2][2]=1;
pieces[11]->piece_dir[0].Piece_array[2][3]=1;
pieces[11]->piece_dir[0].Piece_array[2][4]=1;
pieces[11]->piece_dir[0].Piece_array[0][2]=1;
pieces[11]->piece_dir[0].Piece_array[1][2]=1;

pieces[11]->piece_dir[1].Piece_array[2][2]=1;
pieces[11]->piece_dir[1].Piece_array[2][3]=1;
pieces[11]->piece_dir[1].Piece_array[2][4]=1;
pieces[11]->piece_dir[1].Piece_array[3][2]=1;
pieces[11]->piece_dir[1].Piece_array[4][2]=1;

pieces[11]->piece_dir[2].Piece_array[2][2]=1;
pieces[11]->piece_dir[2].Piece_array[3][2]=1;
pieces[11]->piece_dir[2].Piece_array[4][2]=1;
pieces[11]->piece_dir[2].Piece_array[2][0]=1;
pieces[11]->piece_dir[2].Piece_array[2][1]=1;

pieces[11]->piece_dir[3].Piece_array[0][2]=1;
pieces[11]->piece_dir[3].Piece_array[1][2]=1;
pieces[11]->piece_dir[3].Piece_array[2][2]=1;
pieces[11]->piece_dir[3].Piece_array[2][0]=1;
pieces[11]->piece_dir[3].Piece_array[2][1]=1;


pieces[12]->piece_dir[0].Piece_array[2][2]=1;
pieces[12]->piece_dir[0].Piece_array[2][3]=1;
pieces[12]->piece_dir[0].Piece_array[2][4]=1;
pieces[12]->piece_dir[0].Piece_array[3][1]=1;
pieces[12]->piece_dir[0].Piece_array[3][2]=1;

pieces[12]->piece_dir[1].Piece_array[2][2]=1;
pieces[12]->piece_dir[1].Piece_array[2][3]=1;
pieces[12]->piece_dir[1].Piece_array[2][4]=1;
pieces[12]->piece_dir[1].Piece_array[1][1]=1;
pieces[12]->piece_dir[1].Piece_array[1][2]=1;

pieces[12]->piece_dir[2].Piece_array[2][1]=1;
pieces[12]->piece_dir[2].Piece_array[2][2]=1;
pieces[12]->piece_dir[2].Piece_array[2][3]=1;
pieces[12]->piece_dir[2].Piece_array[3][3]=1;
pieces[12]->piece_dir[2].Piece_array[3][4]=1;

pieces[12]->piece_dir[3].Piece_array[2][1]=1;
pieces[12]->piece_dir[3].Piece_array[2][2]=1;
pieces[12]->piece_dir[3].Piece_array[2][3]=1;
pieces[12]->piece_dir[3].Piece_array[1][3]=1;
pieces[12]->piece_dir[3].Piece_array[1][4]=1;

pieces[12]->piece_dir[4].Piece_array[2][2]=1;
pieces[12]->piece_dir[4].Piece_array[3][2]=1;
pieces[12]->piece_dir[4].Piece_array[4][2]=1;
pieces[12]->piece_dir[4].Piece_array[1][3]=1;
pieces[12]->piece_dir[4].Piece_array[2][3]=1;

pieces[12]->piece_dir[5].Piece_array[2][2]=1;
pieces[12]->piece_dir[5].Piece_array[3][2]=1;
pieces[12]->piece_dir[5].Piece_array[4][2]=1;
pieces[12]->piece_dir[5].Piece_array[1][1]=1;
pieces[12]->piece_dir[5].Piece_array[2][1]=1;

pieces[12]->piece_dir[6].Piece_array[1][2]=1;
pieces[12]->piece_dir[6].Piece_array[2][2]=1;
pieces[12]->piece_dir[6].Piece_array[3][2]=1;
pieces[12]->piece_dir[6].Piece_array[3][3]=1;
pieces[12]->piece_dir[6].Piece_array[4][3]=1;

pieces[12]->piece_dir[7].Piece_array[1][2]=1;
pieces[12]->piece_dir[7].Piece_array[2][2]=1;
pieces[12]->piece_dir[7].Piece_array[3][2]=1;
pieces[12]->piece_dir[7].Piece_array[3][1]=1;
pieces[12]->piece_dir[7].Piece_array[4][1]=1;

pieces[13]->piece_dir[0].Piece_array[2][2]=1;
pieces[13]->piece_dir[0].Piece_array[1][2]=1;
pieces[13]->piece_dir[0].Piece_array[3][2]=1;
pieces[13]->piece_dir[0].Piece_array[1][3]=1;
pieces[13]->piece_dir[0].Piece_array[3][1]=1;

pieces[13]->piece_dir[1].Piece_array[1][2]=1;
pieces[13]->piece_dir[1].Piece_array[2][2]=1;
pieces[13]->piece_dir[1].Piece_array[3][2]=1;
pieces[13]->piece_dir[1].Piece_array[3][3]=1;
pieces[13]->piece_dir[1].Piece_array[1][1]=1;

pieces[13]->piece_dir[2].Piece_array[2][2]=1;
pieces[13]->piece_dir[2].Piece_array[2][1]=1;
pieces[13]->piece_dir[2].Piece_array[2][3]=1;
pieces[13]->piece_dir[2].Piece_array[1][3]=1;
pieces[13]->piece_dir[2].Piece_array[3][1]=1;

pieces[13]->piece_dir[3].Piece_array[2][1]=1;
pieces[13]->piece_dir[3].Piece_array[2][2]=1;
pieces[13]->piece_dir[3].Piece_array[2][3]=1;
pieces[13]->piece_dir[3].Piece_array[3][3]=1;
pieces[13]->piece_dir[3].Piece_array[1][1]=1;


pieces[14]->piece_dir[0].Piece_array[2][0]=1;
pieces[14]->piece_dir[0].Piece_array[2][1]=1;
pieces[14]->piece_dir[0].Piece_array[2][2]=1;
pieces[14]->piece_dir[0].Piece_array[2][3]=1;
pieces[14]->piece_dir[0].Piece_array[2][4]=1;

pieces[14]->piece_dir[1].Piece_array[0][2]=1;
pieces[14]->piece_dir[1].Piece_array[1][2]=1;
pieces[14]->piece_dir[1].Piece_array[2][2]=1;
pieces[14]->piece_dir[1].Piece_array[3][2]=1;
pieces[14]->piece_dir[1].Piece_array[4][2]=1;


pieces[15]->piece_dir[0].Piece_array[2][2]=1;
pieces[15]->piece_dir[0].Piece_array[2][1]=1;
pieces[15]->piece_dir[0].Piece_array[2][3]=1;
pieces[15]->piece_dir[0].Piece_array[3][2]=1;
pieces[15]->piece_dir[0].Piece_array[3][3]=1;

pieces[15]->piece_dir[1].Piece_array[2][2]=1;
pieces[15]->piece_dir[1].Piece_array[3][1]=1;
pieces[15]->piece_dir[1].Piece_array[2][3]=1;
pieces[15]->piece_dir[1].Piece_array[3][2]=1;
pieces[15]->piece_dir[1].Piece_array[3][3]=1;

pieces[15]->piece_dir[2].Piece_array[2][2]=1;
pieces[15]->piece_dir[2].Piece_array[2][1]=1;
pieces[15]->piece_dir[2].Piece_array[2][3]=1;
pieces[15]->piece_dir[2].Piece_array[3][1]=1;
pieces[15]->piece_dir[2].Piece_array[3][2]=1;

pieces[15]->piece_dir[3].Piece_array[2][2]=1;
pieces[15]->piece_dir[3].Piece_array[2][1]=1;
pieces[15]->piece_dir[3].Piece_array[3][3]=1;
pieces[15]->piece_dir[3].Piece_array[3][1]=1;
pieces[15]->piece_dir[3].Piece_array[3][2]=1;

pieces[15]->piece_dir[4].Piece_array[1][2]=1;
pieces[15]->piece_dir[4].Piece_array[2][2]=1;
pieces[15]->piece_dir[4].Piece_array[3][2]=1;
pieces[15]->piece_dir[4].Piece_array[2][3]=1;
pieces[15]->piece_dir[4].Piece_array[3][3]=1;

pieces[15]->piece_dir[5].Piece_array[2][2]=1;
pieces[15]->piece_dir[5].Piece_array[1][3]=1;
pieces[15]->piece_dir[5].Piece_array[3][2]=1;
pieces[15]->piece_dir[5].Piece_array[2][3]=1;
pieces[15]->piece_dir[5].Piece_array[3][3]=1;

pieces[15]->piece_dir[6].Piece_array[2][2]=1;
pieces[15]->piece_dir[6].Piece_array[1][2]=1;
pieces[15]->piece_dir[6].Piece_array[3][2]=1;
pieces[15]->piece_dir[6].Piece_array[1][3]=1;
pieces[15]->piece_dir[6].Piece_array[2][3]=1;

pieces[15]->piece_dir[7].Piece_array[2][2]=1;
pieces[15]->piece_dir[7].Piece_array[1][2]=1;
pieces[15]->piece_dir[7].Piece_array[3][3]=1;
pieces[15]->piece_dir[7].Piece_array[1][3]=1;
pieces[15]->piece_dir[7].Piece_array[2][3]=1;


pieces[16]->piece_dir[0].Piece_array[2][2]=1;
pieces[16]->piece_dir[0].Piece_array[2][1]=1;
pieces[16]->piece_dir[0].Piece_array[3][1]=1;
pieces[16]->piece_dir[0].Piece_array[1][2]=1;
pieces[16]->piece_dir[0].Piece_array[1][3]=1;

pieces[16]->piece_dir[1].Piece_array[2][2]=1;
pieces[16]->piece_dir[1].Piece_array[2][1]=1;
pieces[16]->piece_dir[1].Piece_array[1][1]=1;
pieces[16]->piece_dir[1].Piece_array[3][2]=1;
pieces[16]->piece_dir[1].Piece_array[3][3]=1;

pieces[16]->piece_dir[2].Piece_array[2][2]=1;
pieces[16]->piece_dir[2].Piece_array[3][2]=1;
pieces[16]->piece_dir[2].Piece_array[1][3]=1;
pieces[16]->piece_dir[2].Piece_array[2][3]=1;
pieces[16]->piece_dir[2].Piece_array[3][1]=1;

pieces[16]->piece_dir[3].Piece_array[2][2]=1;
pieces[16]->piece_dir[3].Piece_array[1][2]=1;
pieces[16]->piece_dir[3].Piece_array[1][1]=1;
pieces[16]->piece_dir[3].Piece_array[2][3]=1;
pieces[16]->piece_dir[3].Piece_array[3][3]=1;


pieces[17]->piece_dir[0].Piece_array[2][2]=1;
pieces[17]->piece_dir[0].Piece_array[2][1]=1;
pieces[17]->piece_dir[0].Piece_array[2][3]=1;
pieces[17]->piece_dir[0].Piece_array[3][1]=1;
pieces[17]->piece_dir[0].Piece_array[3][3]=1;

pieces[17]->piece_dir[1].Piece_array[2][1]=1;
pieces[17]->piece_dir[1].Piece_array[2][2]=1;
pieces[17]->piece_dir[1].Piece_array[2][3]=1;
pieces[17]->piece_dir[1].Piece_array[1][1]=1;
pieces[17]->piece_dir[1].Piece_array[1][3]=1;

pieces[17]->piece_dir[2].Piece_array[2][2]=1;
pieces[17]->piece_dir[2].Piece_array[1][2]=1;
pieces[17]->piece_dir[2].Piece_array[3][2]=1;
pieces[17]->piece_dir[2].Piece_array[1][3]=1;
pieces[17]->piece_dir[2].Piece_array[3][3]=1;

pieces[17]->piece_dir[3].Piece_array[1][2]=1;
pieces[17]->piece_dir[3].Piece_array[2][2]=1;
pieces[17]->piece_dir[3].Piece_array[3][2]=1;
pieces[17]->piece_dir[3].Piece_array[1][1]=1;
pieces[17]->piece_dir[3].Piece_array[3][1]=1;


pieces[18]->piece_dir[0].Piece_array[2][2]=1;
pieces[18]->piece_dir[0].Piece_array[2][3]=1;
pieces[18]->piece_dir[0].Piece_array[2][1]=1;
pieces[18]->piece_dir[0].Piece_array[1][2]=1;
pieces[18]->piece_dir[0].Piece_array[3][1]=1;

pieces[18]->piece_dir[1].Piece_array[2][2]=1;
pieces[18]->piece_dir[1].Piece_array[2][1]=1;
pieces[18]->piece_dir[1].Piece_array[2][3]=1;
pieces[18]->piece_dir[1].Piece_array[1][1]=1;
pieces[18]->piece_dir[1].Piece_array[3][2]=1;

pieces[18]->piece_dir[2].Piece_array[2][1]=1;
pieces[18]->piece_dir[2].Piece_array[2][2]=1;
pieces[18]->piece_dir[2].Piece_array[2][3]=1;
pieces[18]->piece_dir[2].Piece_array[3][2]=1;
pieces[18]->piece_dir[2].Piece_array[1][3]=1;

pieces[18]->piece_dir[3].Piece_array[2][2]=1;
pieces[18]->piece_dir[3].Piece_array[2][3]=1;
pieces[18]->piece_dir[3].Piece_array[2][1]=1;
pieces[18]->piece_dir[3].Piece_array[1][2]=1;
pieces[18]->piece_dir[3].Piece_array[3][3]=1;

pieces[18]->piece_dir[4].Piece_array[2][2]=1;
pieces[18]->piece_dir[4].Piece_array[3][2]=1;
pieces[18]->piece_dir[4].Piece_array[1][2]=1;
pieces[18]->piece_dir[4].Piece_array[2][1]=1;
pieces[18]->piece_dir[4].Piece_array[1][3]=1;

pieces[18]->piece_dir[5].Piece_array[2][2]=1;
pieces[18]->piece_dir[5].Piece_array[1][2]=1;
pieces[18]->piece_dir[5].Piece_array[3][2]=1;
pieces[18]->piece_dir[5].Piece_array[1][1]=1;
pieces[18]->piece_dir[5].Piece_array[2][3]=1;

pieces[18]->piece_dir[6].Piece_array[1][2]=1;
pieces[18]->piece_dir[6].Piece_array[2][2]=1;
pieces[18]->piece_dir[6].Piece_array[2][3]=1;
pieces[18]->piece_dir[6].Piece_array[3][2]=1;
pieces[18]->piece_dir[6].Piece_array[3][1]=1;

pieces[18]->piece_dir[7].Piece_array[2][2]=1;
pieces[18]->piece_dir[7].Piece_array[3][2]=1;
pieces[18]->piece_dir[7].Piece_array[2][1]=1;
pieces[18]->piece_dir[7].Piece_array[1][2]=1;
pieces[18]->piece_dir[7].Piece_array[3][3]=1;


pieces[19]->piece_dir[0].Piece_array[2][2]=1;
pieces[19]->piece_dir[0].Piece_array[2][1]=1;
pieces[19]->piece_dir[0].Piece_array[2][3]=1;
pieces[19]->piece_dir[0].Piece_array[1][2]=1;
pieces[19]->piece_dir[0].Piece_array[3][2]=1;


pieces[20]->piece_dir[0].Piece_array[2][1]=1;
pieces[20]->piece_dir[0].Piece_array[2][2]=1;
pieces[20]->piece_dir[0].Piece_array[2][3]=1;
pieces[20]->piece_dir[0].Piece_array[2][4]=1;
pieces[20]->piece_dir[0].Piece_array[1][2]=1;


pieces[20]->piece_dir[1].Piece_array[2][1]=1;
pieces[20]->piece_dir[1].Piece_array[2][2]=1;
pieces[20]->piece_dir[1].Piece_array[2][3]=1;
pieces[20]->piece_dir[1].Piece_array[2][4]=1;
pieces[20]->piece_dir[1].Piece_array[1][3]=1;

pieces[20]->piece_dir[2].Piece_array[2][1]=1;
pieces[20]->piece_dir[2].Piece_array[2][2]=1;
pieces[20]->piece_dir[2].Piece_array[2][3]=1;
pieces[20]->piece_dir[2].Piece_array[2][4]=1;
pieces[20]->piece_dir[2].Piece_array[3][2]=1;

pieces[20]->piece_dir[3].Piece_array[2][1]=1;
pieces[20]->piece_dir[3].Piece_array[2][2]=1;
pieces[20]->piece_dir[3].Piece_array[2][3]=1;
pieces[20]->piece_dir[3].Piece_array[2][4]=1;
pieces[20]->piece_dir[3].Piece_array[3][3]=1;

pieces[20]->piece_dir[4].Piece_array[1][2]=1;
pieces[20]->piece_dir[4].Piece_array[2][2]=1;
pieces[20]->piece_dir[4].Piece_array[3][2]=1;
pieces[20]->piece_dir[4].Piece_array[4][2]=1;
pieces[20]->piece_dir[4].Piece_array[2][1]=1;

pieces[20]->piece_dir[5].Piece_array[1][2]=1;
pieces[20]->piece_dir[5].Piece_array[2][2]=1;
pieces[20]->piece_dir[5].Piece_array[3][2]=1;
pieces[20]->piece_dir[5].Piece_array[4][2]=1;
pieces[20]->piece_dir[5].Piece_array[3][1]=1;

pieces[20]->piece_dir[6].Piece_array[1][2]=1;
pieces[20]->piece_dir[6].Piece_array[2][2]=1;
pieces[20]->piece_dir[6].Piece_array[3][2]=1;
pieces[20]->piece_dir[6].Piece_array[4][2]=1;
pieces[20]->piece_dir[6].Piece_array[2][3]=1;

pieces[20]->piece_dir[7].Piece_array[1][2]=1;
pieces[20]->piece_dir[7].Piece_array[2][2]=1;
pieces[20]->piece_dir[7].Piece_array[3][2]=1;
pieces[20]->piece_dir[7].Piece_array[4][2]=1;
pieces[20]->piece_dir[7].Piece_array[3][3]=1;

}
