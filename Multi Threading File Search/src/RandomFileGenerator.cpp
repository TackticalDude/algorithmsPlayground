/*
 * RandomFileGenerator.cpp
 *
 *  Created on: May 4, 2015
 *      Author: TackticalDude
 */

#include "RandomFileGenerator.h"

/*
* @name RandomFileGenerator
* @brief RandomFileGenerator with nothing in it
*/
RandomFileGenerator::RandomFileGenerator(){

}

/*
* @name generateRandomFile
* @brief generates a file with random data, the name of the file is the name given in as parameter
* @param fileName - the name of the file
*/
void RandomFileGenerator::generateRandomFile(std::string fileName){
	std::ofstream outfile(fileName);
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < 10; j++){
			int randInt = rand() % 63;
			if (randInt < 10) outfile << randInt+48;		//the 0 char is on position 48(30h)
			else if (randInt < 36) outfile << randInt+55;	//the uppercase alphabet starts at 65. -10 because the first 10 numbers are for 0-9
			else if (randInt < 62) outfile << randInt+61;
		}
	}
	outfile.close();
}

/*
* @name generateRandomFile
* @brief generates random file with data. The amount of lines and the amount of chars per line can be given in parameter.
* @param fileName - the name of the file
* @param lines - amount of lines that should be generated
* @param width - amount of char per line
* @param number - when true the file will contain numbers
* @param lowerCase - when true the file will contain lowercase characters
* @param upperCase - when true the file will contain uppercase characters
* @warning this function file overwrite the file if it already exists
*/
void RandomFileGenerator::generateRandomFile(std::string fileName, int lines, int width, bool number, bool lowerCase, bool upperCase){
	std::ofstream outfile(fileName);
	int compare = 63;
	if (number && !lowerCase && !upperCase) compare = 10; //when only numbers is true the random generated number shouldn't be bigger then 10
	if (!number && !lowerCase && upperCase) compare = 36; //when only uppercase is selected the random generated number shouldn't be bigger then 36(26+10)
															//no need for if statement for only lowercase selected because the lowercase comes last in next for loop
	for (int i = 0; i < lines; i++){
		for (int j = 0; j < width; j++){
			int randInt = rand() % compare;
			if (randInt < 10 && number){
				char outChar = (char)randInt + 48;				//to convert int to char it is needed to add 48, the 0 character starts at 48(30h)
				outfile << outChar;
			}else if (randInt < 10 && !number) randInt+=10;		//if number is not true 10 should be added to the random generated int (to skip 0-9)

			if (randInt < 36 && upperCase && randInt >= 10){
				char outChar = (char)randInt + 55;
				outfile << outChar;
			}else if (randInt < 36 && !upperCase && randInt >= 10) randInt+=26;

			if (randInt < 62 && lowerCase && randInt > 36){
				char outChar = (char)randInt + 61;
				outfile << outChar;
			}

		}
		outfile << std::endl;
	}
	outfile.close();
}
