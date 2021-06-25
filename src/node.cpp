/*
 * node.cpp
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#include "board.h"
#include "piece.h"
#include "moveVector.h"
#include "pathVector.h"
#include "node.h"

using namespace std;


	node::node(board current){
		this->current=current;
	};

	node::node(board* last, pathVector path){
		short int start[2]= {path.start.x, path.start.y};
		short int end[2] = {path.move.x+path.start.x, path.move.y+path.start.y};
		this->current.set_board(*new board(last, start, end));
	};

	node::~node(){

		this->children.clear();
	};

	pathVector node::getBestMove(int depth){

		this->getChildren();

		print();

		node* evaluating = new node(&this->current, this->children[0]);
		pathVector bestMove = this->children[0];
		int minmax = evaluating->getChildrenEvaluation(depth-1);



				for(pathVector move : this->children){

					evaluating = new node(&this->current, move);

					int eval = evaluating->getChildrenEvaluation(depth-1);

					if(this->current.turn){
						if(minmax < eval){
							minmax=eval;
							bestMove=move;
						}
					}
					else{
						if(minmax > eval){
							minmax = eval;
							bestMove=move;
						}
					}
				}

			delete evaluating;

				return bestMove;

	}

	int node::getChildrenEvaluation(int depth){

		if(depth){
			this->getChildren();
			print();
			return this->minimax( depth);
		}
		else{
			return this->current.evaluation;
		}
	};

	int node::minimax(int depth){

		node* evaluating = new node(&this->current, this->children[0]);
		int minmax = evaluating->getChildrenEvaluation(depth-1);

		for(pathVector move : this->children){

			evaluating = new node(&this->current, move);

			int eval = evaluating->getChildrenEvaluation(depth-1);

			if(this->current.turn){
				if(minmax < eval)
					minmax=eval;
			}
			else{
				if(minmax > eval)
					minmax = eval;
			}
		}

		delete evaluating;

		return minmax;//minmax;
	};

	void node::getChildren(){ // a vector of evaluations from children

//		this->children=
		this->current.nextPositions(&this->children);//iterates through next positions, need to be created as nodes?

	};

	void node::print(){
		this->current.print();

		/*for(pathVector path : this->children){
			path.print();
		cout<<"\n";
		}*/



	};


// get evaluation as min/max of children until depth equal 0

