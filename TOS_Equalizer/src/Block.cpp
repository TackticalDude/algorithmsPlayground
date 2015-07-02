/**
 * @headerfile Block.h
 * @author Zakaria el Barnoussi (TackticalDude)
 * @version 0.1
*/

#include "Block.h"

/**
 * @name Constructor
 * @param ID - id of the block
 * @param datachunk - chunk of data
 * @param size - size of the data chunk
 */
Block::Block(int ID, short* datachunk, int size) {
	_ID = ID;
	memcpy(_dataChunk, datachunk, sizeof(short)*size);
	_size = size;
}

/**
 * @name getDataChunk
 * @return the datachunk of the block object
 */
short *Block::getDataChunk(){
	return _dataChunk;
}

/**
 * @name getSize
 * @return size of the block
 */
int Block::getSize(){
	return _size;
}

/**
 * @name getID
 * @return id of the datachunk of the block
 */
int Block::getID(){
	return this->_ID;
}

/**
 * @name Deconstructor
 */
Block::~Block() {
	free(_dataChunk);
}

