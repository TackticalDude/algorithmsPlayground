/*
 * FileParser.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include "Queue.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#define MAX_BLOCK_SIZE 1024

/**
 * @class FileParser
 * @brief Parses a file into blocks and places them in a Queue
 */
class FileParser {
public:
	FileParser();
	void parseFile(Queue *q, std::string fileName);
	virtual ~FileParser();
};

#endif /* FILEPARSER_H_ */
