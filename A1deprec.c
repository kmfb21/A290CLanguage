/*Filename: A1deprec.c *
 *Part of: A290 Assignment1 *
 *Created by: Bo Fang *
 *Created on: 5/20/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 5/16/2015 *
 */
#include <stdio.h>
int main()
{
  printf("Enter the purchase price, years of service, annual depreciation:\n");
  float a,b,c,ans;//a is the purchase price, b is years of service and c is annual depreciation. they are all float(in case of float years)
  scanf("%f %f %f",&a,&b,&c);//so that we can imput by a,b,c
  ans=a-b*c;//ans is the answer since c=(a-ans)/b
  printf("The salvage value of the item is %.6f\n",ans);//print using %.6f to get six decimal places
  return(0);
}
