#include <stdio.h>
#include <string.h>
int count_stars(const char *s);

int main()
{
  
    printf("%d\n",count_stars("Hello**world"));
    return 0;
}

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

   