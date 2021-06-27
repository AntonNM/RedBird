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

#include "moveVector.h"


using namespace std;

struct pathVector{
public:
	moveVector start;
	moveVector move;


	pathVector(moveVector start, moveVector move){
		this->start=start;
		this->move=move;

	};

	pathVector(){}

	moveVector getStart(){
		return this->start;
	}

	moveVector getMove(){
		return this->move;
	}

	moveVector getEnd(){
		return this->start + this->move;
	}

	void print(){
		this->start.print();
		this->move.print();
	}

	bool isEmpty(){

		return  (this->move.x==0) and (this->move.y==0);
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





#endif /* SRC_PATHVECTOR_H_ */
