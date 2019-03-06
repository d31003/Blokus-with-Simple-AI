//Piece_set.h
#ifndef PIECE_SET_H
#define PIECE_SET_H
#include "Piece.h"

class Piece_set
{
	public:
		Piece_set();
		~Piece_set();

		Piece* pieces[21];
		bool viable[21];
		bool remain[21];

		void initial_size();
		void initial_type();
		void initial_piece();
		void printviable();
		void printremain();
		void printremainbutnotviable();






	private:
		static int piece_size[21];
		static int piece_type[21];


};



#endif
