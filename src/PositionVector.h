/*
 * PositionVector.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_PositionVector_H_
#define SRC_PositionVector_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include "PositionVector.h"


using namespace std;

struct PositionVector{
	 int x;
	int y;

	PositionVector(){
		this->x=0;
		this->y=0;


	}
	PositionVector( int y,int x){
		this->x=x;
		this->y=y;
	}

	bool isValid(){

		return this->x>=0 && this->x<=7 && this->y>=0 && this->y<=7;
	}

	PositionVector  operator+(PositionVector b){


		//return result;
		return {this->y + b.y,this->x + b.x};
		//return new PositionVector(this->x + b.x,this->y + b.y);


	}
	PositionVector operator*(int scalar){

		return {this->y*scalar, this->x*scalar};
	}

	bool operator==(PositionVector* b){

		if ((x == b->x) && (y == b->y ))
			return true;
		return false;


		}

	bool operator==(PositionVector b){

			if ((x == b.x) && (y == b.y ))
				return true;
			return false;


			}
	void print();
};






#endif /* SRC_PositionVector_H_ */
