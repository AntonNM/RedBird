/*
 * TranspositionTable.h
 *
 *  Created on: Feb. 18, 2022
 *      Author: anton
 */

#ifndef SRC_TRANSPOSITIONTABLE_H_
#define SRC_TRANSPOSITIONTABLE_H_


#include "pathVector.h"
#include "Board.h"
#include "iostream"
#include <map>


class TranspositionTable{

	std::map<std::string,childVector> table;


	bool exists(board* board){

		return true;
	}

	childVector getBestMove(board* board){

		return childVector{};
	}

	void insert(board* board){


	}

	std::string getIndex(board* board){


		return std::string{};
	}








};




#endif /* SRC_TRANSPOSITIONTABLE_H_ */
