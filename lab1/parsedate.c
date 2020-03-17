# include <stdio.h>
#include <string.h>
# include "parsedate.h"



/**
     FAHAD AHMED KHAN
     214468888
     15 SEPT 2017
     THE CODE PARSES A DATE STRING INTO INTEGERS
 * parsedate.c - This is my solution to the first lab of eecs2031 ....

 *

 * 

 **/
 

int parse_year(const char *buf) 
{
  int year;
  int month;
  int day;
  char tmp[100];
  strcpy( tmp, buf );
  sscanf( tmp , "%d/%d/%d",&year,  &month, &day );
  printf("%d\n", year);
  return year;
}

int parse_month(const char *buf) 
{
    int month;
    int year;
    int day;
    char tmp[100];
    strcpy( tmp, buf );
    sscanf( tmp , "%d/%d/%d",&year,  &month, &day );
    printf("%d\n", month );
  return month;
}


int parse_day(const char *buf) 
{
   int month;
    int year;
    int day;
    char tmp[100];
    strcpy( tmp, buf );
    sscanf( tmp , "%d/%d/%d",&year , &month, &day );
  printf("%d\n", day );  
  return day;
}
