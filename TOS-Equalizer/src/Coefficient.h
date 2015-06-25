/*
 * Coefficient.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef COEFFICIENT_H_
#define COEFFICIENT_H_

#include <math.h>

class Coefficient {
public:
	Coefficient();
	void bassCoffiecient(int intensity, double *b0, double *b1, double *b2, double *a1, double *a2);
	void trebleCofficient(int intensity, double *b0, double *b1, double *b2, double *a1, double *a2);
	virtual ~Coefficient();
};

#endif /* COEFFICIENT_H_ */
