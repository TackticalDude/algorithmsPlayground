/*
 * Equalizer.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef EQUALIZER_H_
#define EQUALIZER_H_

#include "CommandHandler.h"
#include "Queue.h"
#include "FileParser.h"

class Equalizer{
private:

public:
	CommandHandler _commandHandler;
	Queue _blockQueue;
	FileParser _fileParser;

	Equalizer(int argc, char *argv[]);
	void writeOut();
	void equalizeBass();
	void equalizeTreble();
	void threadProcessor();
	~Equalizer();
};



#endif /* EQUALIZER_H_ */
