/* This is a sandbox for the C For Everyone course.
 * I will really quickly go through the course just to brush up a bit :)
 */
// INCLUDES
#include "conversion.h"


// FUNCTION IMPLEMENTATION
float miles_2_km(float miles, float yards)
{
    float kilometers = 0;

    kilometers = 1.609 *(miles + yards / 1760.0);
    return(kilometers);
}

int fahrenheit_2_celcius(int degrees)
{
    int celcius = 0;

    celcius = (degrees - 32)/1.8; // implicite conversion!
    return(celcius);
}
