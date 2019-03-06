//Piece.h
//declaration of the "Piece" that should be used in the game
#ifndef Piece_H
#define Piece_H

//struct piece_array related difinition
struct piece_array
{
	int Piece_array[5][5];
};
/*
void print_pieceArray();
void print_piece();

=>to Piece.cpp
*/

class Piece
{
public:
//variables, and Constructor
	Piece(int,int,int);
	~Piece();
	
	int piece_number;
	/*const*/int type_num;
	//struct piece_array piece_dir[8];
	struct piece_array* piece_dir ; 
	int size; //the size on board /// =the area this piece takes.
	
//functions
//struct functions
	void print_pieceArray(struct piece_array );
	void print_piece(struct piece_array [], int);

 };
 



#endif

 
