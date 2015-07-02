/*
 * Equalizer.h
 *
 *  Created on: Jun 29, 2015
 *      Author: TackticalDude
 */

#ifndef EQUALIZER_H_
#define EQUALIZER_H_

#include "Coefficient.h"
#include "Queue.h"
#include <thread>
#include <stdlib.h>
#include <iostream>
#include <string>

/**
 * @class Equalizer
 * @brief Makes a thread to recalculate blocks
 */
class Equalizer {
private:
	Queue *_from;
	Queue *_to;
	biquad_t _treble;
	biquad_t _bass;

	std::thread _objThread;
	std::string _name;

	bool finished;
public:
	Equalizer(Queue *form, Queue *to, biquad_t treble, biquad_t bass);
	Equalizer(Queue *form, Queue *to, biquad_t treble, biquad_t bass, std::string name);
	void run();
	void stop();
	~Equalizer();
};

#endif /* EQUALIZER_H_ */
