/*
 * moveVector.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_MOVEVECTOR_H_
#define SRC_MOVEVECTOR_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include "moveVector.h"


using namespace std;

struct moveVector{
	short int x;
	short int y;

	moveVector(){}
	moveVector(short int x, short int y){
		this->x=x;
		this->y=y;
	}


	moveVector operator+(moveVector b){
		moveVector result;

		result.x = this->x = b.x;
		result.y = this->y = b.y;

		return result;
	}
	void print();
};






#endif /* SRC_MOVEVECTOR_H_ */
