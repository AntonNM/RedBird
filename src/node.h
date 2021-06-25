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

#include "moveVector.h"
#include "pathVector.h"
#include "piece.h"
#include "board.h"
#include "node.h"

using namespace std;


class node{

public:

	board current;
	vector<pathVector> children;


	node(board current);

	node(board* last, pathVector path);

	~node();

	pathVector getBestMove(int depth);

	int getChildrenEvaluation(int depth);

	int minimax(int depth);

	void getChildren();

	void print();




};


#endif /* SRC_NODE_H_ */
