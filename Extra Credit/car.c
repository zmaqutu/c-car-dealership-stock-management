//the code below prompts the user to input the characteristics of a car and strores it as a structure
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "car.h"
#include "readline.h"

int check(struct car* car1, struct car* car2);
struct car *append_to_list(struct car *list){

        //add your code here and remove the return NULL; statement                                              //Add cars to the list
struct car* newCar = (struct car*)malloc(sizeof(struct car));
newCar->next = NULL;
        printf("Please enter the car make:\n ");
		fflush(stdout);
                read_line(newCar->make, LEN);
        printf("Please enter the model:\n ");
		fflush(stdout);
                read_line(newCar->model, LEN);
        printf("Please enter the car color:\n ");
		fflush(stdout);
                read_line(newCar->color, LEN);
        printf("Please enter the car year:\n ");
		fflush(stdout);
                scanf("%d", &newCar->year);
        printf("Please enter City MPG(Miles per Gallon):\n ");
		fflush(stdout);
                scanf("%d", &newCar->city_mpg);
        printf("Please enter Highway MPG(Miles per Gallon):\n ");
		fflush(stdout);
                scanf("%d", &newCar->highway_mpg);
        printf("Please enter quantity in stock:\n ");
		fflush(stdout);
                scanf("%d", &newCar->quantity);

if(list == NULL)
{
return newCar;
}
else
{
struct car* current = list;
struct car* previous = NULL;
struct car* ptr = list;
while(current != NULL)
{
int comparison = check(newCar, ptr);

	if(comparison == 0)
	{
	printf("The car aleady exists on the list");
	return list;
	}
	else if(comparison = EOF)
	{
	break;
	}
previous = current;
current = current->next;	
}

newCar->next = current;

if(previous == NULL)
{
list = newCar;
}
else
previous->next = newCar;

return list;
}

        return NULL;
}

void find_car(struct car * list)                                                                                                //funciton to search for an existing car $
{
        //add your code here

        int is_present = 0;
        char userModel[LEN+1], userMake[LEN+1];
        printf("Enter make to search for: ");
        read_line(userMake, LEN);
        printf("Enter model to search for: ");
        read_line(userModel, LEN);

struct car* ptr = list;
while(ptr != NULL)
{
if( (strcmp(ptr->make, userMake)==0) && (strcmp(ptr->model, userModel)==0) )
{
struct car *c = ptr;
printf("Car Model: %s, Make: %s, Color: %s, Year: %d, quantity: %d\n",c->model, c->make, c->color, c->year, c->quantity);
is_present = 1;
}
ptr = ptr->next;
}

if(!is_present) {
printf("No matching car found.\n");
}

}

void printList(struct car *list){                                                                                               //Function to print cars in list

        //add your code here
struct car* ptr = list;
while(ptr != NULL)
{
struct car *c = ptr;
printf("Car Model: %s, Make: %s, Color: %s, Year: %d, quantity: %d",c->model, c->make, c->color, c->year, c->quantity);
ptr = ptr->next;
}


} //close void
void clearList(struct car *list)                                                                                                //Function to clear list
{
        //add your code here
struct car* ptr = list;
while(ptr != NULL)
{
struct car *c = ptr;
ptr = ptr->next;
free(c);
}
printf("List has been cleared\n");

}

int check(struct car* car1, struct car* car2)						//this function compares two cars and checks which one goes first
{
int comparison = strcmp(car1->make, car2->make);

if(comparison < 0)
return EOF;

else if(comparison > 0)
return 1;

else 
{
comparison = strcmp(car1->model, car2->model);
if(comparison < 0)
return EOF;
else if(comparison > 0)
return 1;
else 
{
comparison = strcmp(car1->color, car2->color);
if(comparison < 0)
return EOF;
else if(comparison > 0)
return 1;
else
{
return car1->year - car2->year;
}

}

}
}
