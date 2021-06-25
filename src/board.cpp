#include <iostream>
#include <stdio.h>
#include <vector>

#include "board.h"
#include "piece.h"
#include "moveVector.h"
#include "pathVector.h"


using namespace std;



//
//class board {
//private:
//
//	piece position[8][8];
//	bool turn;
//	int evaluation;
//
//public:
	// Default constructor for the initial board position


	board::board(){

		char Intial_Position_Ids[8][8] = {'r', 'k', 'b', 'Q', 'K', 'b', 'k', 'r',
										  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
										  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
										  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
										  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
										  'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e',
										  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
										  'r', 'k', 'b', 'Q', 'K', 'b', 'k', 'r'};
		//Sets Piece Ids in Board.Position
		for(int i=0; i<8;++i){
			for (int o=0;o<8;++o){
				position[i][o].set_Piece_Id(Intial_Position_Ids[i][o]);
				position[i][o].set_Piece_Side(i<=3);
			}
		}
		turn = true;
		evaluation = 0;
	}

	board::board( board* last, short int start[2], short int end[2]){

		turn = !last->turn;

		evaluation = last->evaluation - last->position[end[1]][end[0]].get_Piece_value();

		for(int i=0;i<8;i++){
			for(int o=0;o<8;o++){
					position[i][o]=last->position[i][o];
				}
			}

		piece* moving = &position[start[1]][start[0]];
		position[end[1]][end[0]].set_piece(*moving);
		moving->set_empty();


	}

	board::~board(){}

	// Constructor to create a board from a previous position
	///////////////////////////////////////////////////////


	void board::set_board(board board){

		turn= board.turn;
		for(int i=0;i<8;i++){
			for(int o=0;o<8;o++){
				this->position[i][o].set_piece(board.position[i][o]);
			}
		}

	}

	// Prints the current position of a board
	void board::print(){

		for(int i=0; i<8;++i){
			for (int o=0;o<8;++o){
				position[i][o].print_Piece_Id();
			}
			cout<<'\n';
		}

		cout<< "Turn: " << turn;
		cout<<'\n';

	}


	void board::evaluate(){
		for(int i=0; i<8;++i){
			for (int o=0;o<8;++o){
				evaluation+= position[i][o].get_Piece_value();
			}
		}

	}

	bool board::is_check(){
			return false;

		}


	void board::nextPositions(vector<pathVector>* children){

		for(short int i=0;i<8;i++){

			for(short int o=0;o<8;o++){

				if (!position[i][o].is_empty() && position[i][o].get_piece_side()==turn){

					for(short int j=0;j< position[i][o].get_movement_vector_length();j++){

						short int start[2] = {o, i};
						short int end[2]={ o + (&position[i][o].get_moveVectors()+j)->x , i+ (&position[i][o].get_moveVectors()+j)->y}; // pawn moves are different for opposite sides


							//(&position[i][o].get_moveVectors()+j)->print();
							if(validMove(this, start, end)){
								//board* next = new board(this, start, end);
//								pathVector* childPath = new pathVector(start, move, node.evaluation);
								moveVector starting(start[0], start[1]);
								moveVector move((&position[i][o].get_moveVectors()+j)->x ,(&position[i][o].get_moveVectors()+j)->y);

								pathVector path(starting, move);
								children->push_back(path);
							}
					}

				}
			}
		}

	}

	bool board::validMove(board* current, short int start[2], short int end[2]){
		if(end[0]>=0 && end[0]<=7 && end[1]>=0 && end[1]<=7){

			char Id=current->position[start[1]][start[0]].get_piece_id();

			short int move_y=end[1]-start[1];
			short int move_x=end[0]-start[0];

			switch(Id){

			case 'Q':

				if (move_y==0){
					if(move_x>0){
						for(short int x=start[0]+1;x<end[0];x++){
							if(!current->position[start[1]][x].is_empty())
								return false;
						}
					}
					else{
						for(short int x=start[0]-1;x>end[0];x--){
							if(!current->position[start[1]][x].is_empty())
								return false;
						}
					}
				}
				if (move_x==0){
					if(move_y>0){
						for(short int y=start[1]+1;y<end[1];y++){
							if(!current->position[y][start[0]].is_empty())
									return false;
						}
					}
					else{
						for(short int y=start[1]-1;y>end[1];y--){
							if(!current->position[y][start[0]].is_empty())
									return false;
						}
					}
				}
				if(move_x>0 && move_y>0){
									for(short int y=start[1]+1, x=start[0]+1; y<end[1]; y++, x++){
										if(!current->position[y][x].is_empty())
												return false;
									}
								}
								else if(move_x<0 && move_y>0){
									for(short int y=start[1]+1, x=start[0]-1; y<end[1]; y++, x--){
										if(!current->position[y][x].is_empty())
												return false;
									}

								}
								else if(move_x<0 && move_y<0){
									for(short int y=start[1]-1, x=start[0]-1; y>end[1]; y--, x--){
										if(!current->position[y][x].is_empty())
												return false;
									}

								}
								else if(move_x>0 && move_y<0){
									for(short int y=start[1]-1, x=start[0]+1; y>end[1]; y--, x++){
										if(!current->position[y][x].is_empty())
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
					for(short int y=start[1]+1, x=start[0]+1; y<end[1]; y++, x++){
						if(!current->position[y][x].is_empty())
								return false;
					}
				}
				else if(move_x<0 && move_y>0){
					for(short int y=start[1]+1, x=start[0]-1; y<end[1]; y++, x--){
						if(!current->position[y][x].is_empty())
								return false;
					}

				}
				else if(move_x<0 && move_y<0){
					for(short int y=start[1]-1, x=start[0]-1; y>end[1]; y--, x--){
						if(!current->position[y][x].is_empty())
								return false;
					}

				}
				else if(move_x>0 && move_y<0){
					for(short int y=start[1]-1, x=start[0]+1; y>end[1]; y--, x++){
						if(!current->position[y][x].is_empty())
								return false;
					}
				}
				break;
			case 'k':
				break;
			case 'r':
				if (move_y==0){
					if(move_x>0){
						for(short int x=start[0]+1;x<end[0];x++){
							if(!current->position[start[1]][x].is_empty())
								return false;
						}
					}
					else{
						for(short int x=start[0]-1;x>end[0];x--){
							if(!current->position[start[1]][x].is_empty())
								return false;
						}
					}
				}
				if (move_x==0){
					if(move_y>0){
						for(short int y=start[1]+1;y<end[1];y++){
							if(!current->position[y][start[0]].is_empty())
									return false;
						}
					}
					else{
						for(short int y=start[1]-1;y>end[1];y--){
							if(!current->position[y][start[0]].is_empty())
									return false;
						}
					}
				}
				break;
			case 'p':

				if(move_x==0){
					if(move_y>0){
						for(short int y=start[1]+1;y<=end[1];y++){
							if(!current->position[y][start[0]].is_empty())
									return false;
						}
					}
					else{
						for(short int y=start[1]+1;y>=end[1];y--){
							if(!current->position[y][start[0]].is_empty())
									return false;
						}
					}
				}
				else
					if(position[end[1]][end[0]].is_empty())
						return false;

				break;
			}

			if(!position[end[1]][end[0]].is_empty())
				return position[start[1]][start[0]].get_piece_side() != position[end[1]][end[0]].get_piece_side();
			else
				return true;
		}
		else{
			return false;
		}

		return true;
	}



