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

//static struct option long_options[]={
//		{"phreads", required_argument, 0, 'p'},
//		{"bass", required_argument, 0, 'b'},
//		{"treble", required_argument, 0, 't'}
//		/*{"input", required_argument, 0, 0},
//		{"output", required_argument, 0, 0},
//		{0,0,0,0}*/
//};

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
