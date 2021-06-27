/*
 * main.cpp
 *
 *  Created on: March 4, 2021
 *      Author: Anton Mladenov
 */


#include <iostream>
#include <stdio.h>
#include <vector>

#include "board.h"
#include "piece.h"
#include "moveVector.h"
#include "pathVector.h"
#include "node.h"

using namespace std;







class engine {

	node currentBoard;

	vector<pathVector> evaluatingPath;


};








int main(){


	board *start = new board();
	//start->print();

	node *gameNode = new node(*start);

	pathVector bestMove = gameNode->getBestMove(5);

	bestMove.print();


	delete gameNode;
	delete start;



//	start->nextPositions();



//	int* a;
//
//	int array[5]={-10, 2, 3, 4, 6};
//
//	a=array;
//
//	vector<int> vec;
//
//	vector<board> children;

	return 0;
}



