/*
 * Coefficient.h
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#ifndef COEFFICIENT_H_
#define COEFFICIENT_H_

#include <math.h>

/**
 * @struct biquad_t
 * @brief Contains doubles for bass and treble calculations
 * 			b0 - b coefficient 0
 * 			b1 - b coefficient 1
 * 			b2 - b coefficient 2
 * 			a0 - a coefficient 0
 * 			a1 - a coefficient 1
 */
typedef struct{
	double b0, b1, b2, a1, a2;
}biquad_t;

/**
 * @class Coefficient
 * @brief can calculate the coefficients needed to adjust treble and bass
 */
class Coefficient {
public:
	Coefficient();
	void bassCoeffiecient(int intensity, double *b0, double *b1, double *b2, double *a1, double *a2);
	void trebleCoefficient(int intensity, double *b0, double *b1, double *b2, double *a1, double *a2);
	virtual ~Coefficient();
};

#endif /* COEFFICIENT_H_ */
