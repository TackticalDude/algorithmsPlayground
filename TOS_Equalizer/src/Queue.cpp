/**
 * @headerfile Queue.h
 * @author Zakaria el Barnoussi (TackticalDude)
 * @brief This class contains a array of blocks and counters to remember size and amount of blocks requested.
 */

#include "Queue.h"

/**
 * @name Constructor
 * @brief initializes block counter and size
 */
Queue::Queue() {
	_blockCnt = 0;
	_size = 0;
}

/**
 * @name put
 * @param toAdd - block to add to the _blockQueue vector
 * @brief adds block to end of queue
 */
void Queue::put(Block *toAdd){
	_putBlock.lock();
	std::cout << "Added Block " << std::dec << toAdd->getID() << " to Queue by thread " << std::this_thread::get_id() << std::endl;
	_blockQueue.push_back(toAdd);
	_size++;
	_putBlock.unlock();
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
 * @return size of queue on a given moment
 */
int Queue::getQueueSize(){
	return _size;
}

/**
 * @name getBlockCount
 * @return the block counter value
 */
int Queue::getBlockCount(){
	return _blockCnt;
}

/**
 * @name writeToFile
 * @param string outfile
 */
void Queue::writeToFile(std::string outFile){
	std::ofstream out(outFile, std::ofstream::binary);
	for (std::vector<Block *>::iterator it = _blockQueue.begin() ; it != _blockQueue.end(); ++it){
		out.write((char *)(*it)->getDataChunk(), ((*it)->getSize())*2);
	}
	out.close();
	std::cout << "Wrote queue to file " << outFile << " with " << getQueueSize() << " blocks."<< std::endl;
}

/**
 * @name at
 * @param n - element to return
 * @return A block pointer which is on the n'th element of vector _blockQueue
 */
Block *Queue::at(unsigned int n){
	return _blockQueue.at(n);
}

/**
 * @name requestBlock
 * @return a block pointer
 * @brief when a thread requests a block to process, this function returns a pointer to the block which should be processed
 */
Block *Queue::requestBlock(){
	_requestBlock.lock();

	Block *it;
	if(_blockCnt >= _blockQueue.size()) it = NULL;
	else{
		it = _blockQueue.at(_blockCnt);
		_blockCnt++;
		std::cout << "Requested Block : " << _blockCnt << " by " << std::this_thread::get_id() << std::endl;
	}

	_requestBlock.unlock();
	return it;
}

/**
 * @name isEmpty
 * @return true when _blockQueue is empty, false when _blockQueue when not emtpy
 */
bool Queue::isEmpty(){
	return _blockQueue.empty();
}

/**
 * @name Deconstructor
 */
Queue::~Queue() {

}

