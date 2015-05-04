/*
 * SearchEngine.cpp
 *
 *  Created on: May 4, 2015
 *      Author: TackticalDude
 */

#include "SearchEngine.h"

static int threadCount = 0;
static std::map<std::string, int> results;

SearchEngine::SearchEngine(){
	threadCount++;
	results.insert(results.begin(), std::pair<std::string, int>(std::string(""), 0));
}

/*
* @name startFileSearch
* @param fd - name of the file in string format
* @param number - number to look for in file
* @return - see enum ERROR_NAMES
*/
ERROR_NAMES SearchEngine::startFileSearch(std::string fd, int number){
	std::ifstream fp;
	std::string line;
	if (number < 0) return INVALID_NUMBER;
	std::string num = std::to_string(number);
	int result = 0;
	fp.open(fd);
	if (fp.is_open()){													//check whether file is opened
		while (std::getline(fp, line)){									//loop thru lines in file
			for (int i = 0; i < line.length(); i++){					//loop thru line char by char
				if (line[i] == num[0]){									//check on first char of num string
					if (num.length() == 1) result++;					//if looking for single digit
					for (int j = 1; (j < num.length())
								&& (j + i < line.length()); j++){		//loop thru number given in parameter to check whole number
						if (num[j] != line[i + j]) break;
						if (j == num.length() - 1 && num[j] == line[i + j]) result++;//if last chars are the same the search engine has found the number
					}
				}
			}
		}
	}else return FAILED_TO_OPEN_FILE;
	addResult(fd, result);
	return SUCCES;
}

/*
* @name startDirSearch
* @brief searches in every file in the given directory. For each file there will be a thread started. the result will be placed in the results map
* @param fullDirPath - full path to the direcotry to search in
* @param number - number to search
* @return - see enum ERROR_NAMES
*/
ERROR_NAMES SearchEngine::startDirSearch(std::string fullDirPath, int number){
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir(fullDirPath.c_str())) != NULL) {
		// print all the files and directories within directory
		while ((ent = readdir(dir)) != NULL) {
			std::thread searchThread(&SearchEngine::startFileSearch, this, std::string(ent->d_name), number);	//start thread for each file
			searchThread.join();
		}
		closedir(dir);
	} else {
		perror("");	// could not open directory
		return FAILED_TO_OPEN_DIR;
	}
	return SUCCES;
}

/*
* @name getThreadCount
* @return threadCount - the amount of threads that are running
* @todo update this function
*/
int SearchEngine::getThreadCount(){
	return threadCount;
}

/*
* @name showTop10
* @brief - print the results in the terminal
* @todo rename function
*/
void SearchEngine::showTop10(){
	std::cout << " Results: " << std::endl;
	std::cout << "File name \t\t result" << std::endl;
	for (it_type iterator = results.begin(); iterator != results.end(); iterator++) {
		std::cout << iterator->first << ":\t\t" << iterator->second << std::endl;
	}
}

/*
* @name clearTop10
* @brief clears the results in the result <map>
* @todo rename function
*/
void SearchEngine::clearTop10(){
	results.erase(results.begin(), results.end());
}

/*
* @name addResult
* @brief adds result to the result map on the position, so the map will be sorted from most count to least counts
* @param fileName - the name of the file
* @param result - the count of how many times the number is found in the file
* @todo fix sorting thing
*/
void SearchEngine::addResult(std::string fileName, int result){
	for (it_type iterator = results.begin(); iterator != results.end(); iterator++) {
		if (result > iterator->second){
			iterator--;
			results.insert(iterator, std::pair<std::string, int>(std::string(fileName), result));
			break;
		}
	}
}
