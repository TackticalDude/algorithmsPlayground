/*
 * Coefficient.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: TackticalDude
 */

#include "Coefficient.h"

Coefficient::Coefficient() {
	// TODO Auto-generated constructor stub

}

void Coefficient::bassCoffiecient(int intensity, double *b0, double *b1, double *b2, double *a1, double *a2) {
	double frequency = 330;
	double qFactor = 0.5;
	double gain = intensity;
	double sampleRate = 44100;
	double pi = 4.0 * atan(1);

	double a = pow(10.0, gain / 40);
	double w0 = 2 * pi * frequency / sampleRate;
	double alpha = sin(w0) / (2.0 * qFactor);
	double a0 = (a + 1) + (a - 1) * cos(w0) + 2.0 * sqrt(a) * alpha;

	*a1 = -(-2.0 * ((a - 1) + (a + 1) * cos(w0))) / a0;
	*a2 = -((a + 1) + (a - 1) * cos(w0) - 2.0 * sqrt(a) * alpha) / a0;
	*b0 = (a * ((a + 1) - (a - 1) * cos(w0) + 2.0 * sqrt(a) * alpha)) / a0;
	*b1 = (2 * a * ((a - 1) - (a + 1) * cos(w0))) / a0;
	*b2 = (a * ((a + 1) - (a - 1) * cos(w0) - 2.0 * sqrt(a) * alpha)) / a0;
}

void Coefficient::trebleCofficient(int intensity, double *b0, double *b1,double *b2, double *a1, double *a2) {
    double frequency = 3300;
    double qFactor = 0.5;
    double gain = intensity;
    double sampleRate = 44100;
    double pi=4.0*atan(1);

    double a=pow(10.0, gain/40);
    double w0=2*pi*frequency/sampleRate;
    double alpha=sin(w0)/(2.0*qFactor);

    double a0=(a+1)-(a-1)*cos(w0)+2.0*sqrt(a)*alpha;

    *a1=-(2.0*((a-1)-(a+1)*cos(w0)))/a0;
    *a2=-((a+1)-(a-1)*cos(w0)-2.0*sqrt(a)*alpha)/a0;
    *b0=(a*((a+1)+(a-1)*cos(w0)+2.0*sqrt(a)*alpha))/a0;
    *b1=(-2.0*a*((a-1)+(a+1)*cos(w0)))/a0;
    *b2=(a*((a+1)+(a-1)*cos(w0)-2.0*sqrt(a)*alpha))/a0;
}

Coefficient::~Coefficient() {
	// TODO Auto-generated destructor stub
}

