/* This is a sandbox for the C For Everyone course.
 * I will really quickly go through the course just to brush up a bit :)
 */
// INCLUDES
#include <stdio.h>


/* FUNCTION DECLARATIONS */
/**
 * sin(x) - returns the sine of x using Bhaskara I approximation
 * using this approximation is fast and does not require using
 * the math library
 * @param 	x	 - the angle in radians
 * @return	the sine of input param x given by Bhaskara I approximation
 */

double bhashara_sine(double x);

/* FUNCTION DECLARATIONS */
/**
 * sin(x) - returns the sine of x using Taylor expansion
 * using this approximation is fast and does not require using
 * the math library
 * @param 	x	 - the angle in radians
 * @return	the sine of input param x given by Bhaskara I approximation
 */

double taylor_sine(double x);
