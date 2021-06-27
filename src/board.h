/*
 * board.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include "board.h"
#include "piece.h"
#include "moveVector.h"
#include "pathVector.h"


using namespace std;

class board
{
	public:

		piece position[8][8];
		bool turn;
		int evaluation;



		board();
		board( board* last, short int start[2], short int end[2]);
		~board();

		void print();
		void set_board(board board);
		void evaluate();
		bool is_check();
		void nextPositions(vector<pathVector>* children);

		pathVector getNextPathVector(moveVector *boardPosition, int* pointerPosition);

		bool validMove(board* current, short int start[2], short int end[2]);


};



#endif /* SRC_BOARD_H_ */
