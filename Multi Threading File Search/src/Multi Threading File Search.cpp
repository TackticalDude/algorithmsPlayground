#include "SearchEngine.h"
#include "RandomFileGenerator.h"

int main(){
	SearchEngine sr;
	sr.startDirSearch("C:\\Users\\TackticalDude\\Documents\\Visual Studio 2013\\Projects\\ConsoleApplication1\\ConsoleApplication1", 8963);
	sr.showTop10();

	/*RandomFileGenerator rfg;
	std::string fileName;
	for (int i = 0; i < 10; i++){
		fileName = "randomDataFile" + i + std::string(".txt");
		rfg.generateRandomFile(fileName, 10000, 35, true, false, false);
	}*/

	while (1){

	}
	return 0;
}
