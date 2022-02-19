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
#include "Piece.h"
#include "PositionVector.h"
#include "pathVector.h"
#include "node.h"
#include <time.h>

using namespace std;







class engine {

	node currentBoard;

	vector<pathVector> evaluatingPath;

	//tranposition table

	//alphabeta pruning

	//progressive deepening3.


};





int main2(){

	board * start = new board(true);

	start->print();

	return 0;
}


int main(){

	clock_t tStart = clock();
	int depth =4;

	board *start = new board(true);

	node *gameNode = new node(start);


/*
	vector<pathVector> possibleMoves;

	pathVector firstMove= { PositionVector {1, 4}, PositionVector {3, 4}, 'p' };
	pathVector secondMove={ PositionVector {6, 3}, PositionVector {4, 3}, 'p' };
	pathVector thirdMove= { PositionVector {3, 4}, PositionVector {4, 3}, 'p' };
	pathVector fourthMove= { PositionVector {6, 7}, PositionVector {4, 7}, 'p' };

	board* first = new board(start, &firstMove);
	first->print();
	board* second = new board(first, &secondMove);
	second->print();
	board* third = new board(second, &thirdMove);
	third->print();
	board* fourth = new board(third, &fourthMove);
	//start->print();
	fourth->print();
*/





/*

	for(Piece* piece = third->Head->Next;piece!=third->Middle;piece=piece->Next){

		piece->print();
	}
	for(Piece* piece = third->Tail->Previous;piece!=third->Middle;piece=piece->Previous){
		piece->print();
	}
*/

/*
	start->nextPositions(&possibleMoves);

	//for

	for(auto move:possibleMoves){

		move.print();
		board* next = new board(start,&(move));
		//next->print();
	}
*/


int numboards = 0;


	gameNode->minimax(depth, &numboards).print();//.print();//.print();
	//node *Next;

	std::cout<<((double)(clock()-tStart))/CLOCKS_PER_SEC;
	std::cout<<"\n"<<numboards;

	//start->Head;

	/*for(Piece* pointer=start->Head->Next;pointer!=start->Middle;pointer=pointer->Next){

		pointer->printPieceId();
	}*/

	//std::cout<<start->position[4][0]->pieceId;

	//gameNode->getChildren();

	//gameNode->print();


	//pathVector bestMove = gameNode->getBestMove(depth);


/*
	char input;
	while (true){

		gameNode->current.evaluate();
		cout<<"evaluation: "<<gameNode->current.evaluation<<"\n";
		cout<<"Next?";
		cin>>input;

		bestMove = gameNode->getBestMove(depth);
		// best move needs to be randomized if multiple equal moves are produced.
		// Piece evaluations should be affected by a position matrix
		//alpha beta pruning
		//Deincentives repititions
		Next = new node(&gameNode->current, bestMove);

		delete gameNode;
		gameNode = Next;
		gameNode->print();


	}


	delete gameNode;
	delete start;

*/



	return 0;
}



