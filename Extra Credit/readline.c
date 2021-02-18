//The function below reads from a line of characters, it is linked to numerous files where it is called
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include "readline.h"


int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
 }

