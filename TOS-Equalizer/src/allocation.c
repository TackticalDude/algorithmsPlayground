/*
 * allocation.c
 *
 *  Created on: Jun 27, 2015
 *      Author: TackticalDude
 */
#include "allocation.h"

short * c_malloc(unsigned int size){
	short *ptr = malloc(size);
	return ptr;
}
