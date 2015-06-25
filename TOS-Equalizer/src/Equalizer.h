/*
 * Equalizer.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef EQUALIZER_H_
#define EQUALIZER_H_

#include <thread>
#include "CommandHandler.h"
#include "Queue.h"
#include "FileParser.h"
#include "Coefficient.h"

typedef struct{
	double b0, b1, b2, a1, a2;
}biquad;

class Equalizer{
private:
	biquad bass;
	biquad treble;
public:
	CommandHandler _commandHandler;
	Queue _blockQueue;
	Queue _endQueue;
	FileParser _fileParser;

	Equalizer(int argc, char *argv[]);
	void writeOut();
	void equalizeBass();
	void equalizeTreble();
	void equalize();
	void calculateBiquad();
	Block *requestBlock();
	~Equalizer();
};



#endif /* EQUALIZER_H_ */
