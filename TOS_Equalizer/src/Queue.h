/*
 * Queue.h
 *
 *  Created on: Jun 29, 2015
 *      Author: TackticalDude
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Block.h"
#include <mutex>
#include <vector>
#include <fstream>
#include <iostream>
#include <thread>

/**
 * @class Queue
 * @brief contains a thread save block request function and Block vector
 */
class Queue {
private:
	unsigned int _blockCnt;
	int _size;

	std::vector<Block *> _blockQueue;
	std::mutex _requestBlock;
	std::mutex _putBlock;
public:
	Queue();
	Block *requestBlock();
	Block *at(unsigned int n);
	int getQueueSize();
	int getBlockCount();
	bool isEmpty();
	void put(Block *toAdd);
	void emptyQueue();
	void writeToFile(std::string outFile);
	~Queue();
};

#endif /* QUEUE_H_ */
