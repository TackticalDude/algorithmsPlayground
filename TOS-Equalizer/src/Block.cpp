/*
 * Blobk.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "Block.h"

Block::Block(int ID, short* datachunk, int size) {
	_ID = ID;
	_dataChunk = datachunk;
	_size = size;
}

short *Block::getDataChunk(){
	return _dataChunk;
}

int Block::getSize(){
	return _size;
}

Block::~Block() {
	free(_dataChunk);
}

