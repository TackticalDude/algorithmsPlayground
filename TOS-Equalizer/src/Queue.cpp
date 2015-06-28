/*
 * Queue.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "Queue.h"

Queue::Queue() {

}
/**
 * @name put
 * @param toAdd - block to add
 * @brief adds block to end of queue
 */
void Queue::put(Block *toAdd){
	_blockQueue.push_back(toAdd);
}

/**
 * @name emptyQueue
 * @brief clears the queue
 */
void Queue::emptyQueue(){
	_blockQueue.clear();
}

/**
 * @name getQueueSize
 * @return int - size of queue on a given moment
 */
int Queue::getQueueSize(){
	return _blockQueue.size();
}

/**
 * @name writeToFile
 * @param string outfile
 */
void Queue::writeToFile(std::string outFile){
	std::ofstream out(outFile, std::ofstream::binary);
	for (std::vector<Block *>::iterator it = _blockQueue.begin() ; it != _blockQueue.end(); ++it){
		out.write((char *)(*it)->getDataChunk(), ((*it)->getSize())*2);
		std::vector<Block *>::iterator ittemp = it + 1;
		std::cout << (*it)->getDataChunk() << std::endl;
	}
	out.close();
}

Block *Queue::at(unsigned int n){
	return _blockQueue.at(n);
}

Queue::~Queue() {
//	for (std::vector<Block *>::iterator it = _blockQueue.end() ; it != _blockQueue.begin(); --it){
//		_blockQueue.pop_back();
//		(*it)->~Block();
//	}
//	_blockQueue.clear();
}

