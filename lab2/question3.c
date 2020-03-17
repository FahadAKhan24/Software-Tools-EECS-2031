#include <stdio.h>
void reverse_elements(int vals[], int count);
int main()
{
    int i;
    int balance[3] = {1, 3, 5 };
    reverse_elements(balance,3);
    for (i=0 ; i<3 ;i++) {
    printf("%d\n",balance[i]);
}
    return 0;
    
}

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
