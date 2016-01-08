/*Filename: A3.c *
 *Part of: A290 Assignment3 *
 *Created by: Bo Fang *
 *Created on: 6/13/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 6/13/2015 *
 */
#include <stdio.h>
void showbits(int number); /*Function prototype */
void leftshift(); /*Function prototype */
void rightshift(); /*Function prototype */
void bitand(); /*Function prototype */
void bitor(); /*Function prototype */
void bitnegation(); /*Function prototype */
void bitxor(); /*Function prototype */
int main()
{
	int input=0;//No input
	while(input!=7)//whenever user is not choosing 7:Quit
	{
		printf("                Main Menu\n");
		printf("                ---------\n");
		printf("1. Perform Left Bit Shift Operation (one value)\n");
		printf("2. Perform Right Bit Shift Operation (one value)\n");
		printf("3. Perform Binary AND Operation (two values)\n");
		printf("4. Perform Binary OR Operation (two values)\n");
		printf("5. Perform Binary One's Complement (~) Operation (one value)\n");
		printf("6. Perform Binary XOR Operation (two values)\n");
		printf("7. Quit\n");
		scanf("%d",&input);//get user's choice
		switch(input)//switch
		{
			case 1:
				leftshift();//left bit shift
				break;
			case 2:
				rightshift();//right bit shift
				break;
			case 3:
				bitand();//AND
				break;
			case 4:
				bitor();//OR
				break;
			case 5:
				bitnegation();//NOT
				break;
			case 6:
				bitxor();//XOR
				break;
			case 7:
				break;//will quit at the beginning of while loop
			default:
				printf("Please choose one option from 1 to 7!!!\n\n");//in case user make a mistake
		}
	}
	return(0);
}
void showbits(int number)
{
	int i;
	for(i=31;i>=0;i--)
		printf("%d",number>>i&1);//right bit shift i then AND 000001 to get the i th position of number in binary, then print it out
	printf(" (base 10 %d)",number);//print the original number
}
void leftshift()
{
	int number,shift;
	printf("\nEnter a base 10 Integer: ");
	scanf("%d",&number);
	printf("\nEnter number of places to shift bit: ");
	scanf("%d",&shift);
	printf("\n        Entered Integer: ");
	showbits(number);
	printf("\n        Left Shifted   : ");
	showbits(number<<shift);//left shift the number and print it out
	printf("\n\n");
}	
void rightshift()
{
	int number,shift;
	printf("\nEnter a base 10 Integer: ");
	scanf("%d",&number);
	printf("\nEnter number of places to shift bit: ");
	scanf("%d",&shift);
	printf("\n        Entered Integer: ");
	showbits(number);
	printf("\n        Right Shifted  : ");
	showbits(number>>shift);//right shift the number and print it out
	printf("\n\n");
}
void bitand()
{
	int n1,n2;
	printf("\nEnter two base 10 Integers, separated by a space: ");
	scanf("%d %d",&n1,&n2);
	printf("\n        Entered Integer 1: ");
	showbits(n1);
	printf("\n        Entered Integer 2: ");
	showbits(n2);
	printf("\n        AND'ed           : ");//AND
	showbits(n1&n2);
	printf("\n\n");
}
void bitor()
{
	int n1,n2;
	printf("\nEnter two base 10 Integers, separated by a space: ");
	scanf("%d %d",&n1,&n2);
	printf("\n        Entered Integer 1: ");
	showbits(n1);
	printf("\n        Entered Integer 2: ");
	showbits(n2);
	printf("\n        OR'ed            : ");//OR
	showbits(n1|n2);
	printf("\n\n");
}
void bitnegation()
{
	int number;
	printf("\nEnter a base 10 Integer: ");
	scanf("%d",&number);
	printf("\n        Entered Integer: ");
	showbits(number);
	printf("\n        ~'ed           : ");//NOT
	showbits(~number);
	printf("\n\n");
}
void bitxor()
{
	int n1,n2;
	printf("\nEnter two base 10 Integers, separated by a space: ");
	scanf("%d %d",&n1,&n2);
	printf("\n        Entered Integer 1: ");
	showbits(n1);
	printf("\n        Entered Integer 2: ");
	showbits(n2);
	printf("\n        XOR'ed           : ");//XOR
	showbits(n1^n2);
	printf("\n\n");
}