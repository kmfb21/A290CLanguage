/*Filename: buffet.c *
*Part of: First A290/C291_Program *
*Created by: Bo Fang *
*Created on: 5/13/2015 *
*Last Modified by: Bo Fang *
*Last Modified on: 5/16/2015 *
*/
#include <stdio.h>
int main()
{
  /* The body of your source code will go here */

/*Part 1:*/
  /*Here are a set of printf statements that will display the actual
    memery size of different data type */
  printf("sizeof(char) == %d\n", sizeof(char));
  printf("sizeof(short) == %d\n", sizeof(short));
  printf("sizeof(int) == %d\n", sizeof(int));
  printf("sizeof(long) == %d\n", sizeof(long));
  printf("sizeof(float) == %d\n", sizeof(float));
  printf("sizeof(double) == %d\n", sizeof(double));
  printf("sizeof(long double) == %d\n", sizeof(long double));
  printf("sizeof(long long) == %d\n", sizeof(long long));

/*Part 2:*/
  int x,y;
  char a;
  float f,e;
  double d;
  x=4;
  y=7;
  a='H';
  f=-3.4;
  d=54.123456789;
  e=54.123456789;
  printf("%d %c %f %lf\n",x,a,e,d);
  printf("%d %c %.9f %.9lf\n",x,a,e,d);  

/*Part 3:*/
  int r1,r2,r3,r4,r5;
  r1=x+y;
  r2=x-y;
  r3=x/y;
  r4=x*y;
  printf("%d %d %d %d\n",r1,r2,r3,r4);
  r3++;
  r4--;
  r5=r4%r1;
  printf("%d %d %d\n",r3,r4,r5);

/*Part 4:*/
  int i,j,number;
  printf("Enter a number: ");
  scanf("%d",&number);
  i=1;
  while (i*i <= number)
    {
      j=1;
      while (j <= i)
	{
	  if (i*i + j*j == number)
	    printf("Found: %d + %d\n",i*i,j*j);
	  j++;
	}
	i=i+1;
    }

  return (0);
}