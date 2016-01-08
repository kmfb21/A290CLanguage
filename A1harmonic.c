/*Filename: A1harmonic.c *
 *Part of: A290 Assignment *
 *Created by: Bo Fang *
 *Created on: 5/20/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 5/20/2015 *
 */
#include <stdio.h>
int main()
{
  int i,n;
  double sum=0;//use sum save sum of series
  printf("Enter a value to calculate the value of this harmonic series:\n");
  do
    {
      scanf("%d",&n);
      if (n<=0) printf("Please enter a POSITIVE Number:");
    }
  while(n<=0);//do it until we get a positive number
  for(i=1;i<=n;i++) sum = 1.0/i + sum;//a loop get sum of series
  printf("The value for the series is: %.6f.\n",sum);//6 decimal places
  return 0;
}
