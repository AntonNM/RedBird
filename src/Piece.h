/*
 * Piece.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_Piece_H_
#define SRC_Piece_H_

#include <iostream>
#include <stdio.h>
#include <vector>


#include "Piece.h"
#include "PositionVector.h"
#include "MovementVector.h"

using namespace std;

class Piece {

public:

	char pieceId;
	bool pieceSide;
	int pieceValue;

	bool pinned; // add to constructor

	Piece * Next;
	Piece *Previous;

	PositionVector positionVector;



	Piece(){

	pieceId='e';
	pieceSide= false;
	positionVector={};

	pieceValue=0;

	pinned=false;

	Next=nullptr;
	Previous=nullptr;




	};

	Piece (char pieceId,bool pieceSide, PositionVector positionVector){

		this->pieceId=pieceId;
		this->pieceSide=pieceSide;
		this->positionVector=positionVector;

		this->pieceValue = this->getPieceValue();

		this->pinned=false;
		Next=nullptr;
		Previous=nullptr;

	};

	Piece(Piece* piece){

		this->pieceId=piece->pieceId;
				this->pieceSide=piece->pieceSide;
				this->positionVector=piece->positionVector;

				this->pieceValue = piece->pieceValue;

				this->pinned=piece->pinned;

				Next=nullptr;
				Previous=nullptr;

	};


	//void set_Piece(Piece x);
	void setPieceId(char id);
	//void set_Piece_Side(bool side);
	void print();
	//void set_empty();
	bool isEmpty();
	char getPieceId();
	bool getPieceSide();
	float getPieceValue();//replace indices with position vectors
	float getPieceMapValue();
	float& getPieceMap();
	short int getMovementVectorsLength();


	MovementVector& getMovementVectors();
	MovementVectorList& getMovementVectorList();
	MovementVectorList& getMovementVectorList(char PieceID);
};


#endif /* SRC_Piece_H_ */
