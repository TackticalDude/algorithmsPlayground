/*
 * SearchEngine.h
 *
 *  Created on: May 4, 2015
 *      Author: TackticalDude
 */

#ifndef SEARCHENGINE_H_
#define SEARCHENGINE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <sstream>
#include <dirent.h>
#include <map>
using namespace std;

/*
* SUCCES - when nothing goes wrong
* FAILED_TO_OPEN_FILE - the function failed to open the file
* FAILED_TO_CLOSE_FILE - the function failed to close the file
* FAILED_TO_OPEN_DIR - the function failed to open the dir(make sure the path is right)
* FAILED_TO_CLOSE_DIR - the function failed to close the direcotry
* FILE_NOT_FOUND - when the file does not exist
* DIR_NOT_FOUND - directory not found
* UNKOWN_ERROR - ...
* INVALID_NUMBER - number given in parameter is invalid(no negative numbers)
*/
enum ERROR_NAMES{
	SUCCES,
	FAILED_TO_OPEN_FILE,
	FAILED_TO_CLOSE_FILE,
	FAILED_TO_OPEN_DIR,
	FAILED_TO_CLOSE_DIR,
	FILE_NOT_FOUND,
	DIR_NOT_FOUND,
	UNKOWN_ERROR,
	INVALID_NUMBER
};

typedef std::map<std::string, int>::iterator it_type;

class SearchEngine{
public:
	SearchEngine();
	ERROR_NAMES startFileSearch(std::string file, int number);
	ERROR_NAMES startDirSearch(std::string fullDirPath, int number);
	int getThreadCount();
	/*Result functions*/
	static void showTop10();
	static void clearTop10();
	static void addResult(std::string fileName, int result);
};

#endif /* SEARCHENGINE_H_ */
