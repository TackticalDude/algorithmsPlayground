/*
 * Blobk.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "Block.h"

Block::Block(int ID, short* datachunk, int size) {
	_ID = ID;
	//std::copy(datachunk, datachunk+size, _dataChunk);
	memcpy(_dataChunk, datachunk, sizeof(short)*size);
	_size = size;
}

short *Block::getDataChunk(){
	return _dataChunk;
}

int Block::getSize(){
	return _size;
}

//Block::~Block() {
//	free(_dataChunk);
//}

