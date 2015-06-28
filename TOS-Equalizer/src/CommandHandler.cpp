/*
 * CommandHandler.cpp
 *
 *  Created on: May 26, 2015
 *      Author: TackticalDude
 */

#include "CommandHandler.h"

CommandHandler::CommandHandler() {

}

int CommandHandler::handleStartCommands(int argc, char **argv) {
	int getopt_ret = 0;

	while ((getopt_ret = getopt(argc, argv, "p:b:t:")) != -1) {
		switch (getopt_ret) {
		case 0:
			printf("something with extra options: %s\n", optarg);
			break;
		case 'p':
			pValue = atoi(optarg);
			printf("pthread %d\n", pValue);
			break;
		case 'b':
			bValue = atoi(optarg);
			printf("bass %d\n", bValue);
			break;
		case 't':
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

	if (argv[optind]) {
		this->inputFileName = argv[optind];
		optind++;
	} else {
		printf("No input file specified\n");
	}

	if (argv[optind]) {
		this->outputFileName = argv[optind];
		optind++;
	} else {
		printf("No output file specified\n");
	}
	if (!commandCheck())
		exit(1);
	return 0;
}

bool CommandHandler::commandCheck() {
	if (pValue < 2 || pValue > 8) {
		std::cout << "thread amount must be between 2 and 8" << std::endl;
		return false;
	}
	if (bValue < -6 || bValue > 6) {
		std::cout << "base intensity must be between -6 and 6" << std::endl;
		return false;
	}
	if (tValue < -6 || tValue > 6) {
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

std::string CommandHandler::getInputFileName(){
	return this->inputFileName;
}

std::string CommandHandler::getOutputFileName(){
	return this->outputFileName;
}

int CommandHandler::getThreadAmount(){
	return this->pValue;
}

int CommandHandler::getBassIntensity(){
	return this->bValue;
}

int CommandHandler::getTrebleIntensity(){
	return this->tValue;
}
