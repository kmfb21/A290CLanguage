/*Filename: A4.c *
 *Part of: A290 Assignment4 *
 *Created by: Bo Fang *
 *Created on: 6/18/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 6/18/2015 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

/*Declare structure */
struct person/* structure person to save each person in teams */
{
	char name[32];
	float average;
};
struct team/* structure team to save each team and how many people in it */
{
	char tname[32];
	struct person people[11];
	int amount;
};
struct NODE/* structure: LinkedList */
{
	int number;
	struct NODE *next;
};

/*Declare function prototype in Main Menu*/
void Cricket();
void LinkedList();
/*Declaring the prototypes for the functions we will use in LinkedList*/
void insertEnd(struct NODE *list,int n);
struct NODE *insertBegin(struct NODE *list,int n);
void deleteEnd(struct NODE *list);
struct NODE *deleteBegin(struct NODE *list);
void insertMid(struct NODE *list,int n,int nn);
void deleteMid(struct NODE *list,int n);
void modify(struct NODE *list,int n,int nn);
void printlist(struct NODE *list);

int main()
{
	int input = 3;
	while(input != 0)//main menu
	{
		printf("\n-- Menu Selection --\n");
		printf("0) Quit\n");
		printf("1) Cricket\n");
		printf("2) LinkedList\n");
		scanf("%d", &input);//input the choice
		switch(input)
		{
			case 0:
				printf("Goodbye ...\n");/*Exit the menu gracefully */
				break;
			case 1:
				printf("Your choice: 'Cricket'\n");//first function
				Cricket();
				break;
			case 2:
				printf("Your choice: 'LinkedList'\n");//second function
				LinkedList();
				break;
			default:
				printf("That is not a valid menu option\n");//in case of wrong input
				break;
		}/*end of switch-case */
	}/*end of while loop */
	return(0);
}

void Cricket()
{
	printf("Enter the number of teams you wish to record: ");
	int tnumber;
	scanf("%d",&tnumber);
	struct team teams[tnumber];//attay of teams
	int i,j;
	char s[32],ss[32];
	for(i=0;i<tnumber;i++)
	{
		printf("Enter the name(s) of the teams: ");//input team names and set amount of people 0
		scanf("%s",&s);
		strcpy(teams[i].tname,s);
		teams[i].amount=0;
	}
	printf("\nEnter the TOTAL number of players for all teams: ");
	int pnumber;
	scanf("%d",&pnumber);
	float averages;
	for(i=0;i<pnumber;i++)
	{
		printf("Enter the %d Player name, Team name, and batting average: ",i+1);//input people into teams
		scanf("%s %s %f",&s,&ss,&averages);
		j=0;
		while(strcmp(teams[j].tname,ss)!=0) j++;//find right position j in team[] for each person
		strcpy(teams[j].people[teams[j].amount].name,s);
		teams[j].people[teams[j].amount].average=averages;
		teams[j].amount++;
	}
	printf("\nListing of players and batting average according to team names:\n");
	for(i=0;i<tnumber;i++)
	{
		printf("\n");
		printf("%s-\n",teams[i].tname);
		for(j=0;j<teams[i].amount;j++)
			printf("        %-10s%f\n",teams[i].people[j].name,teams[i].people[j].average);//output result of each team and each people
	}
}

void LinkedList()
{
	int n,nn,input=0;
	struct NODE *list;
	list=NULL;//null list in the beginning
	while(input!=8)
	{
		printf("\nPlease enter your choice\n");//menu of it
		printf("1. INSERT a node at the END of linklist\n");
		printf("2. INSERT a node at the BEGINNING of linklist\n");
		printf("3. DELETE a node at the END of linklist\n");
		printf("4. DELETE a node from the BEGINNING of linklist\n");
		printf("5. INSERT a node in the MIDDLE of linklist\n");
		printf("6. DELETE a node from the MIDDLE of linklist\n");
		printf("7. MODIFY any node in linklist\n");
		printf("8. EXIT\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("Enter your node in the list\n");//insert at the end
				scanf("%d",&n);
				if(list)//if there is already numbers in it
					insertEnd(list,n);
				else
				{
					list=(struct NODE *)malloc(sizeof(struct NODE));//if list is null,just allocate a new memory
					list->number=n;
					list->next=NULL;
				}
				printlist(list);
				break;
			case 2:
				printf("Enter the value for the node you want to insert at the beginning\n");//insert at beginning
				scanf("%d",&n);
				list=insertBegin(list,n);//make the address of returned value into list
				printlist(list);
				break;
			case 3:
				if(list->next)
					deleteEnd(list);//delete
				else
				{
					free(list);//if there is only one value in list,just free it
					list=NULL;
				}
				printlist(list);
				break;
			case 4:
				if(list->next)
					list=deleteBegin(list);
				else
				{
					free(list);//if there is only one value in list,just free it
					list=NULL;
				}
				printlist(list);
				break;
			case 5:
				printf("Enter the value of the node after which you want to insert a new node\n");
				scanf("%d",&n);
				printf("Enter the value of new node\n");//insert mid of link list
				scanf("%d",&nn);
				insertMid(list,n,nn);
				printlist(list);
				break;
			case 6:
				printf("Enter the value of the node that precedes the node you want to delete\n");
				scanf("%d",&n);
				deleteMid(list,n);//delete mid of link list
				printlist(list);
				break;
			case 7:
				printf("Enter the value of the node you want to modify\n");
				scanf("%d",&n);
				printf("Enter the new value for this node:\n");//change the value of one node in list
				scanf("%d",&nn);
				modify(list,n,nn);
				printlist(list);
				break;
			case 8:
				break;
			default:
				printf("That is not a valid menu option\n");//in case wrong input
				break;
		}/*end of switch-case */
	}/*end of while loop */
}
void insertEnd(struct NODE *list,int n)
{
	while(list->next!=NULL) list=list->next;//find the last node
	list->next=(struct NODE *)malloc(sizeof(struct NODE));//creat a new node and put it after the last node
	list->next->number=n;
	list->next->next=NULL;
}
struct NODE *insertBegin(struct NODE *list,int n)
{
	struct NODE *temp;
	temp=(struct NODE *)malloc(sizeof(struct NODE));//creat a new node
	temp->number=n;
	temp->next=list;//put orginal node after the new node
	return(temp);//return address of new node
}
void deleteEnd(struct NODE *list)
{
	while(list->next->next!=NULL) list=list->next;//find the last two node
	free(list->next);//free the last one
	list->next=NULL;
}
struct NODE *deleteBegin(struct NODE *list)
{
	struct NODE *temp;
	temp=list->next;
	free(list);
	return(temp);//just return the second node and free the first one (by save the second one in temp)
}
void insertMid(struct NODE *list,int n,int nn)
{
	while(list->number!=n) list=list->next;//find the number and use insertBegin
	list->next=insertBegin(list->next,nn);
}
void deleteMid(struct NODE *list,int n)
{
	while(list->number!=n) list=list->next;//find the number and use deleteBegin
	list->next=deleteBegin(list->next);
}
void modify(struct NODE *list,int n,int nn)
{
	while(list->number!=n) list=list->next;//find the number and change its value
	list->number=nn;
}
void printlist(struct NODE *list)
{
	printf("The link list currently has these nodes:\n");
	while(list!= NULL)
	{
		printf("%d->",list->number);//print the whole list in formal
		list = list->next;
	}
	printf("\n");
}