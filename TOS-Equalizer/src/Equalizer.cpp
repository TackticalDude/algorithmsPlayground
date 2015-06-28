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

/**
 * Constructor
 * @brief start of the entier program.
 */
Equalizer::Equalizer(int argc, char *argv[]) {
	_blockCnt = 0;
	_commandHandler.handleStartCommands(argc, argv);
	_fileParser.parseFile(&_blockQueue, _commandHandler.getInputFileName());
	std::cout << "Parsed file into " << _blockQueue.getQueueSize() << " blocks."
			<< std::endl;
	calculateBiquad();
	/*for(int i=0;i<_blockQueue.getQueueSize();i++){
		equalizeBass();
	}
	_blockCnt = 0;
	for(int i=0;i<_blockQueue.getQueueSize();i++){
		equalizeTreble();
	}*/
	writeOut();
}

/**
 * @name writeOut
 * @brief writes a queue of blocks out to a file. The file is the filename given as parameter when started this program
 */
void Equalizer::writeOut() {
	_blockQueue.writeToFile(_commandHandler.getOutputFileName());
	std::cout << "Data exported to file : "
			<< _commandHandler.getOutputFileName() << std::endl;
}

/**
 * @name equalize
 * @brief creates the amount of threads given as parameter and makes the thread make calculations
 */
void Equalizer::equalize() {
	for (int i = 0; i < _commandHandler.getThreadAmount(); i++) {
//		std::thread t(equalizeBass);
//		t.join();
	}
}

/**
 * @name calculateBiquad
 * @brief calculates the biquad values for the bass and treble. The results are placed in the bass and treble variable
 */
void Equalizer::calculateBiquad() {
	Coefficient c;
	c.bassCoffiecient(_commandHandler.getBassIntensity(), &(bass.b0),
			&(bass.b1), &(bass.b2), &(bass.a1), &(bass.a2));
	c.trebleCofficient(_commandHandler.getTrebleIntensity(), &(treble.b0),
			&(treble.b1), &(treble.b2), &(treble.a1), &(treble.a2));
}

/**
 * @name equalizeBass
 * @brief performs bass calculation over a block
 */
void Equalizer::equalizeBass() {
	Block *bl = requestBlock();
	int blockSize = bl->getSize();

	if (bl == NULL) /*sleep*/
		;

	for (int n = 0; n < bl->getSize(); n++) {
		short *yBuffer = (short *) malloc(sizeof(short) * blockSize);
		short *xBuffer = bl->getDataChunk();

		yBuffer[n] = bass.b0 * xBuffer[n]
				+ bass.b1 * (n - 1 > 0 ? xBuffer[n - 1] : 0)	//protection against negative indexes
				+ bass.b2 * (n - 2 > 0 ? xBuffer[n - 2] : 0)
				+ bass.a1 * (n - 1 > 0 ? yBuffer[n - 1] : 0)
				+ bass.a2 * (n - 2 > 0 ? yBuffer[n - 2] : 0);
	}
}

/**
 * @name equalizeTreble
 * @brief performs treble calculation over a block
 */
void Equalizer::equalizeTreble() {
	Block *bl = requestBlock();
	int blockSize = bl->getSize();

	if (bl == NULL) /*sleep*/
		;

	for (int n = 0; n < bl->getSize(); n++) {
		short *yBuffer = (short *) malloc(sizeof(short) * blockSize);
		short *xBuffer = bl->getDataChunk();

		yBuffer[n] = bass.b0 * xBuffer[n]
				+ bass.b1 * (n - 1 > 0 ? xBuffer[n - 1] : 0)	//protection against negative indexes
				+ bass.b2 * (n - 2 > 0 ? xBuffer[n - 2] : 0)
				+ bass.a1 * (n - 1 > 0 ? yBuffer[n - 1] : 0)
				+ bass.a2 * (n - 2 > 0 ? yBuffer[n - 2] : 0);
	}
}

Block *Equalizer::requestBlock() {
	return _blockQueue.at(_blockCnt++);
}

Equalizer::~Equalizer() {

}
