#include <stdio.h>
float fahrenheit2celsius(const float f);
int main()
{

 printf("%0.2f\n" , fahrenheit2celsius(100.0);
 printf("%0.2f\n" , celsius2fahrenheit(50.0));
    return 0;
    
}

    float fahrenheit2celsius(const float f) 
{
  return 5.0/9.0 * (f-32);
}  

/* Q2. convert a temperature in C to F */
    float celsius2fahrenheit(const float c) 
{
  return 32 + (c * 9 / 5);
}
