/*
 * CommandHandler.h
 *
 *  Created on: May 26, 2015
 *      Author: TackticalDude
 */

#ifndef COMMANDHANDLER_H_
#define COMMANDHANDLER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "getopt.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @class CommandHandler
 * @brief used to parse the arguments when started this program
 */
class CommandHandler{
private:
	int pValue;
	int bValue;
	int tValue;
	std::string inputFileName;
	std::string outputFileName;
public:
	CommandHandler();
	int handleStartCommands(int argc, char **argv);
	std::string getInputFileName();
	std::string getOutputFileName();
	int getThreadAmount();
	int getBassIntensity();
	int getTrebleIntensity();
	bool commandCheck();
};


#endif /* COMMANDHANDLER_H_ */
