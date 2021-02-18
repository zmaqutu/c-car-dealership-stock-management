//the code below takes the command line argument and displays the argument in alphabetical order

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(const void* x, const void* y);
int main(int argc, char *argv[])

{

	int size, tempS;								//declare variables 
	char array[argc - 1][50];

   
    for( int i = 1 ; i < argc ; i++ )

        strcpy(array[i - 1], argv[i]);

       

    size = sizeof(array[0]);

     tempS = sizeof(array)/size;


    qsort(array, tempS, size, check);						//call on qsort function is stdlib library

   

    for( int i = 0 ; i < argc - 1 ; i++ )
	{
        printf("%s ", array[i]);
	}
       
printf("\n");
    return 0;

}

int check(const void* x, const void* y)						//check function that checks the alphabetical order of each word

{

  const char *a = (const char *)x;

    const char *b = (const char *)y;


    return strcmp(a, b);

}

