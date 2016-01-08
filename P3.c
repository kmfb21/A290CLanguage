/*Filename: P3.c*
*Part of: A290 Program 3*
*Created by: Bo Fang*
*Created on: 6/10/2015*
*Last Modified by: Bo Fang*
*Last Modified on: 6/10/2015*
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

	/*Declaring function prototype as needed */
int division(int numerator, int denominator, int *dividend, int *remainder);

int main()
{
		//bitmodels.c from Meeting 9 Guide
		/*Declaring some variables of different types */
	unsigned char a;
	unsigned char b,c;
	unsigned char d,e;
	char f;
	int i;
		/*Various bitwise operations*/
	a=17;
	a=~a;
	printf("bitwise NOT of 17\n");
	printf("%d\n",a);
	b=17;
	c=22;
	b=b & c;
	printf("bitwise AND of 17 and 22\n");
	printf("%d\n",b);
	d=17;
	e=22;
	d=d | e;
	printf("bitwise OR of 17 and 22\n");
	printf("%d\n",d);
	f=17;
	f=f | (1 << 3); /* set bit #3 */
	printf("Sets bit #3 in 17, new value is 17+8=25\n");
	printf("%d\n",f);
	f=f & (~(1<<4)); /* clear bit #4 */
	printf("Clears bit #4 in 25, new value is 25-16=9\n");
	printf("%d\n",f);
	printf("Reads i-th bit in current value of f (which is the base10 number 9),\nplus a loop that prints every bit in 8-bit space\n");
	for (i=7; i>=0; i--)
		printf("%d ",(f&(1<<i)) >> i); /* read i'th bit */
	printf("\n");
	printf("Current value of a\n");
	for (i=7; i>=0; i--)
		printf("%d ",(a&(1<<i)) >> i); /* read i'th bit */
	printf("\n");
	printf("Current value of d\n");
	for (i=7; i>=0; i--)
		printf("%d ",(d&(1<<i)) >> i); /* read i'th bit */
	printf("\n");
	printf("Current value of e\n");
	for (i=7; i>=0; i--)
		printf("%d ",(e&(1<<i)) >> i); /* read i'th bit */
	printf("\n");

		//pointers.c from Meeting 9 Guide
		/*Declaring some variables of different types */
	int count, x;
	int *count_p;
	char letter;
	char *letter_p = &letter;
		/*Assigning specific values to the declared variables */
	count=10;
	count_p=&count;
	x=*count_p;
	letter = 'Q';
		/*Let's print the contents of count and x*/
	printf("Here's is the step-by-step output from the integer pointer example\n");
		/*Let's confirm the values of count and x*/
	printf("count = %i and x = %i\n", count, x);
		/*Let's change count using the pointer count_p*/
	*count_p = 42;
		/*Let's print the contents of count and x again*/
	printf("count = %i and x = %i\n", count, x);
		/*Let's change count to the value of x*/
	count = x;
		/*Let's print the contents of count and x again*/
	printf("count = %i and x = %i\n", count, x);
	printf("Here's is the step-by-step output from the character pointer example\n");
		/*Let's confirm the values of letter and letter_p*/
	printf("letter = %c and letter_p = %c\n", letter, *letter_p);
		/*Let's change letter but not letter_p*/
	letter = '/';
		/*Let's print the contents of letter and letter_p again*/
	printf("letter = %c and letter_p = %c\n", letter, *letter_p);
		/*Let's change letter_p but not letter*/
	*letter_p = '!';
		/*Let's print the contents of letter and letter_p again*/
	printf("letter = %c and letter_p = %c\n", letter, *letter_p);
	
		//morepointers.c from Meeting 10 Guide
		/*Declaring some variables of different types */
	int firsti, secondi;
	int *firsti_p, *secondi_p;
		/*Assigning specific values to the declared variables */
	firsti=5;
	firsti_p=&firsti;
	secondi = *firsti_p / 2 + 10;
	secondi_p = firsti_p;
		/*Let's print the outcome of our first set of int and int pointers*/
	printf("Here the output from the first integer pointer example\n");
		/*Let's confirm all the values*/
	printf("firsti = %i, secondi = %i, value of firsti_p = %i and value of secondi_p = %i\n", firsti, secondi, *firsti_p, *secondi_p);
	
		//pointerfunction.c from Meeting 10 Guide
		/*int variables for main that will be used in call of division*/
	int x2,y,d2,r;
	x2=9;
	y=2;
	printf("address of d: %u\n",&d2); /*address where dividend in function should point*/
	printf("address of r: %u\n",&r); /*address where remainder in function should point*/
	division(x2,y,&d2,&r);
	printf("%d/%d = %d with %d remainder\n",x2,y,d2,r);
	printf("x=%d\n",x2);
	
		//pointerarithmetic.c from Meeting 10 Guide
		/*Declaring some variables of different types */
	char ca[3],*cp;
	int ia[3],*ip;
		/*Assigning specific values to the declared variables */
	ca[0]='A';
	ca[1]='B';
	ca[2]='c';
	cp=&(ca[0]);
	ia[0]=1234;
	ia[1]=5678;
	ia[2]=9999;
	ip=&(ia[0]);
		/*Show output, then use pointers, then show output again. */
	printf("char pointer cp points to value = %c\n",*cp);
	printf("ca[2] = %c\n", ca[2]);
	printf("int pointer ip points to value = %i\n", *ip);
	printf("ia[2] = %i\n",ia[2]);
	*(cp+2) = 'Q';
	*(ip+2) = 33;
	printf("Results after we apply pointer arithmetic.\n");
	printf("ca[2] = %c\n",ca[2]);
	printf("ia[2] = %i\n",ia[2]);

		//pointerarray.c from Meeting 10 Guide
/*
** This program shows how a piece of memory can be accessed
** as an array, or by using a pointer. In the first case, it
** shows how array indices move up and down the memory.
** In the second case,it shows how pointer arithmetic does
** the exact same thing. (From Hoover 111-112)
*/
	double array[10];
	double *d_ptr;
	double value;
	int i2,offset;
	for (i2=0; i2<10; i2++)
	array[i2]=(double)i2+10.0; /* access memory using array index and fill cells with #s*/
	d_ptr=&(array[0]); /* access memory location of first array cell using pointer*/
	while (1)
		{
			printf("\nAddress(hex)\tAddress(base10)\tValue\n");
			for (i2=0; i2<10; i2++)
				printf("%p\t%u\t%lf\n",&(array[i2]),&(array[i2]),array[i2]);
			printf("Enter offset value (0 0 to quit): ");
			scanf("%d %lf",&offset,&value);
			if (offset == 0 && value == 0.0)
				break; /* break out of loop */
			if (offset < 0 || offset > 9)
				{
					printf("Offset out of bounds\n");
					continue; /* go back to start of loop */
				}
	/* Three ways to do the same thing */
	/*NOTE FROM JEFF: First one listed will be the one used at compile time To test each one, change order, or comment out all but one*/
			array[offset]=value; /* using array syntax */
	/* *(d_ptr+offset)=value; using pointer syntax */
	/* *(array+offset)=value; using mixed syntax */
		}
	return (0);
}
	/*This is the division function, with 2 int variables and 2 int pointer variables*/
int division(int numerator, int denominator, int *dividend, int *remainder)
{
	printf("address stored in dividend: %u\n",dividend);
	printf("address stored in remainder: %u\n",remainder);
	if (denominator < 1)
		return(0);
	*dividend=numerator/denominator;
	*remainder=numerator%denominator;
	numerator=7;
}