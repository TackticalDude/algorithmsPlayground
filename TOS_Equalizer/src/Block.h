/*
 * Blobk.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

/**
 * @class Block
 * @brief a block with ID and size
 */
class Block {
private:
	int _ID;
	short _dataChunk[1024];
	int _size;
public:
	Block(int ID, short* datachunk, int size);
	short *getDataChunk();
	int getSize();
	int getID();
	~Block();
};

#endif /* BLOCK_H_ */
