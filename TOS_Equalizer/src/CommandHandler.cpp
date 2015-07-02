/**
 * @class CommandHandler
 * @author Zakaria el Barnoussi (TackticalDude)
 * @version 0.1
 */

#include "CommandHandler.h"

/**
 * @name Constructor
 */
CommandHandler::CommandHandler() {

}

/**
 * @name handleStartCommands
 * @param argc - argument count
 * @param argv - argument array
 * @return 0 when completed
 * @brief parses parameters
 */
int CommandHandler::handleStartCommands(int argc, char **argv) {
	int getopt_ret = 0;

	while ((getopt_ret = getopt(argc, argv, "p:b:t:")) != -1) {
		switch (getopt_ret) {
		case 0:
			printf("something with extra options: %s\n", optarg);
			break;
		case 'p'://parse -p argument (thread amount)
			pValue = atoi(optarg);
			printf("pthread %d\n", pValue);
			break;
		case 'b'://parse -b argument (bass intensity)
			bValue = atoi(optarg);
			printf("bass %d\n", bValue);
			break;
		case 't'://parse -t argument (treble intensity)
			tValue = atoi(optarg);
			printf("treble %d\n", tValue);
			break;
		case '?': /* Invalid option */
			printf(
					"Usage: %s [-p threads] [-b dB(bass)] [-t dB(treble)] <input file> <output file>\n",
					argv[0]);
			break;
		default:
			printf("hmmmm\n");
		}
	}

	if (argv[optind]) {//input file name is first file name argument
		this->inputFileName = argv[optind];
		optind++;
	} else {
		printf("No input file specified\n");
	}

	if (argv[optind]) {//output file name is second file name argument
		this->outputFileName = argv[optind];
		optind++;
	} else {
		printf("No output file specified\n");
	}
	if (!commandCheck())
		exit(1);
	return 0;
}

/**
 * @name commandCheck
 * @return true when commands are valid, falsewhen commands are invalid
 * @brief checks wheter commands are valid
 */
bool CommandHandler::commandCheck() {
	if (pValue < 2 || pValue > 8) {//The thread amount must be between 2 and 6
		std::cout << "thread amount must be between 2 and 8" << std::endl;
		return false;
	}
	if (bValue < -6 || bValue > 6) {//bass intensity must be between 6 and -6 dB
		std::cout << "base intensity must be between -6 and 6" << std::endl;
		return false;
	}
	if (tValue < -6 || tValue > 6) {//treble intensity must be between 6 and -6 dB
		std::cout << "treble intensity must be between -6 and 6" << std::endl;
		return false;
	}

	std::ifstream ifs(inputFileName.c_str(), std::ifstream::in);
	if (!ifs.is_open()) {
		std::cout << "input file not found" << std::endl;
		return false;
	}else{
		std::cout << "input file : " << inputFileName << std::endl;
	}
	ifs.close();

	std::ifstream ofs(outputFileName.c_str(), std::ifstream::out);
	if (!ofs.is_open()) {
		std::cout << "output file not found" << std::endl;
		return false;
	}
	else{
		std::cout << "output file : " << outputFileName << std::endl;
	}
	ifs.close();

	return true;
}

/**
 * @name getInputFileName
 * @return string - file name of the input file
 */
std::string CommandHandler::getInputFileName(){
	return this->inputFileName;
}

/**
 * @name getOutputFileName
 * @return string - file name of the output file
 */
std::string CommandHandler::getOutputFileName(){
	return this->outputFileName;
}

/**
 * @name getThreadAmount
 * @return amount of threads given in the argument list, -p
 */
int CommandHandler::getThreadAmount(){
	return this->pValue;
}

/**
 * @name getBassIntensity
 * @return intensity of the bass given in the argument list -b
 */
int CommandHandler::getBassIntensity(){
	return this->bValue;
}

/**
 * @name getTrebleIntensity
 * @return intensity of the treble given in the argument list -t
 */
int CommandHandler::getTrebleIntensity(){
	return this->tValue;
}
