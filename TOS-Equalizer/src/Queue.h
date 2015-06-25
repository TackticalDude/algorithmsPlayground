/*
 * Queue.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Block.h"
#include <iostream>
#include <vector>

class Queue {
private:
	std::vector<Block *> _blockQueue;
public:
	Queue();
	void addBlock(Block *toAdd);
	void emptyQueue();
	int getQueueSize();
	void writeToFile(std::string outFile);
	virtual ~Queue();
};

#endif /* QUEUE_H_ */
