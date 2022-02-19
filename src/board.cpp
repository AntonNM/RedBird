#include <iostream>
#include <stdio.h>
#include <vector>

#include "board.h"
#include "Piece.h"
#include "PositionVector.h"
#include "pathVector.h"


using namespace std;

Piece* board::getPiece(PositionVector position){

	return this->position[position.y][position.x];
}

	board::board(){};

	board::board(bool start){

		Head= new Piece();

		Tail=new Piece();
		Middle=new Piece();

		Head->Next=Middle;
		Middle->Previous= Head;
		Middle->Next = Tail;
		Tail->Previous=Middle;

		char Intial_Position_Ids[8][8] = {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R',
										  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
										  'e', 'e', 'Q', 'e', 'e', 'e', 'e', 'e',
										  'e', 'e', 'e', 'e', 'e', 'B', 'e', 'e',
										  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
										  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
										  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
										  'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'};

		/*char Intial_Position_Ids[8][8] = {'e', 'e', 'e', 'K', 'e', 'e', 'e', 'R',
												  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
												  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
												  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
												  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
												  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
												   'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
												  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'K'};*/


		for(int i=0; i<8;++i){
			for (int o=0;o<8;++o){
				if(Intial_Position_Ids[i][o]!='e'){
					//append piece to correct section of linked list
					Piece * tmp = new Piece(Intial_Position_Ids[i][o], (i<=3), {i, o});
				this->pushPiece(tmp);
				position[i][o]=tmp;
				}
				else{
					position[i][o]=nullptr;

				}
				//,position[i][o]->setPieceId(Intial_Position_Ids[i][o]);
		//		position[i][o]->setPieceSide(i<=3);
			}
		}
		turn = true;
		evaluation = 0;
	}



/*
	board::board( board* last,  int start[2], int end[2]){

		Head=nullptr;
				Tail=nullptr;
				Middle=nullptr;



		turn = !last->turn;

		evaluation = last->evaluation - last->position[end[0]][end[1]]->getPieceValue();

		for(int i=0;i<8;i++){
			for(int o=0;o<8;o++){
				if (last->position[i][o]== nullptr){
					position[i][o]=nullptr;
				}
					position[i][o]= new Piece(last->position[i][o]->pieceId, last->position[i][o]->pieceSide, last->position[i][o]->positionVector);
					this->pushPiece(position[i][o]);

				}
			}

		Piece* moving = position[start[1]][start[0]];
		//position[end[1]][end[0]]->setPiece(*moving);
		//moving->set_empty();


	}
*/

	board::board( const board* last,  pathVector* move){




		Head= new Piece();
		Tail=new Piece();
		Middle=new Piece();

		Head->Next=Middle;
		Middle->Previous= Head;
		Middle->Next = Tail;
		Tail->Previous=Middle;


			turn = !last->turn;

		//	int startX = move->start.x;
		//	int startY = move->start.y;



		//	int endX= startX + move->move.x;
		//	int endY = startY + move->move.y;


			Piece* White = last->Head->Next;
			Piece* Black = last->Tail->Previous;

			//White->printPieceId();
			//Black->printPieceId();

			for(int i=0;i<8;i++){
				for(int o=0;o<8;o++){

					position[i][o]=nullptr;
							}

			}


						while(White != last->Middle){
							//push copy of piece
							Piece* copy = new Piece(White);

							this->pushPiece(copy);
							this->position[copy->positionVector.y][copy->positionVector.x]=copy;

							//Assign pointer to position array

							White= White->Next;

						}

						while(Black != last->Middle){
							//push copy
							Piece* copy = new Piece(Black);
							//std::cout<<copy->pieceValue;
							this->pushPiece(copy);
							this->position[copy->positionVector.y][copy->positionVector.x]=copy;

							//assign pointer to position array


							Black=Black->Previous;


						}




			Piece* endSquarePiece = this->getPiece(move->end);
			Piece* moving = this->getPiece(move->start);


			if(endSquarePiece!= nullptr){
				if(endSquarePiece->pieceId=='K'){
					//this->print();
					//move->print();
				}


				evaluation = last->evaluation - endSquarePiece->pieceValue;

				this->remove_Piece(endSquarePiece);
				delete endSquarePiece;





			}

			else{
				evaluation = last->evaluation;

			}

			moving->positionVector=move->end;
			position[move->end.y][move->end.x]=moving;
			position[move->start.y][move->start.x]=nullptr;






		}

	board::~board(){

		Piece* White = this->Head->Next;
		Piece* Black = this->Tail->Previous;

		while(White != Middle){



				White= White->Next;

				delete White->Previous;

			}

			while(Black != Middle){



				Black=Black->Previous;

				delete Black->Next;


			}

		delete Head;
		delete Middle;
		delete Tail;




	}

	// Constructor to create a board from a previous position
	///////////////////////////////////////////////////////
	void board::pushPiece(Piece* piece){
		if(piece->pieceSide){

			piece->Previous=Middle->Previous;
			piece->Next=Middle;

			piece->Previous->Next=piece;
			piece->Next->Previous=piece;


		}
		else{

			piece->Next=Middle->Next;
			piece->Previous=Middle;

			piece->Previous->Next=piece;
			piece->Next->Previous=piece;

		}

	}

	void board::sortPieces(){};




	void board::set_board(board board){

		turn= board.turn;
		evaluation = board.evaluation;
		for(int i=0;i<8;i++){
			for(int o=0;o<8;o++){
			//	this->position[i][o]->set_Piece(*board.position[i][o]);
			}
		}



	}

	// Prints the current position of a board
	void board::print(){
		cout<<"\n\n";
		for(int i=0; i<8;++i){
			for (int o=0;o<8;++o){
				if(position[i][o]!= nullptr)
					position[i][o]->print();
				else
					std::cout<<"e";
			}
			cout<<'\n';
		}
		cout<<this->evaluation;
		cout<< " => Turn: " << turn;
		cout<<"\n";

	}


	void board::evaluate(){
		for(int i=0; i<8;++i){
			for (int o=0;o<8;++o){
				evaluation+= position[i][o]->getPieceValue();
			}
		}

	}

	bool board::is_check(){
			return false;

		}

	bool board::removePiece(PositionVector location){

		bool result=true;

		//Check for pin?
		return result;
	}

	void board::nextPositions(vector<pathVector>* children){

		//std::cout<<"NextPositions\n";
		Piece* moving = (this->turn)?this->Head->Next:this->Tail->Previous;

		int numPieces=0;
		while (moving != this->Middle){
			numPieces++;

			//moving->printPieceId();
			//std::cout<<"\n";

			MovementVectorList moveVectorList = moving->getMovementVectorList();

			MovementVector* moveVectors = moveVectorList.list;

			for(int move = 0; move < moveVectorList.length; move++){ // goes through direction and max scalar

				for(int scalar=1; scalar <= (moveVectors+move)->maxScalar;scalar++){ // scales up the direction until break and moves on to next direction for piece
					PositionVector final = moving->positionVector + (moveVectors+move)->direction*scalar;

					//pathVector* pathToChild = new pathVector(moving->positionVector,  moving->positionVector + (moveVectors+move)->direction*scalar);// build path vector to push to children vector
					pathVector pathToChild = {moving->positionVector,  moving->positionVector + (moveVectors+move)->direction*scalar, moving->pieceId};// build path vector to push to children vector
					//pathToChild.print();
					if(final.isValid()){ // check move is on the board

						//break on blocking same colour piece
						Piece * finalSquarePiece= position[final.y][final.x];
						if(finalSquarePiece!=nullptr){ // piece on movement square
							if(moving->pieceId=='p'  ){ // || direction == {0,-1}
								PositionVector pawnMove=((this->turn)?PositionVector{0,1}:PositionVector{0, -1});
								if((moveVectors+move)->direction== pawnMove){

									//any piece prevents forward pawn movement
																	//std::cout<<"break - pawn blocked\n";
																	break;
								}

							}

							if(moving->pieceSide != finalSquarePiece->pieceSide){ // capture last valid move in the direction

								//if check
								//std::cout<<"preCheck - capture\n";
								if(!this->isCheck(pathToChild)){
									//pathToChild.print();
									children->push_back(pathToChild);
								//create child board, check for check, if valid  push child
									//board * child = new board(this, &pathToChild);

								}
								//std::cout<<"break - final capture\n";
								break;//capture last valid move in this direction
							}
							else{ //Piece of the same colour illegal move
								// not valid move and move to next direction.
								//std::cout<<"break - blocking piece\n";
								break;
							}

						}
						else{ //empty square => valid move

							if(moving->pieceId=='p'){

								//pawn can only capture diagnoally not to empty square
								PositionVector pawnCapture1 = ((this->turn)?PositionVector{1,1}:PositionVector{-1, 1});
								PositionVector pawnCapture2 = ((this->turn)?PositionVector{1,-1}:PositionVector{-1, -1});



								if((moveVectors+move)->direction==pawnCapture1 || (moveVectors+move)->direction==pawnCapture2){
									//pawn can't capture empty square

									break;
								}

								//PositionVector pawnMove=((this->turn)?PositionVector{0,1}:PositionVector{0, -1});
								if((moving->positionVector.y!=((this->turn)?1:6)) && scalar==2){
									if(moving==this->Middle){
												std::cout<<"error middle\n";
											}
									//moving->printPieceId();
									//moving->positionVector.print();
									//pathToChild.print();
									break;
								}
							}


							//if check
							//std::cout<<"preCheck - free square\n";
							if(!this->isCheck(pathToChild)){
								//std::cout<<"Push - free Square\n";
								children->push_back(pathToChild);
							}
							//produce board for move, continue with direction scaling;

						}
						//break if capture

						//king piece check check


					}//end of valid moves
					else{
					//std::cout<<"break - off the board\n";
					break;//further scaling is off the board.
					}
					//delete pathToChild;


				}

				//(moveVectors+move)->direction;

				//moving->positionVector;
			}

			(this->turn)? moving=moving->Next : moving=moving->Previous;
		}

		/*for(short int i=0;i<8;i++){

			for(short int o=0;o<8;o++){

				if (!position[i][o]->isEmpty() && position[i][o]->getPieceSide()==turn){

					for(short int j=0;j< position[i][o]->getMovementVectorsLength();j++){

						short int start[2] = {o, i};
						//short int end[2]={ o + (&position[i][o]->getMovementVectors()+j)->direction.x , i+ (&position[i][o]->getMovementVectors()+j)->direction.y}; // pawn moves are different for opposite sides


							//(&position[i][o].get_PositionVectors()+j)->print();
						//	if(validMove(this, start, end)){
								//board* next = new board(this, start, end);
//								pathVector* childPath = new pathVector(start, move, node.evaluation);
							//	PositionVector* starting = new PositionVector(start[0], start[1]);
							//	PositionVector* move = new PositionVector((&position[i][o]->getMovementVectors()+j)->x ,(&position[i][o]->getMovementVectors()+j)->y);

						//		pathVector* path= new pathVector();
						//		children->push_back(*path);
						//	}
					}

				}
			}
		}
*/		//std::cout<<"numpiece:"<<numPieces<<"\n";
	}

	/*pathVector board::getNextPathVector(PositionVector *boardPosition, int* pointerPosition){

		pathVector result;
		int y=boardPosition->y;
		int x=boardPosition->x;
		int z = *pointerPosition;

		for(; y<8; y++){
			for(; x <8;x++){
				if (!position[y][x]->isEmpty() && position[y][x]->getPieceSide()==turn){}

					MovementVector *moves = &position[y][x]->getMovementVectors();
					int movesLength = position[y][x]->getMovementVectorsLength();

					for(;z<movesLength;z++){

						MovementVector *move = moves+z;

						int start[2]= {x, y};
						 int end[2]={x+move->direction.x, y+move->direction.y};

						if(validMove(this, start , end)){
							*boardPosition={x, y};
							*pointerPosition = ++z;
							//result = {*boardPosition, *move};
							return result;
						}
					}
					z=0;
			}
				x=0;
		}

			y=0;
		 ///////////////////
		///////////////////

		return result;

	}*/

	/*bool board::validMove(board* current,  int start[2], int end[2]){
		if(end[0]>=0 && end[0]<=7 && end[1]>=0 && end[1]<=7){

			char Id=current->position[start[1]][start[0]]->getPieceId();

			 int move_y=end[1]-start[1];
			int move_x=end[0]-start[0];

			switch(Id){

			case 'Q':

				if (move_y==0){
					if(move_x>0){
						for(int x=start[0]+1;x<end[0];x++){
							if(!current->position[start[1]][x]->isEmpty())
								return false;
						}
					}
					else{
						for( int x=start[0]-1;x>end[0];x--){
							if(!current->position[start[1]][x]->isEmpty())
								return false;
						}
					}
				}
				if (move_x==0){
					if(move_y>0){
						for( int y=start[1]+1;y<end[1];y++){
							if(!current->position[y][start[0]]->isEmpty())
									return false;
						}
					}
					else{
						for( int y=start[1]-1;y>end[1];y--){
							if(!current->position[y][start[0]]->isEmpty())
									return false;
						}
					}
				}
				if(move_x>0 && move_y>0){
									for(int y=start[1]+1, x=start[0]+1; y<end[1]; y++, x++){
										if(!current->position[y][x]->isEmpty())
												return false;
									}
								}
								else if(move_x<0 && move_y>0){
									for( int y=start[1]+1, x=start[0]-1; y<end[1]; y++, x--){
										if(!current->position[y][x]->isEmpty())
												return false;
									}

								}
								else if(move_x<0 && move_y<0){
									for( int y=start[1]-1, x=start[0]-1; y>end[1]; y--, x--){
										if(!current->position[y][x]->isEmpty())
												return false;
									}

								}
								else if(move_x>0 && move_y<0){
									for( int y=start[1]-1, x=start[0]+1; y>end[1]; y--, x++){
										if(!current->position[y][x]->isEmpty())
												return false;
									}
								}
				break;

			case 'K':
				if(current->is_check())
					return false;

				break;


			case 'b':
				if(move_x>0 && move_y>0){
					for( int y=start[1]+1, x=start[0]+1; y<end[1]; y++, x++){
						if(!current->position[y][x]->isEmpty())
								return false;
					}
				}
				else if(move_x<0 && move_y>0){
					for( int y=start[1]+1, x=start[0]-1; y<end[1]; y++, x--){
						if(!current->position[y][x]->isEmpty())
								return false;
					}

				}
				else if(move_x<0 && move_y<0){
					for( int y=start[1]-1, x=start[0]-1; y>end[1]; y--, x--){
						if(!current->position[y][x]->isEmpty())
								return false;
					}

				}
				else if(move_x>0 && move_y<0){
					for( int y=start[1]-1, x=start[0]+1; y>end[1]; y--, x++){
						if(!current->position[y][x]->isEmpty())
								return false;
					}
				}
				break;
			case 'k':
				break;
			case 'r':
				if (move_y==0){
					if(move_x>0){
						for( int x=start[0]+1;x<end[0];x++){
							if(!current->position[start[1]][x]->isEmpty())
								return false;
						}
					}
					else{
						for( int x=start[0]-1;x>end[0];x--){
							if(!current->position[start[1]][x]->isEmpty())
								return false;
						}
					}
				}
				if (move_x==0){
					if(move_y>0){
						for( int y=start[1]+1;y<end[1];y++){
							if(!current->position[y][start[0]]->isEmpty())
									return false;
						}
					}
					else{
						for( int y=start[1]-1;y>end[1];y--){
							if(!current->position[y][start[0]]->isEmpty())
									return false;
						}
					}
				}
				break;
			case 'p':

				if(move_x==0){
					if(move_y>0){
						for( int y=start[1]+1;y<=end[1];y++){
							if(!current->position[y][start[0]]->isEmpty())
									return false;
						}
					}
					else{
						for( int y=start[1]+1;y>=end[1];y--){
							if(!current->position[y][start[0]]->isEmpty())
									return false;
						}
					}
				}
				else
					if(position[end[1]][end[0]]->isEmpty())
						return false;

				break;
			}

			if(!position[end[1]][end[0]]->isEmpty())
				return position[start[1]][start[0]]->getPieceSide() != position[end[1]][end[0]]->getPieceSide();
			else
				return true;
		}
		else{
			return false;
		}

		return true;
	}

*/

