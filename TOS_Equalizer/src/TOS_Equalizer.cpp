//============================================================================
// Name        : TOS_Equalizer.cpp
// Author      : TackticalDude
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "CommandHandler.h"
#include "Coefficient.h"
#include "Queue.h"
#include "FileParser.h"
#include "Equalizer.h"

int main(int argc, char *argv[]) {
	CommandHandler ch;
	FileParser fp;
	Queue startQueue;
	Queue endQueue;
	biquad_t treble;
	biquad_t bass;

	ch.handleStartCommands(argc, argv);
	fp.parseFile(&startQueue, ch.getInputFileName());
	std::cout << "Parsed file into " << startQueue.getQueueSize() << " blocks."
			<< std::endl;

	Coefficient c;
	c.bassCoeffiecient(ch.getBassIntensity(), &(bass.b0), &(bass.b1), &(bass.b2),
			&(bass.a1), &(bass.a2));
	c.trebleCoefficient(ch.getTrebleIntensity(), &(treble.b0), &(treble.b1),
			&(treble.b2), &(treble.a1), &(treble.a2));

	Equalizer *eq1 = new Equalizer(&startQueue, &endQueue, treble, bass, "Eq1");
	Equalizer *eq2 = new Equalizer(&startQueue, &endQueue, treble, bass, "Eq2");
	Equalizer *eq3 = new Equalizer(&startQueue, &endQueue, treble, bass, "Eq3");
	Equalizer *eq4 = new Equalizer(&startQueue, &endQueue, treble, bass, "Eq4");
	Equalizer *eq5 = new Equalizer(&startQueue, &endQueue, treble, bass, "Eq5");
	Equalizer *eq6 = new Equalizer(&startQueue, &endQueue, treble, bass, "Eq6");

	while (startQueue.getQueueSize() > startQueue.getBlockCount())
		;

	eq1->stop();
	eq2->stop();
	eq3->stop();
	eq4->stop();
	eq5->stop();
	eq6->stop();

	endQueue.writeToFile(ch.getOutputFileName());
	return 0;
}
