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
#include "pathVector.h"
#include "node.h"

#include "Piece.h"
#include "PositionVector.h"

using namespace std;

//Should implement tree traversal, with perhaps hashmap of pathvetor from current board for transpositions
//alpha beta pruning and progressive deepening


	node::node(board* current){
		this->current=current;
	};

	node::node(board* last, pathVector* path){
		/*int start[2]= {path.start.x, path.start.y};
		int end[2] = {path.move.x+path.start.x, path.move.y+path.start.y};*/
		this->current=new board(last, path);
		//delete x;
	};

	node::~node(){


		delete this->current;
	};



	childVector node::minimax(int depth, int *numBoards){

		if(depth>0){


			childVector bestMove={pathVector{}, int{}, depth};
			bool first=true;
			//this->getChildren();
			//this->current->print();
			this->current->nextPositions(&this->children);
			if(this->children.size()>0){
			for(pathVector move:this->children){

				//std::cout<<"something";
				//board* child = new board(this->current, &move);
				//child->print();
				node* child= new node(this->current, &move);
				(*numBoards)++;
				childVector childEvaluation = child->minimax(depth-1, numBoards);
				//move.print();
				// child->current->print();
				//std::cout<<"childEval"<<childEvaluation.childEval;

			/*	if(childEvaluation.Checkmate){
					bestMove.print();
					childEvaluation.print();
					move.print();
				}
*/
				if(first){ // first move
					// asign current move to stats of childVector
					//bestMove={move,childEvaluation.childEval};
					bestMove={move, childEvaluation}; // checkmate instructor, bool side may be inaccurate? for none mates?
					first=false;


				}

				else if ((this->current->turn)?childEvaluation>bestMove:bestMove>childEvaluation){

					bestMove={move, childEvaluation};

				}

		/*		else if(childEvaluation.Checkmate){

					if(childEvaluation.side==this->current->turn){
						bestMove={move, childEvaluation};
						break;
					}

				}
				else if(childEvaluation.StaleMate){

						if(childEvaluation.side==this->current->turn){
							if(!bestMove.Checkmate && ((this->current->turn)? bestMove.childEval<0:bestMove.childEval>0)){ //if best move is not checkmate and the evaluation is losing
								bestMove={move, childEvaluation};
							}
						}
				}





				else if(!bestMove.Checkmate){// && !bestMove.StaleMate){ // when to compare non mate child with Best move
					//staleMate is replace with evaluation fo 1 or greater
					if(bestMove.StaleMate){
						if((this->current->turn)? childEvaluation.childEval<0:childEvaluation.childEval>0){
							bestMove={move,childEvaluation};
						}
					}
					else if((this->current->turn)? childEvaluation.childEval>bestMove.childEval : childEvaluation.childEval<bestMove.childEval){
						bestMove={move,childEvaluation.childEval};
					}
				}

*/			delete child;
			child=nullptr;
			}


			return bestMove;

			}


			else{ // no valid moves
				if( this->current->isCheck()){
					//return checkmate
					//this->current->print();
					return childVector{true,false, (this->current->turn)};

				}
				else{
					//return stalemate
					return childVector{false,true, (this->current->turn)};
				}
			}
		}

		else{ // depth==0
			//std::cout<<"board eval" <<this->current->evaluation;
			return childVector{pathVector{},int{this->current->evaluation}, depth};

		}
	}





	void node::getChildren(){ // a vector of evaluations from children

//		this->children=
		this->current->nextPositions(&this->children);//iterates through next positions, need to be created as nodes?

	};

	void node::print(){
		this->current->print();

		for(pathVector path : this->children){
			path.print();
		cout<<"\n";
		}



	};


// get evaluation as min/max of children until depth equal 0

