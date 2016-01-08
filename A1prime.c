/*Filename: A1prime.c *
 *Part of: A290 Assignment *
 *Created by: Bo Fang *
 *Created on: 5/20/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 5/20/2015 *
 */
#include <stdio.h>
int main()
{
  printf("Enter a number to check if it is a prime number:\n");
  unsigned long int i,n;//for larger number in case
  scanf("%d",&n);
  int check=1;//when check==1, it is prime now
  for(i=2;i<=n/2;i++)//check numbers from 2 to half of n instead of 2 to n since n is large
    if (n%i==0) check=0;//whenever finding any factors, mark check as 0
  if (n==2) check=1;//consider n==2
  if (check==1)
    printf("The number %d is a prime number.\n",n);
  else
    printf("The number %d is NOT a prime number.\n",n);
  return 0;
}
