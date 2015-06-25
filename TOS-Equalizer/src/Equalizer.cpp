/*
 * Equalizer.cpp
 *
 *  Created on: May 26, 2015
 *      Author: TackticalDude
 */

#include "Equalizer.h"

int main(int argc, char *argv[]) {
	Equalizer eq(argc, argv);

}

Equalizer::Equalizer(int argc, char *argv[]){
	_commandHandler.handleStartCommands(argc, argv);
	_fileParser.parseFile(&_blockQueue, _commandHandler.getInputFileName());
	std::cout << "Parsed file into " << _blockQueue.getQueueSize() << " blocks." <<std::endl;
	writeOut();
}

void Equalizer::writeOut(){
	_blockQueue.writeToFile(_commandHandler.getOutputFileName());
	std::cout << "Data exported to file : " << _commandHandler.getOutputFileName() << std::endl;
}

Equalizer::~Equalizer(){

}
