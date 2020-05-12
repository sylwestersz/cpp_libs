/* This is a sandbox for the C For Everyone course.
 * I will really quickly go through the course just to brush up a bit :)
 */
// INCLUDES
#include "conversion.h"

/* MACARO DEFINITIONS */
#define PI 			(3.14159)
#define DEN_CONST	(5*PI*PI)
#define TAYLOR_LEN	(4)         // number of coefficients in taylor expansion

// FUNCTION IMPLEMENTATION
double bhashara_sine(double x)
{
    double num 		= 16*x*(PI - x);
    double den 		= DEN_CONST - 4*x*(PI-x);
    double ret_val 	= num/den;

    return(ret_val);
}



double taylor_sine(double x)
{
    // first order approx is done in initialization
    double factorial       = 1;  // Factorial start
    int    trace_factorial = 1;  // Trace the integers for factorial
    double powers          = x;  // Numerator powers
    double ret_val         = powers/factorial; // first in Taylor series
    int    sign            = (-1);

    for (int i = 1; i < TAYLOR_LEN; i++)
    {
        // advance factorial by 2 integers
        factorial *= (++trace_factorial);
        factorial *= (++trace_factorial);

        // advance numerator power by 2
        powers *= (x*x);

        // sum the series
        ret_val += (sign)*(powers)/factorial;

        sign *= sign;
    }

    return(ret_val);
}
