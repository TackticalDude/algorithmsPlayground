/**
 * @headerfile CommandHandler.h
 * @author Zakaria el Barnoussi (TackticalDude)
 * @version 0.1
 */

#include "Equalizer.h"

/**
 * @name Constuctor
 * @param from - Queue object pointer to request Blocks from
 * @param to - Queue object pointer to write Block to
 * @param treble - biquad structure which contains the b0,b1,b2,a1 and a2 values for the treble
 * @param bass - biquad structure which contains the b0,b1,b2,a1 and a2 values for the bass
 */
Equalizer::Equalizer(Queue *from, Queue *to, biquad_t treble, biquad_t bass){
	_from = from;
	_to = to;
	_treble = treble;
	_bass = bass;

	finished = false;

	std::cout << "Created equalizer" << std::endl;

	_objThread = std::thread(&Equalizer::run, this);
}

/**
 * @name Constructor
 * @param from - Queue object pointer to request Blocks from
 * @param to - Queue object pointer to write Block to
 * @param treble - biquad structure which contains the b0,b1,b2,a1 and a2 values for the treble
 * @param bass - biquad structure which contains the b0,b1,b2,a1 and a2 values for the bass
 * @param name - string name for the object (for debug things)
 */
Equalizer::Equalizer(Queue *from, Queue *to, biquad_t treble, biquad_t bass, std::string name){
	_from = from;
	_to = to;
	_treble = treble;
	_bass = bass;

	finished = false;
	_name = name;
	std::cout << "Created equalizer" << std::endl;

	_objThread = std::thread(&Equalizer::run, this);
}

/**
 * @name stop
 * @brief makes the thread stop running.
 */
void Equalizer::stop(){
	finished = true;
}

void Equalizer::run(){
	while(!finished){
		Block *toProcess = _from->requestBlock();

		int blockSize = toProcess->getSize();

		if (toProcess == NULL) {
			std::cout << "Thread stopped running because of break" << std::endl;
			break;
		}

		short *yBuffer = (short *) malloc(sizeof(short) * blockSize);
		short *xBuffer = toProcess->getDataChunk();

		for (int n = 0; n < toProcess->getSize(); n++) {
			yBuffer[n] = _bass.b0 * xBuffer[n]
					+ _bass.b1 * (n - 1 > 0 ? xBuffer[n - 1] : 0) //protection against negative indexes
					+ _bass.b2 * (n - 2 > 0 ? xBuffer[n - 2] : 0)
					+ _bass.a1 * (n - 1 > 0 ? yBuffer[n - 1] : 0)
					+ _bass.a2 * (n - 2 > 0 ? yBuffer[n - 2] : 0);
		}

		for (int n = 0; n < toProcess->getSize(); n++) {
			yBuffer[n] = _treble.b0 * xBuffer[n]
					+ _treble.b1 * (n - 1 > 0 ? xBuffer[n - 1] : 0) //protection against negative indexes
					+ _treble.b2 * (n - 2 > 0 ? xBuffer[n - 2] : 0)
					+ _treble.a1 * (n - 1 > 0 ? yBuffer[n - 1] : 0)
					+ _treble.a2 * (n - 2 > 0 ? yBuffer[n - 2] : 0);
		}

		_to->put(toProcess);
	}
}

/**
 * @name Deconstructor
 * @brief joins the main thread to make sure the threads is stopped propperly
 */
Equalizer::~Equalizer() {
	this->_objThread.join();
}

