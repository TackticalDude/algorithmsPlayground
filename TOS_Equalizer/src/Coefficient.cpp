/**
 * @class Coefficient
 * @author Zakaria el Barnoussi (TackticalDude)
 * @version 0.1
 */

#include "Coefficient.h"

/**
 * @name Constructor
 */
Coefficient::Coefficient() {
	// TODO Auto-generated constructor stub

}

/**
 * @name bassCoffiecient
 * @param intensity - intensity of the bass
 * @param b0 - pointer to double to place b0 in
 * @param b1 - pointer to double to place b1 in
 * @param b2 - pointer to double to place b2 in
 * @param a1 - pointer to double to place a1 in
 * @param a2 - pointer to double to place a2 in
 */
void Coefficient::bassCoeffiecient(int intensity, double *b0, double *b1, double *b2, double *a1, double *a2) {
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

/**
 * @name trebleCoefficient
 * @param intensity - intensity of the treble
 * @param b0 - pointer to double to place b0 in
 * @param b1 - pointer to double to place b1 in
 * @param b2 - pointer to double to place b2 in
 * @param a1 - pointer to double to place a1 in
 * @param a2 - pointer to double to place a2 in
 */
void Coefficient::trebleCoefficient(int intensity, double *b0, double *b1,double *b2, double *a1, double *a2) {
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

/**
 * @name Deconstructor
 */
Coefficient::~Coefficient() {
	// TODO Auto-generated destructor stub
}

