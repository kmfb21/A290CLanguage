/*Filename: P4.c *
 *Part of: A290 Program4 *
 *Created by: Bo Fang *
 *Created on: 6/15/2015 *
 *Last Modified by: Bo Fang *
 *Last Modified on: 6/15/2015 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

void SecondStruct();//function prototype
void Linked1();//function prototype

int demo_function(); /*Declare function prototype */
void DisplayStats(); /*Declare function prototype */

/*Declaring the prototypes for the functions we will use */
void append_node(struct NODE *llist, int num);
void delete_node(struct NODE *llist, int num);
int search_value(struct NODE *llist, int num);
void display_list(struct NODE *llist);

/*Declare our structure, a custom construct */
struct person { /* "person" is name for structure type */
  char first[32]; /* first field of structure is array of char */
  char last[32]; /* second field is array of char */
  int year; /* third field is int */
  double ppg; /* fourth field is double */
}; /* ending “;” means end of structure type definition */
struct NODE {
  int number;
  struct NODE *next;
};

int main(void)
{
  SecondStruct();
  Linked1();
  return(0);
}

void SecondStruct()
{
  struct person teacher;
  int i;
  /*Initializing the values in the struct with the
    "." syntax to get to each element of the struct*/
  teacher.year=2005;
  teacher.ppg=10.4;
  strcpy(teacher.first,"Adam");
  strcpy(teacher.last,"Hoover");
  demo_function();
  return;
}
int demo_function()
{
  struct person class[54]; /* array of "person" structs */
  class[0].year=2004; /* notice where array index/subscript goes */
  class[0].ppg=5.2;
  strcpy(class[0].first,"Jane");
  strcpy(class[0].last,"Doe");
  class[1].year=2005;
  class[1].ppg=4.9;
  strcpy(class[1].first,"Brian");
  strcpy(class[1].last,"Smith");
  class[2].year=2006;
  class[2].ppg=4.6;
  strcpy(class[2].first,"Bria");
  strcpy(class[2].last,"Smit");
  class[3].year=2007;
  class[3].ppg=4.3;
  strcpy(class[3].first,"Bri");
  strcpy(class[3].last,"Smi");
  class[4].year=2008;
  class[4].ppg=4.0;
  strcpy(class[4].first,"Br");
  strcpy(class[4].last,"Sm");
  class[5].year=2009;
  class[5].ppg=3.7;
  strcpy(class[5].first,"B");
  strcpy(class[5].last,"S");
  class[6].year=2010;
  class[6].ppg=3.4;
  strcpy(class[6].first,"First");
  strcpy(class[6].last,"Last");
  /* do we need a loop or some other construct here to call DisplayStats?
     DisplayStats(class?); This is not valid code, just a hint*/
  int i;
  for(i=0;i<7;++i) DisplayStats(class[i]);
}
void DisplayStats(struct person Input)
{
  printf("%s, %s: %lf PPG in %d\n",Input.last,Input.first,Input.ppg,Input.year);
}

void Linked1()
{
  int num = 0;
  int input = 1;
  int retval = 0;
  struct NODE *llist;

  /*Initializing the list using malloc and make sure we have one node
    and a pointer to the next node */
  llist = (struct NODE *)malloc(sizeof(struct NODE));
  llist->number = 0;
  llist->next = NULL;
  /*Setup our menu system so we can make some basic changes to the nodes
    in our linked list*/
  while(input != 0) {
    printf("\n-- Menu Selection --\n");
    printf("0) Quit\n");
    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Search\n");
    printf("4) Display\n");
    scanf("%d", &input);
    switch(input) {
      /*Exit the menu gracefully */
    case 0:
      printf("Goodbye ...\n");
      input = 0;
      break;
      /*Insert a value by creating a node at the end of the list */
    case 1:
      printf("Your choice: 'Insertion'\n");
      printf("Enter the value which should be inserted: ");
      scanf("%d", &num);
      append_node(llist, num);
      break;
      /*Remove a value by removing the node with that value */
    case 2:
      printf("Your choice: 'Deletion'\n");
      printf("Enter the value which should be deleted: ");
      scanf("%d", &num);
      if((retval = search_value(llist, num)) == -1)
	printf("Value '%d' not found\n", num);
      else
	delete_node(llist, num);
      break;
      /*Search for a value, if not found, notify, if found
	state what node "position" it has in the list */
    case 3:
      printf("Your choice: 'Search'\n");
      printf("Enter the value you want to find: ");
      scanf("%d", &num);
      if((retval = search_value(llist, num)) == -1)
	printf("Value '%d' not found\n", num);
      else
	printf("Value '%d' located at position '%d'\n", num, retval);
      break;
      /*Display the current contents of the list */
    case 4:
      printf("You choice: 'Display'\n");
      display_list(llist);
      break;
      /*Catch all unmanaged input and return to menu */
    default:
      printf("That is not a valid menu option\n");
      break;
    } /*end of switch-case */
  } /*end of while loop */
  free(llist); /*BE SURE YOU FREE UP YOUR MALLOC when you are done!!! */
  return;
}
/* END OF MAIN */
/*All the functions that we proto-typed and then called from within our menu */
/*Add/append a node. Have to use malloc and have to "move" pointers */
void append_node(struct NODE *llist, int num) {
  while(llist->next != NULL)
    llist = llist->next;
  llist->next = (struct NODE *)malloc(sizeof(struct NODE));
  llist->next->number = num;
  llist->next->next = NULL;
}
/*Remove a node. Have to use a temp to store pointer if we find the node,
and have to "move" pointers. Note we have to deal with a node in the "middle"
differently than a node at the "end" DON'T FORGET TO "FREE" */
void delete_node(struct NODE *llist, int num) {
  struct NODE *temp;
  temp = (struct NODE *)malloc(sizeof(struct NODE));
  if(llist->number == num) {
    /* remove the node */
    temp = llist->next;
    free(llist); /*FREE UP THAT MEMORY!! */
    llist = temp;
  } else {
    while(llist->next->number != num)
      llist = llist->next;
    temp = llist->next->next;
    free(llist->next); /*FREE UP THAT MEMORY!! */
    llist->next = temp;
  }
}
/*Search for a node with a value using basic “while” loop and increments.*/
int search_value(struct NODE *llist, int num) {
  int retval = -1;
  int i = 1;
  while(llist->next != NULL) {
    if(llist->next->number == num)
      return i;
    else
      i++;
    llist = llist->next;
  }
  return retval;
}
/*Display the current contents of the list */
void display_list(struct NODE *llist) {
  while(llist->next != NULL) {
    printf("%d ", llist->number);
    llist = llist->next;
  }
  printf("%d", llist->number);
}
