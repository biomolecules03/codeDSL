#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

typedef struct node
{
int coef;
int power; 
struct node *link;
}*NODE;
NODE First = NULL;

void Create()
{
NODE Temp, New, Prev; //Don’t take as "new" because "new" is a kayword
int coef, power;
printf("Enter the coef and power terminated by coef 0 \n");
scanf("%d %d", &coef, &power);
while(coef != 0)
{
New = (NODE)malloc(sizeof(struct node));
New->coef = coef;
New->power = power;
New->link = NULL; //As it is the First node its link must be NULL
if(First == NULL) //Like First == NULL in normal list
First = New ;
/* If First is NULL, then there is no list, so New is the First Node inserted */
else //If the list has some nodes
{
if(power > First->power) 
{
New->link = First; //If it is the highest power
First = New;
}
else
{
Temp = First;
while( (Temp!= NULL) && (power < Temp->power) ) //if power to x is less
{
Prev = Temp;
Temp = Temp->link; //To traverse
}
if(Temp == NULL)    //Its true when last node reached, means least power
{
Prev->link = New;
New->link = Temp; //New->link = NULL;
}
else //For Intermediate Power
{
Prev->link = New;
New->link = Temp;
}
}
}
scanf("%d %d", &coef, &power);
}
}
//Evaluation of the Polynomial
int Evaluate()
{
NODE Temp;
int result = 0, x;
printf("Enter the value of X in the Polynomial  \n");
scanf("%d", &x);
Temp = First;
while(Temp!= NULL) //Traversing
{
result = result + Temp->coef * pow(x, Temp->power);
Temp = Temp->link;
}
return result;
}
//Display Function
void Display()
{
NODE Temp;
if(First == NULL)
{
printf("Empty Polynomial \n");
return;
}
Temp = First;
while(Temp!= NULL) //Traversing
{
printf("|%d|%d| –>", Temp->coef, Temp->power);
Temp = Temp->link;
}
printf("NULL"); 
}

int main()
{
int choice, result;
for(;;)
{
printf("\n1.Create Polynomial\n2.Evaluate\n3.Display\n4.Exit\n");
printf("Enter your choice : \n");
scanf("%d", &choice);
switch(choice)
{
case 1:
Create();
printf("Polynomial After Creation \n");
Display();
break;
case 2:
result = Evaluate();
printf("Result is %d", result);
break;
case 3:
printf("Polynomial is \n");
Display();
break;
case 4:
exit(0);
default:
printf("Invalid option\n\n");
break;
}
}
}