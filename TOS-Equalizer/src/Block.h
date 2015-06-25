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

class Block {
private:
	int _ID;
	short* _dataChunk;
	int _size;
public:
	Block(int ID, short* datachunk, int size);
	short *getDataChunk();
	int getSize();
	virtual ~Block();
};

#endif /* BLOCK_H_ */
