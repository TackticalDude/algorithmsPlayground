/*
 * Queue.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "Queue.h"

Queue::Queue() {

}

void Queue::addBlock(Block *toAdd){
	_blockQueue.push_back(toAdd);
}

void Queue::emptyQueue(){
	_blockQueue.clear();
}

int Queue::getQueueSize(){
	return _blockQueue.size();
}

void Queue::writeToFile(std::string outFile){
	FILE *fp;
	fp = fopen(outFile.c_str(), "w+");

	if(fp==NULL) std::cout << "writeToFile(): failed to open file" << std::endl, exit(1);

	for (std::vector<Block *>::iterator it = _blockQueue.begin() ; it != _blockQueue.end(); ++it){
		fwrite((*it)->getDataChunk(), sizeof(char), 1024, fp);
	}

	fclose(fp);
}

Queue::~Queue() {
//	for (std::vector<Block *>::iterator it = _blockQueue.end() ; it != _blockQueue.begin(); --it){
//		_blockQueue.pop_back();
//		(*it)->~Block();
//	}
//	_blockQueue.clear();
}

