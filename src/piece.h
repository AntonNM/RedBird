/*
 * piece.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_PIECE_H_
#define SRC_PIECE_H_

#include <iostream>
#include <stdio.h>
#include <vector>


#include "piece.h"
#include "moveVector.h"

using namespace std;

class piece {

private:
	char Piece_Id;
	bool Piece_Side;

public:
	void set_piece(piece x);
	void set_Piece_Id(char id);
	void set_Piece_Side(bool side);
	void print_Piece_Id();
	void set_empty();
	bool is_empty();
	char get_piece_id();
	bool get_piece_side();
	int get_Piece_value();
	short int get_movement_vector_length();
	moveVector& get_moveVectors();
};


#endif /* SRC_PIECE_H_ */
