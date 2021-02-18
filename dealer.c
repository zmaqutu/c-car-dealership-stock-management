//The program below represents a stock management system by a car dealer
//The code has four functions that help the dealer find cars he has in stock, print the entire stock list, and delete all records
//Author @Zongo Justin Maqutu
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "car.h"
#include "readline.h"


/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct car *car_list = NULL;  
  printf("Operation Code: a for appending to the list, f for finding a car"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': car_list = append_to_list(car_list);
                break;
      case 'f': find_car(car_list);
                break;
      case 'p': printList(car_list);
                break;
      case 'q': clearList(car_list);
		return 0;
      case 'd': delete_from_list(car_list);
            break;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}


