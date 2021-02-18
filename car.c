//the code below prompts the user to input the characteristics of a car and strores it as a structure
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "car.h"
#include "readline.h"

struct car* delete_from_list(struct car *list){								//this function will delete a car from the list
													//prompt user to input car info, then search and delete
struct car* delcar = (struct car*)malloc(sizeof(struct car));
    delcar->next = NULL;
    printf("Please enter the car make : ");
    read_line(delcar->make, LEN);
    printf("Please enter model: ");
    read_line(delcar->model, LEN);
    printf("Please enter the car color: ");
    read_line(delcar->color, LEN);
    printf("Please enter car year: ");
    scanf("%d", &delcar->year);

struct car *x;
struct car *y;

x = list;
    if (x == NULL){
       printf("There are no cars on the list\n");
    }
    else {
       while (x->next != NULL){
          y = x->next;
          if (strcmp(y->make,delcar->make) == 0 && strcmp(y->model,delcar->model) == 0 && strcmp(y->color,delcar->color) == 0 && y->year == delcar->year)
             break;
          x = x->next;
       }
       if (x->next != NULL){
           x->next = y->next;
       }
       else {
           printf("Car Not Found\n");
       }
    }
    return list;   
}







struct car *append_to_list(struct car *list){

        //add your code here and remove the return NULL; statement                                              //Add cars to the list
struct car* newCar = (struct car*)malloc(sizeof(struct car));
newCar->next = NULL;
        printf("Please enter the car make:\n ");
                read_line(newCar->make, LEN);
        printf("Please enter the model:\n ");
                read_line(newCar->model, LEN);
        printf("Please enter the car color:\n ");
                read_line(newCar->color, LEN);
        printf("Please enter the car year:\n ");
                scanf("%d", &newCar->year);
        printf("Please enter City MPG(Miles per Gallon):\n ");
                scanf("%d", &newCar->city_mpg);
        printf("Please enter Highway MPG(Miles per Gallon):\n ");
                scanf("%d", &newCar->highway_mpg);
        printf("Please enter quantity in stock:\n ");
                scanf("%d", &newCar->quantity);
struct car *x;
struct car *y;

x = list;
if(x == NULL)
{
x = newCar;
newCar->next = NULL;
}
else
{
while (x->next != NULL)
{													//line 90
          y = x->next;
          if (strcmp(y->make,newCar->make) < 0)
	  {
             break;
          }
          else if (strcmp(y->make,newCar->make) == 0)
	  {
                   if (strcmp(y->model,newCar->model) <= 0)
		   {
                      break;
          	   }
          x = x->next;
       	  }
       if (x->next != NULL)
       {
           newCar->next = y;
           x->next = newCar;    
       }
       else 
       {
           x->next = newCar;
           newCar->next = NULL;
       }
}
    return list; 
}

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

