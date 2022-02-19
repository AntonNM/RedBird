#include <iostream>
#include <stdio.h>
#include <vector>

#include "Piece.h"
#include "PositionVector.h"
#include "MovementVector.h"


using namespace std;




MovementVector WHITE_PAWN[3] {{0,1, 2},{1,1, 1},{-1,1, 1}};
MovementVectorList WHITE_PAWN_LIST{WHITE_PAWN, 3};

MovementVector BLACK_PAWN[3] = {{0,-1, 2},{1,-1, 1},{-1,-1, 1}};
MovementVectorList BLACK_PAWN_LIST{BLACK_PAWN, 3};

	MovementVector ROOK[4] = {	//one of the 00 sets requires another check?
									{0,-1, 8}, //00
									{0,1, 8}, //01
									{-1,0, 8}, //00
									{1,0,8}};//10
	MovementVectorList ROOK_LIST{ROOK, 4};

	MovementVector KNIGHT[8] = {{-1,-2, 1}, {-2,-1, 1}, //00
									{-1,2, 1}, {-2,1, 1}, //01
									{1,-2, 1}, {2,-1, 1}, //10
									{1,2, 1}, {2,1, 1} //11
									};

	MovementVectorList KNIGHT_LIST{KNIGHT, 8};

	MovementVector BISHOP[4] = {	 {-1,-1, 8}, //00
										{-1,1, 8}, //01
										 {1,-1, 8}, //10
										{1,1, 8}}; //11

	MovementVectorList BISHOP_LIST{BISHOP, 4};

	MovementVector KING[8] = {	{0,-1, 1}, {-1,-1, 1},
									{0,1, 1}, {-1,1, 1},
									{1,-1, 1},{1,0, 1},
									{1,1, 1}, {-1,0, 1} };

	MovementVectorList KING_LIST{KING, 8};

	MovementVector QUEEN[8] = {	{0,-1, 8}, {-1,-1, 8},
			{0,1, 8}, {-1,1, 8},
			{1,-1, 8},{1,0, 8},
			{1,1, 8}, {-1,0, 8} };

	MovementVectorList QUEEN_LIST{QUEEN, 8};

	MovementVector empty[1]={{0,0, 1}};
	MovementVectorList EMPTY_LIST{empty, 1};

	const short int length[6]= {3, 8, 4, 4, 8, 8};


/*PositionVector WHITE_PAWN[4] = {{0,1},{0,2},{1,1},{-1,1}};
PositionVector BLACK_PAWN[4] = {{0,-1},{0,-2},{1,-1},{-1,-1}};

	PositionVector ROOK[32] = {	//one of the 00 sets requires another check?
									{0,-8}, {0,-7}, {0,-6}, {0,-5}, {0,-4}, {0,-3}, {0,-2}, {0,-1}, //00
									{0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, //01
									{-8,0}, {-7,0}, {-6,0}, {-5,0}, {-4,0}, {-3,0}, {-2,0}, {-1,0}, //00
									{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}};//10

	PositionVector KNIGHT[8] = {{-1,-2}, {-2,-1}, //00
									{-1,2}, {-2,1}, //01
									{1,-2}, {2,-1}, //10
									{1,2}, {2,1} //11
									};

	PositionVector BISHOP[32] = {	{-8,-8}, {-7,-7}, {-6,-6}, {-5,-5}, {-4,-4}, {-3,-3}, {-2,-2}, {-1,-1}, //00
										{-1,1}, {-2,2}, {-3,3}, {-4,4}, {-5,5}, {-6,6}, {-7,7}, {-8,8}, //01
										{8,-8}, {7,-7}, {6,-6}, {5,-5}, {4,-4}, {3,-3}, {2,-2}, {1,-1}, //10
										{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}, {8,8}  }; //11

	PositionVector KING[8] = {	{0,-1}, {-1,-1},
									{0,1}, {-1,1},
									{1,-1},{1,0},
									{1,1}, {-1,0} };

	PositionVector QUEEN[64] = {
									// xy bits 00 section 1/4; s=0  -- must check if x==0
									{0,-8}, {0,-7}, {0,-6}, {0,-5}, {0,-4}, {0,-3}, {0,-2}, {0,-1},// -- must check if x==0
									{-8,-8}, {-7,-7}, {-6,-6}, {-5,-5}, {-4,-4}, {-3,-3}, {-2,-2}, {-1,-1},

									// xy bits 01 section 2/4; s=1
									{0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, //-- must check if x==0
									{-1,1}, {-2,2}, {-3,3}, {-4,4}, {-5,5}, {-6,6}, {-7,7}, {-8,8},

									// xy bits 10 section 3/4; s=2
									{-8,0}, {-7,0}, {-6,0}, {-5,0}, {-4,0}, {-3,0}, {-2,0}, {-1,0}, //-- must check if y==0
									{8,-8}, {7,-7}, {6,-6}, {5,-5}, {4,-4}, {3,-3}, {2,-2}, {1,-1},

									// xy bits 11 section 4/4; s=3
									{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}, //-- must check if y==0
									{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}, {8,8}};

	PositionVector empty[1]={{0,0}};

	const short int length[6]= {4, 8, 32, 32, 64, 8};
	const short int set_length[6]= {1, 8, 1, 8, 1, 8};*/


	float PAWN_MAP[64] = {0, 0, 0, 0, 0, 0, 0, 0,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1.125, 1.5, 1.5, 1.125, 1, 1,
						  1, 1, 1, 1.25, 1.25, 1, 1, 1,
						  3, 1, 1, 1, 1, 1, 1, 3,
						  6, 5, 5, 5, 5, 5, 5, 5,
						  9, 9, 9, 9, 9, 9, 9, 9};



	float ROOK_MAP[64] = {1, 1, 1, 1.2, 1.2, 1.2, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1,
						  1, 1, 1, 1, 1, 1, 1, 1, };

	float KNIGHT_MAP[64] = {0.125, 0.375, 0.5, 0.5, 0.5, 0.5, 0.375, 0.125,
						  0.375, 0.625, 0.75, 0.75, 0.75, 0.75, 0.625, 0.375,
						  0.5, 0.75, 1, 1, 1, 1, 0.75, 0.5,
						  0.5, 0.75, 1, 1, 1, 1, 0.75, 0.5,
						  0.5, 0.75, 1, 1, 1, 1, 0.75, 0.5,
						  0.5, 0.75, 1, 1, 1, 1, 0.75, 0.5,
						  0.375, 0.625, 0.75, 0.75, 0.75, 0.75, 0.625, 0.375,
						  0.125, 0.375, 0.5, 0.5, 0.5, 0.5, 0.375, 0.125,};

	float BISHOP_MAP[64] = {0.33,1, 1, 1, 1, 1, 1, 0.33,
						  1, 1.166, 1, 1, 1, 1, 1.166, 1,
						  1, 1, 1, 1.166, 1, 1.166, 1, 1,
						  1, 1, 1, 1.33, 1.33, 1, 1, 1,
						  1, 1, 1, 1.33, 1.33, 1, 1, 1,
						  1, 1, 1.166, 1, 1, 1.166, 1, 1,
						  1, 1.166, 1, 1, 1, 1, 1.166, 1,
						  0.33, 1, 1, 1, 1, 1, 1, 0.33,};

	float QUEEN_MAP[64] = {1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1.08, 1.08, 1, 1, 1,
							1, 1, 1, 1.08, 1.08, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1};

	float KING_MAP[64] = 	{1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1,
							1, 1, 1, 1, 1, 1, 1, 1};

	float empty_Map[64] = {
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,

	};



/* */
	void Piece::setPieceId(char id){
		pieceId = id;
	}
/*	void Piece::Piece::set_Piece_Side(bool side){
		pieceSide=side;
	}*/
	void Piece::print(){
		if(this!=nullptr){
		cout<< pieceId;// <<":"<< pieceSide;
		//positionVector.print();
		}
		else{
			std::cout<<"something";
		}

	}
/*
	void Piece::set_empty(){
		pieceId='e';
	}
*/

	bool Piece::isEmpty(){
		return pieceId=='e';
	}

	char Piece::getPieceId(){
		return pieceId;
	}

	bool Piece::getPieceSide(){
		return pieceSide;
	}

	float Piece::getPieceValue(){


		int value;
		switch (this->pieceId){
		case 'e':
			value = 0;// * this->getPieceMapValue();
			break;
		case 'p':
			value = 1;// *this->getPieceMapValue();
			break;
		case 'N':
		case 'B':
			value = 3;//*this->getPieceMapValue();
			break;
		case'R':
			value = 5;//*this->getPieceMapValue();
			break;
		case 'Q':
			value = 9;//*this;//->getPieceMapValue();
			break;
		case 'K':
			value = 1000;//*this;//->getPieceMapValue();
			break;
		};

		if (! this->pieceSide)
			value*=-1;

		return value;
	}

	float Piece::getPieceMapValue(){
	/*	float *value;
		int index;
		if(this->Piece_Side)
					this->positionVector.x=7-this->positionVector.x;

		int index = this->positionVector.x*8 +this->positionVector.x;

		value = &this->getPieceMap() +index;


		return *value;*/

		return 1;
	}




	short int Piece::getMovementVectorsLength(){

			switch (this->pieceId){
					case 'p':
						return length[0];
						break;
					case 'N':
						return length[1];
						break;
					case 'B':
						return length[2];
						break;
					case'R':
						return length[3];
						break;
					case 'Q':
						return length[4];
						break;
					case 'K':
						return length[5];
						break;
					default:
						return 0;
					};
		}

	float& Piece::getPieceMap(){
		switch (this->pieceId){
							case 'p':
								return *PAWN_MAP;
								break;
							case 'N':
								return *KNIGHT_MAP;
								break;
							case 'B':
								return *BISHOP_MAP;
								break;
							case'R':
								return *ROOK_MAP;
								break;
							case 'Q':
								return *QUEEN_MAP;
								break;
							case 'K':
								return *KING_MAP;
								break;
							default:
								return *empty_Map;
							};

	}


	MovementVector& Piece::getMovementVectors(){

		switch (this->pieceId){
							case 'p':
								if(this->pieceSide)
									return *WHITE_PAWN;
								else
									return *BLACK_PAWN;
								break;
							case 'N':
								return *KNIGHT;
								break;
							case 'B':
								return *BISHOP;
								break;
							case'R':
								return *ROOK;
								break;
							case 'Q':
								return *QUEEN;
								break;
							case 'K':
								return *KING;
								break;
							default:
								return *empty;
							};

	}

		MovementVectorList& Piece::getMovementVectorList(){

		switch (this->pieceId){
							case 'p':
								if(this->pieceSide)
									return WHITE_PAWN_LIST;
								else
									return BLACK_PAWN_LIST;
								break;
							case 'N':
								return KNIGHT_LIST;
								break;
							case 'B':
								return BISHOP_LIST;
								break;
							case'R':
								return ROOK_LIST;
								break;
							case 'Q':
								return QUEEN_LIST;
								break;
							case 'K':
								return KING_LIST;
								break;
							default:
								return EMPTY_LIST;
							};

	}

		MovementVectorList& Piece::getMovementVectorList(char PieceID){

		switch (PieceID){
							case 'p': // inverted because used while looking for checks
								if(!this->pieceSide)
									return WHITE_PAWN_LIST;
								else
									return BLACK_PAWN_LIST;
								break;
							case 'N':
								return KNIGHT_LIST;
								break;
							case 'B':
								return BISHOP_LIST;
								break;
							case'R':
								return ROOK_LIST;
								break;
							case 'Q':
								return QUEEN_LIST;
								break;
							case 'K':
								return KING_LIST;
								break;
							default:
								return EMPTY_LIST;
							};

	}


