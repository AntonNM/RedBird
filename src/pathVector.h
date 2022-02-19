/*
 * pathVector.h
 *
 *  Created on: May 1, 2021
 *      Author: anton
 */

#ifndef SRC_PATHVECTOR_H_
#define SRC_PATHVECTOR_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include "PositionVector.h"


using namespace std;


struct pathVector{
public:
	PositionVector start;
	PositionVector end;
	char pieceId;


	pathVector(PositionVector start, PositionVector end, char PieceId){
		this->start=start;
		this->end=end;
		this->pieceId=PieceId;

	};

	pathVector(){
		this->start={};
		this->end={};
		this->pieceId='e';
	}

	PositionVector getStart(){
		return this->start;
	}

	PositionVector getEnd(){
		return this->end;
	}
	PositionVector getMove(){

		return this->end+ this->start*-1;
	}

//	PositionVector* getEnd(){
//		return &this->start + &this->move;
//	}

	void print(){
		this->start.print();
		this->end.print();
		std::cout<<this->pieceId<<"\n";

	}

	bool isEmpty(){

		return  (this->end.x=0) and (this->end.y==0);
	}
	/*int evaluation;

	bool operator==(pathVector b){

		return this->evaluation == b.evaluation;
	}
	bool operator<(pathVector b){
		return this->evaluation < b.evaluation;
	}
	bool operator>(pathVector b){
		return this->evaluation > b.evaluation;
	}*/

};



struct childVector{
public:
	pathVector move;
	int childEval;
	bool Checkmate;
	bool StaleMate;
	bool side;
	int depth;

	childVector(pathVector Move, int Eval, int depth){ // Produces a childVector from move and the minimax evaluation of the child.
		this->move=Move;
		this->childEval=Eval;
		this->Checkmate=false;
		this->StaleMate=false;
		this->side=false;
		this->depth=depth;

	}
	childVector(pathVector Move, childVector mate){
			this->move=Move;
			this->childEval=mate.childEval;
			this->Checkmate=mate.Checkmate;
			this->StaleMate=mate.StaleMate;
			this->side=mate.side;
			this->depth=mate.depth+1;
			if(this->Checkmate){
				this->childEval++;
			}

		}


	childVector(bool Checkmate, bool StaleMate, bool side){
				this->move={};
				this->childEval=0;
				this->Checkmate=Checkmate;
				this->StaleMate=StaleMate;
				this->side=side;
				this->depth=0;

			}

	bool operator>(childVector b){

		if(this->Checkmate ){ //checkmate for white is greatest element
			//std::cout<<"CheckmateSide"<<this->side;
			if(b.Checkmate ){ //checkmate for black is smallest element
						return this->childEval<b.childEval;
					}
			return !this->side;
		}
		if(b.Checkmate ){ //checkmate for black is smallest element
			return b.side;
		}

		if(this->StaleMate){

			if(b.StaleMate){

				return !this->side && b.side; // not sure which stalemate has higher priority for white, whit gets stalemated verus black get stalemated
				}

			return b.childEval<0;


		}

		if(b.StaleMate){

						return this->childEval>0;
					}

		if( !(this->Checkmate || this->StaleMate ) ){




			return this->childEval>b.childEval;
		}





		return true;
	}


	void print(){
		this->move.print();
		std::cout<<" eval:"<<this->childEval<<" CM : "<<this->Checkmate<<" SM: "<<this->StaleMate<<" \n";
	}

};





#endif /* SRC_PATHVECTOR_H_ */
