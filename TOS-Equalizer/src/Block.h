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
	char* _dataChunk;
	int _size;
public:
	Block(int ID, char* datachunk, int size);
	char *getDataChunk();
	virtual ~Block();
};

#endif /* BLOCK_H_ */
