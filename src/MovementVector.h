/*
 * MovementVector.h
 *
 *  Created on: Jan. 30, 2022
 *      Author: anton
 */

#ifndef SRC_MOVEMENTVECTOR_H_
#define SRC_MOVEMENTVECTOR_H_

#include "PositionVector.h"
struct MovementVector {


	PositionVector direction;
	int maxScalar;

	MovementVector(){
		direction = {0,0};
		maxScalar=0;

	};
	MovementVector(PositionVector direction, int maxScalar){
		this->direction=direction;
		this->maxScalar=maxScalar;


	};

	MovementVector(int x, int y, int maxScalar){

			this->direction={y, x};
			this->maxScalar=maxScalar;


		};
	~MovementVector(){};



};

struct MovementVectorList{

	MovementVector * list;
	int length;

	MovementVectorList(MovementVector*list, int length){

		this->list=list;
		this->length=length;
	};
	~MovementVectorList(){};
};



#endif /* SRC_MOVEMENTVECTOR_H_ */
