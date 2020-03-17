# include <stdio.h>
# include <string.h>
# include "identifiers.h"

/*
FAHAD AHMED KHAN
214468888
22 SEPT 2017
THIS CODE HAS FOUR FUNCTIONS:
(a) The first converts fahrenheit to celsius.
    
(b) The second converts celsius to fahrenheit.
    
(c) This reverses the elements in an array.
  
(d) This counts the number of * in a string given.
    
/* you may wish to remove the following lines */
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wdangling-else"
#pragma GCC diagnostic ignored "-Wempty-body"

/* Q1.convert a temperature in F to it in C */
float fahrenheit2celsius(const float f) 
{
  return 5.0/9.0 * (f-32);
}  

/*
 The only problem here was that the integers 5 and 9 weren't in floating 
 point format.
*/


/* Q2. convert a temperature in C to F */
float celsius2fahrenheit(const float c) 
{
  return 32 + (c * 9 / 5);
}
/*
Here the formula was wrong. 32 had to be added to the rest of the expression.  
*/

/* Q3. reverse the elements in an array of int's in place */
void reverse_elements(int vals[], int count)
{
  int i;
  for(i=0;i<count/2;i++) {
    int t = vals[i];
    vals[i] = vals[count-1-i];
    vals[count-1-i] = t;
  } 
}

/*
 The fix here was to divide the variable count by 2 in the for loop argument 
*/

/* Q4. Count the number of '*' in the string given */
int count_stars(const char *s)

{
  int count = 0;
  int i;
  int length = (int)strlen(s);
  for(i=0;i<length ;i++){
    if(s[i] == '*'){
      count++;
    }
  }
  return count;
 }

/*
 the fix here was to put proper brackets and iterate through the string using
 a proper variable i. Also strlen was used to calculate length of the string
*/   
