/*Filename: A2.c *
 *Part of: A290 Assignment2 *
 *Created by: Bo Fang *
 *Created on: 5/31/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 5/31/2015 *
 */
#include <stdio.h>
int find(int n,int size,int array[])//use find to judge whether a value is in an array
{
  int i;
  for(i=0;i<size;++i)
    if(n==array[i])
      return(1);
  return(-1);
}
void inORnot(int array1[],int *size1,int array2[],int *size2,int answer[],int *anssize,int way)//when in way 1, find whether a1[i] is in a2[]/. when in way -1, find whether a1[i] is not in a2[]
{
  int i;
  for(i=0;i<*size1;++i)
    if(find(array1[i],*size2,array2)==way&&find(array1[i],*anssize,answer)==-1)//make sure no same element
      {
	    answer[*anssize]=array1[i];//using answer to save our answer array, and must make sure that there is no same element in it
	    ++*anssize;
      }
  return;
}
void scanarray(int array[],int size)//function scan array
{
  int i;
  for(i=0;i<size;++i)
	  scanf("%d",&array[i]);
  return;
}
void printarray(int array[],int size)//function print array
{
  int i;
  for(i=0;i<size;++i)
	  printf("%d",array[i]);
  printf("\n");
  return;
}
void Array()// main of Array
{
  printf("Enter the size of the arrays:\n");
  int size;
  scanf("%d",&size);

  printf("Enter elements of the first array:\n");
  int i,a[size],b[size];
  scanarray(a,size);
  printf("Enter elements of the second array:\n");//scanf two arrays
  scanarray(b,size);

  printf("The intersection of two arrays is: ");
  int answer[size*2],anssize;
  inORnot(a,&size,b,&size,answer,&anssize,1);//get intersection
  printarray(answer,anssize);

  printf("The union of two arrays is: ");
  inORnot(a,&size,answer,&anssize,answer,&anssize,-1);//put all element in intersection that is not in a into answer
  inORnot(b,&size,answer,&anssize,answer,&anssize,-1);//put all element in intersection that is not in b into answer
  printarray(answer,anssize);//get union

  return;
}

void Matrices(int M1[][5],int M2[][4])//main of Matrices
{
	int i,j;
	for(i=0;i<4;++i)
		for(j=0;j<5;++j)
			M2[j][i]=M1[i][j];
	return;
}
void printMA(int r,int c,int M[r][c])//print Matrices in formal
{
	int i,j;
	for(i=0;i<r;++i)
		{
			printf("%d",M[i][0]);
			for(j=1;j<c;++j)
				printf(" %d",M[i][j]);
			printf("\n");//change another line
		}
	return;
}

void Calculator()// main of Calculator
{
	printf("Begin Calculations\n");
	printf("Initialize your Accumulator with data of the form");
	printf(" \"number\" \"S\" which sets the Accumulator to the value of your number\n");
	double sum,iput;
	char op='S';
	while(op!='E')
	{
		scanf("%lf %c",&iput,&op);
		switch(op)// switch function
		{
			case '+':
				sum=sum+iput;
				break;
			case '-':
				sum=sum-iput;
				break;
			case '*':
				sum=sum*iput;
				break;
			case '/':
				if(iput==0)// make sure divider is not 0
					printf("Can not divide by 0.\n");
				else
					sum=sum/iput;
				break;
			case 'S':
				sum=iput;
				break;
			case 'E':
				break;
			default:
				printf("Unknown operator.\n");
				break;
		}
		printf("Value in the Accumulator = %lf\n",sum);// output
	}
	printf("End of Calculations.\n",sum);// end
	return;
}

int main()// main function of three
{
  Array();
/*
  int Ma[4][5]={{1,2,3,4,5},{6,7,8,9,10},{10,9,8,7,6},{5,4,3,2,1}};
  int Mb[5][4];
  Matrices(Ma,Mb);
  printf("The original matrix was:\n");
  printMA(4,5,Ma);
  printf("The transposed matrix is:\n");
  printMA(5,4,Mb);
*/
  Calculator();
  
  return(0);
}