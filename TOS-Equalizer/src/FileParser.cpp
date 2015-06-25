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
	FILE *fp;
	int blocksNeeded = 0, currSize = 0;
	long fileSize = 0;
	char *blockBuffer = NULL;

	fp = fopen(fileName.c_str(), "r");
	if (!fp)
		std::cout << "parseFile(): failed to open file" << std::endl, exit(1);

	fseek(fp, 0L, SEEK_END);
	fileSize = ftell(fp);
	rewind(fp);

	blocksNeeded = fileSize / MAX_BLOCK_SIZE;

	for (int i = 0; i < blocksNeeded; i++) {
		blockBuffer = (char *) malloc(sizeof(char) * MAX_BLOCK_SIZE);
		//if it is the last block to read(can be smaller then 1024
		if(i == blocksNeeded-1) currSize = fileSize%MAX_BLOCK_SIZE;
		else currSize = MAX_BLOCK_SIZE;

		if (!fread(blockBuffer, currSize, 1, fp))
					std::cout << "parseFile(): failed to fread" << std::endl, exit(1);

		Block nb(i, blockBuffer, currSize);
		q->addBlock(&nb);
	}

	fclose(fp);
}

FileParser::~FileParser() {
	// TODO Auto-generated destructor stub
}

