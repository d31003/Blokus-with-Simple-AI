//Piece.cpp     the implementation of Piece.h
#include "Piece.h"
#include <iostream>

using namespace std;
int para_sup = -1;




//Constructor
Piece::Piece(int piece_num1, int size1, int type_num1)
{
	piece_number = piece_num1;
	size = size1;
	type_num = type_num1; 
	//struct piece_array piece_dir[type_num] ={};
	piece_dir = new struct piece_array[type_num];
	for(int i = 0; i<type_num;i++)
	{
		for(int j = 0; j <5; j++)
		{	for(int k= 0; k <5; k++)
			{
				piece_dir[i].Piece_array[j][k] = 0;
				//cout<<piece_dir[i].Piece_array[j][k]<<" ";
			}
			//cout<<endl;
		}
		//debug cout<<"1"; 
		//cout<<endl;
		
	}
	

	//piece_dir 's initialization
}
Piece::~Piece()
{
	delete piece_dir;
	
	
 } 
//Member Functions 










