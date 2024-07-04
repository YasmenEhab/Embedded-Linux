#include <stdio.h>
#include <string.h> 
#include <stdlib.h> // Include the stdlib.h header file for malloc
/*Write a program that reads a number of strings from the user, stores them in dynamically allocated memory, and then prints them out before deallocating the memory. The program should first ask the user how many strings they want to enter, and then read the strings one at a time.
The program should use a dynamically allocated array of pointers to store the strings.*/
int main() {
    
    int numOfStr;
    char buffer[30];
    
    printf("Enter the number of strings:\n");
    scanf("%d",&numOfStr);
    
    char ** arrOfStr = (char**) malloc(numOfStr *sizeof(char*));
    
    int *strlength = (int*) malloc(numOfStr * sizeof(int)); 
    for(int i=0 ;i< numOfStr ; i++)
    {
        printf("Enter string %d: ", i + 1);
        scanf("%s", buffer);
        strlength[i] = strlen(buffer) +1;
        arrOfStr[i] = (char*) malloc(sizeof(char) * strlength[i]);
        
        /*char *strcpy(char *dest, const char *src);*/
        strcpy( arrOfStr[i], buffer);
   
    }
        for(int i=0 ; i< numOfStr ; i++)
        {
        for(int j=0 ; j < strlength[i] ; j++)
            {
                printf("%c", arrOfStr[i][j]);
            
            }
        }
        printf("\n");
        
    /* When freeing memory, you need to reverse the process:*/
       for(int i=0 ; i< numOfStr ; i++)
       {
           free(arrOfStr[i]);
       }
       free(arrOfStr);
    
   
    

    return 0;
}
