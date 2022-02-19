/*
 * board.h
 *
 *  Created on: Apr. 30, 2021
 *      Author: anton
 */

#ifndef SRC_BOARD_H_
#define SRC_BOARD_H_

#include <iostream>
#include <stdio.h>
#include <vector>

#include "board.h"
#include "PositionVector.h"
#include "pathVector.h"
#include "Piece.h"


using namespace std;

class board
{

	//Double Sentinal linked list order by piece value largest to smallest
	//Iterator based on Player turn
	//Evaluation = sum of pieces

	//ability to walk through all pieces and get its position more possible moves
	//get piece from position in lowest possible time



	public:

		Piece* position[8][8]; //double array of pointer to pieces given a position vector for the indices



		Piece *Head;
		Piece *Tail;
		Piece *Middle;



		bool turn;
		float evaluation;

		//bool pushPiece(Piece *piece);
		void pushPiece(Piece* piece);
		void sortPieces();
		void remove_Piece(Piece *piece){

			piece->Next->Previous=piece->Previous;
			piece->Previous->Next=piece->Next;
			//piece->Next=nullptr;
			//piece->Previous=nullptr;
			//delete piece;
		};

		//iterator for piece linked list for prioritizing move of pieces.

		bool isCheck(pathVector move){

			PositionVector start = move.start;
			PositionVector end = move.getEnd();

		//	Piece * King= this->getKing(side);

			//move.print();

			if(move.pieceId=='K'){

			}

			Piece* King = nullptr;

			for(Piece* piece = (this->turn)?this->Head->Next:this->Tail->Previous; piece!=Middle; piece=(this->turn)? piece->Next : piece->Previous){

				if(piece->pieceId=='K'){
					King=piece;

				}

			}

			/*if (King==nullptr){
				std::cout<<"King Got CAPTURED??";
				return true;
			}*/

			char pieceIds[6] = {'p', 'N', 'B', 'R', 'Q', 'K'};


			for(int pieceIndex=0;pieceIndex<6;pieceIndex++){

				char pieceId= pieceIds[pieceIndex];

				MovementVectorList MoveList = King->getMovementVectorList(pieceId);

				MovementVector* moves = MoveList.list;

				for(int index = 0; index< MoveList.length; index++){
					if(pieceId=='p' && index==0){ //skip over non capturing pawn moves
						index=1;
					}
					for(int scalar=1; scalar <= (moves+index)->maxScalar;scalar++){

						if(move.pieceId!='K'){
						PositionVector Square = King->positionVector + (moves+index)->direction*-1*scalar;

						if(!Square.isValid()){
							break;
						}
						if(Square==start){

						}
						else if(Square==end){
							break;
						}
						else{
							 Piece* piece = this->getPiece(Square);

							if(piece!=nullptr && piece->pieceId==pieceId && piece->pieceSide!=this->turn){
								//std::cout<<"isCheck:";
								//piece->print();
								//King->print();
								return true;
							}

						}
						}
						else{
							PositionVector Square = move.end + (moves+index)->direction*-1*scalar;

													if(!Square.isValid()){
														break;
													}
													if(Square==start){

													}

													else{
														 Piece* piece = this->getPiece(Square);

														if(piece!=nullptr && piece->pieceId==pieceId && piece->pieceSide!=this->turn){
															//std::cout<<"isCheck:";
															//piece->print();
															//King->print();
															return true;
														}

													}



						}

					}

				}

			}
			//modify position array but not piece information to be able to return
			//search all piece capture from king position
			//looking for opposing piece
			//that have the same movement vector (search opposite directions?)
			//ignore piece on start position
			//override piece on end square


			return false;
		};

		bool isCheck(){

			//	PositionVector start = move.start;
				//PositionVector end = move.getEnd();

			//	Piece * King= this->getKing(side);

				Piece* King;

				for(Piece* piece = (this->turn)?this->Head->Next:this->Tail->Previous; piece!=Middle; piece=(this->turn)? piece->Next : piece->Previous){

					if(piece->pieceId=='K'){
						King=piece;

					}

				}

				char pieceIds[6] = {'p', 'N', 'B', 'R', 'Q', 'K'};


				for(int pieceIndex=0;pieceIndex<6;pieceIndex++){

					char pieceId= pieceIds[pieceIndex];

					MovementVectorList MoveList = King->getMovementVectorList(pieceId);

					MovementVector* moves = MoveList.list;

					for(int index = 0; index< MoveList.length; index++){
						if(pieceId=='p' && index==0){ //skip over non capturing pawn moves
							index=1;
						}
						for(int scalar=1; scalar <= (moves+index)->maxScalar;scalar++){

							PositionVector Square = King->positionVector + (moves+index)->direction*-1*scalar;

							if(!Square.isValid()){
								break;
							}
			/*				}
					//		if(Square==start){

							}
					//		else if(Square==end){
								break;
							}*/
							else{
								 Piece* piece = this->getPiece(Square);

								if(piece!=nullptr && piece->pieceId==pieceId && piece->pieceSide!=this->turn){
									//std::cout<<"isCheck:";
									//piece->printPieceId();
									//King->printPieceId();
									return true;
								}

							}

						}

					}

				}
				//modify position array but not piece information to be able to return
				//search all piece capture from king position
				//looking for opposing piece
				//that have the same movement vector (search opposite directions?)
				//ignore piece on start position
				//override piece on end square


				return false;
			};

		board();
		board(bool start);
		//board( board* last,  int start[2], int end[2]);
		board(const board* last,  pathVector* move);

		~board();

		void print();
		void set_board(board board);
		void evaluate();
		bool is_check();






		Piece* getPiece(PositionVector positionVector);

		bool removePiece(PositionVector location);

		//pathVector getNextPathVector(PositionVector *boardPosition, int* pointerPosition);
		void nextPositions(vector<pathVector>* children);

		bool validMove(board* current,  int start[2], int end[2]);
		//bool validMove(pathVector* move);


};



#endif /* SRC_BOARD_H_ */
