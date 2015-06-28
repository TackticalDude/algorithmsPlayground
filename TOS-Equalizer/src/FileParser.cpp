/*
 * FileParser.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "FileParser.h"

FileParser::FileParser() {

}

void FileParser::parseFile(Queue *q, std::string fileName) {
	std::ifstream in(fileName, std::ios::in|std::ios::binary);
	int blocksNeeded = 0, currSize = 0;
	in.seekg(0, std::ios::end);
	long fileSize = in.tellg();
	in.seekg(0, std::ios::beg);

	blocksNeeded = fileSize / (MAX_BLOCK_SIZE*2);

	short *blockBuffer = new short[1024];
	for (int i = 0; i < blocksNeeded; i++) {
		//short *blockBuffer = new short[1024];
		//if it is the last block to read(can be smaller then 1024
		if(i == blocksNeeded-1) currSize = fileSize%MAX_BLOCK_SIZE;
		else currSize = MAX_BLOCK_SIZE;

		in.read((char *)blockBuffer, currSize*2);

		Block nb(i, blockBuffer, currSize);
		q->put(&nb);
	}
	in.close();
}

FileParser::~FileParser() {
	// TODO Auto-generated destructor stub
}

