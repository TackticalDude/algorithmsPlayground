/**
 * @headerfile CommandHandler
 * @author Zakaria el Barnoussi (TackticalDude)
 * @version 0.1
 */

#include "FileParser.h"

/**
 * @name Constructor
 */
FileParser::FileParser() {

}

/**
 * @name parseFile
 * @param q - Queue object pointer to place the parsed data in
 * @param fileName - name of the file in std::string format
 */
void FileParser::parseFile(Queue *q, std::string fileName) {
	std::ifstream in(fileName, std::ios::in|std::ios::binary);
	int blocksNeeded = 0, currSize = 0;

	in.seekg(0, std::ios::end);
	long fileSize = in.tellg();
	in.seekg(0, std::ios::beg);

	blocksNeeded = fileSize / (MAX_BLOCK_SIZE*2);

	short *blockBuffer = new short[1024];
	for (int i = 0; i < blocksNeeded; i++) {
		//short *blockBuffer = new short[1024];
		//if it is the last block to read(can be smaller then 1024
		if(i == blocksNeeded-1) currSize = fileSize%MAX_BLOCK_SIZE;
		else currSize = MAX_BLOCK_SIZE;

		in.read((char *)blockBuffer, currSize*2);

		Block *nb = new Block(i, blockBuffer, currSize);
		q->put(nb);
	}
	in.close();
}

/**
 * @name Deconstructor
 */
FileParser::~FileParser() {
	// TODO Auto-generated destructor stub
}

