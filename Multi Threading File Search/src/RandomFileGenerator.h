/*
 * RandomFileGenerator.h
 *
 *  Created on: May 4, 2015
 *      Author: TackticalDude
 */

#ifndef RANDOMFILEGENERATOR_H_
#define RANDOMFILEGENERATOR_H_

#include <string>
#include <fstream>
#include <cstdlib>

class RandomFileGenerator{
public:
	RandomFileGenerator();
	void generateRandomFile(std::string fileName);
	void generateRandomFile(std::string fileName, int lines, int width, bool number, bool lowerCase, bool upperCase);
};

#endif /* RANDOMFILEGENERATOR_H_ */
