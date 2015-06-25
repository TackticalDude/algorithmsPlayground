/*
 * Blobk.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "Block.h"

Block::Block(int ID, char* datachunk, int size) {
	_ID = ID;
	_dataChunk = datachunk;
	_size = size;
}

char *Block::getDataChunk(){
	return _dataChunk;
}

Block::~Block() {
	free(_dataChunk);
}

