/*Filename: callingfunc.c *
 *Part of: A290C Program2 *
 *Created by: Bo Fang *
 *Created on: 5/26/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 5/26/2015 *
 */
#include <stdio.h>
/* creating a function to do the loops from Meeting 4 */
void loops()
{
  int i,x;
  x=0;
  /*for loop: runs for values of i = 0, 1, 2, and 3*/
  printf ("This is a \"for\" loop\n");
  for (i=0; i<4; i++)//for loop
    {
      x=x+i;
      printf("%d\n",x);
    }
  /*while loop runs until i is less than 7, but what is the starting
    value of i for this loop?*/
  printf ("This is a \"while\" loop\n");
  while (i<7)//while loop
    {
      x=x+i;
      i++;
      printf("%d\n",x);
    }
  /*do-while loop runs until i is less than 9, but runs at least
    once. What is the starting value of i for this loop?*/
  printf ("This is a \"do-while\" loop\n");
  do//do while loop
  {
    x=x+i;
    i++;
    printf("%d\n",x);
  }
 while (i<9);
}
/* Creating a function to show conditionals as in Meeting 4.*/
void conditionals()
{
  int i,x;
  x=0;
  for (i=0; i<5; i++)
    {
      if (i%2 == 0 || i == 1)//if condition
	x=x+i;
      else
	x=x-i;
      printf("%d\n",x);
    }
  /*An example of switch-case. Notice the cases are "grades" but they are looking for values
    that are ints.*/
  printf ("This is a \"switch-case\" conditional\n");
  int grade;
  printf ("Input Grade: [5=A, 4=B, 3=C, 2=D, 1=F] \n");
  scanf ("%d", &grade);
  switch (grade) {//switch condition
  case 1:
    printf ("Fail (F)\n");break;
  case 2:
    printf ("Not Good (D)\n");break;
  case 3:
    printf ("Good (C)\n"); break;
  case 4:
    printf ("Very Good (B)\n"); break;
  case 5:
    printf ("Excellent (A)\n"); break;
  default:
    printf ("You have not inputted a valid grade value.\n");
    break;
  }
}
/*Creating an function that will re-arrange the content of the cells in an array.*/
void firstswap()
{
  /*Declare 4 variables*/
  int i,j,k,swap;
  /* Array “c” of chars with 8 cells*/
  char c[8];
  /*Initialize first 5 cells with values. Other 3 are empty*/
  c[0]='f'; c[1]='r'; c[2]='o'; c[3]='g'; c[4]=0;

  printf("Initial values for first 5 cells: %c%c%c%c%c\n",c[0],c[1],c[2],c[3],c[4]);
  /*Initialize i and start a for loop*/
  for (i=0; i<4; i++)
    {
      /*Initialize k as equal to incremented i*/
      k=i;
      /*Initialize j as one greater than i and j*/
      for (j=i+1; j<4; j++)
	if (c[j]-c[k] < 10) /*What does this means or do?*/
	  k=j;
      swap=c[i];
      c[i]=c[k];
      c[k]=swap;
    }
  printf("Final values: i: %d, j: %d, k: %d, swap: %d\n",i,j,k,swap);
  printf("Final values for first 5 cells as we swap: %c%c%c%c%c\n",c[0],c[1],c[2],c[3],c[4]);
}
int main(void)
{
  printf("THIS IS MY CONDITIONALS FUNCTION.\n\n");
  conditionals();
  printf("THIS IS MY LOOPS FUNCTION.\n\n");
  loops();
  printf("THIS IS MY FIRST ARRAY FUNCTION.\n\n");
  firstswap();
  return(0);
}
