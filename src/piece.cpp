#include <iostream>
#include <stdio.h>
#include <vector>

#include "piece.h"
#include "moveVector.h"


using namespace std;


moveVector white_pawn[4] = {{0,1},{0,2},{1,1},{-1,1}};
moveVector black_pawn[4] = {{0,-1},{0,-2},{1,-1},{-1,-1}};

	moveVector rook[32] = {	//one of the 00 sets requires another check?
									{0,-8}, {0,-7}, {0,-6}, {0,-5}, {0,-4}, {0,-3}, {0,-2}, {0,-1}, //00
									{0,1}, {0,2}, {0,3}, {0,4}, {0,5}, {0,6}, {0,7}, {0,8}, //01
									{-8,0}, {-7,0}, {-6,0}, {-5,0}, {-4,0}, {-3,0}, {-2,0}, {-1,0}, //00
									{1,0}, {2,0}, {3,0}, {4,0}, {5,0}, {6,0}, {7,0}, {8,0}};//10

	moveVector knight[8] = {{-1,-2}, {-2,-1}, //00
									{-1,2}, {-2,1}, //01
									{1,-2}, {2,-1}, //10
									{1,2}, {2,1} //11
									};

	moveVector bishop[32] = {	{-8,-8}, {-7,-7}, {-6,-6}, {-5,-5}, {-4,-4}, {-3,-3}, {-2,-2}, {-1,-1}, //00
										{-1,1}, {-2,2}, {-3,3}, {-4,4}, {-5,5}, {-6,6}, {-7,7}, {-8,8}, //01
										{8,-8}, {7,-7}, {6,-6}, {5,-5}, {4,-4}, {3,-3}, {2,-2}, {1,-1}, //10
										{1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}, {8,8}  }; //11

	moveVector king[8] = {	{0,-1}, {-1,-1},
									{0,1}, {-1,1},
									{1,-1},{1,0},
									{1,1}, {-1,0} };

	moveVector queen[64] = {
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

	moveVector empty[1]={{0,0}};


	const short int length[6]= {4, 8, 32, 32, 64, 8};
	const short int set_length[6]= {1, 8, 1, 8, 1, 8};



	void piece::set_piece(piece x){
		Piece_Id=x.Piece_Id;
		Piece_Side=x.Piece_Side;
	}
	void piece::set_Piece_Id(char id){
		Piece_Id = id;
	}
	void piece::piece::set_Piece_Side(bool side){
		Piece_Side=side;
	}
	void piece::print_Piece_Id(){
		cout<< Piece_Id;
	}
	void piece::set_empty(){
		Piece_Id='e';
	}

	bool piece::is_empty(){
		return Piece_Id=='e';
	}

	char piece::get_piece_id(){
		return Piece_Id;
	}

	bool piece::get_piece_side(){
		return Piece_Side;
	}

	int piece::get_Piece_value(){

		int value;
		switch (this->Piece_Id){
		case 'e':
			value = 0;
			break;
		case 'p':
			value = 1;
			break;
		case 'k':
		case 'b':
			value = 3;
			break;
		case'r':
			value = 5;
			break;
		case 'Q':
			value = 9;
			break;
		case 'K':
			value = 1000;
			break;
		};

		if (! this->Piece_Side)
			value*=-1;

		return value;
	}




	short int piece::get_movement_vector_length(){

			switch (this->Piece_Id){
					case 'p':
						return length[0];
						break;
					case 'k':
						return length[1];
						break;
					case 'b':
						return length[2];
						break;
					case'r':
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

	moveVector& piece::get_moveVectors(){
		switch (this->Piece_Id){
							case 'p':
								if(this->Piece_Side)
									return *white_pawn;
								else
									return *black_pawn;
								break;
							case 'k':
								return *knight;
								break;
							case 'b':
								return *bishop;
								break;
							case'r':
								return *rook;
								break;
							case 'Q':
								return *queen;
								break;
							case 'K':
								return *king;
								break;
							default:
								return *empty;
							};

	}

