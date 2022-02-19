/*
 * node.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include "PositionVector.h"
#include "pathVector.h"
#include "Piece.h"
#include "board.h"
#include "node.h"

using namespace std;


class node{ // purpose is to manage tree searches of board objects

public:

	board* current;
	vector<pathVector> children;


	node(board* current);

	node(board* last, pathVector* path);

	~node();

//	pathVector getBestMove(int depth);

	//childVector getChildrenEvaluation(int depth);

	childVector minimax(int depth, int* numBoards);

	void getChildren();

	void print();




};


#endif /* SRC_NODE_H_ */
