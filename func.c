/*Written by L.Zhang for COMP20003, 19/8/18 */

#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define MAX_INPUT 512
#define N_DATA 15
#define KEY_POS 1

/*function to print out a message
used for debugging*/
void hello(void){
  printf("hello world\n");
}

/*Function to compare string by the character's alphabetical order.
Return -1 if str_1 has lower order.
Return 0 if str_1 and str_2 are the same.
Return 1 if str_1 has higher order.*/
int str_comparsion(char str1[MAX_STRING+1],char str2[MAX_STRING+1]){
  int i = 0;

  while(i < MAX_STRING+1){
    /*one of str_1 and str_2 has reached the end of the string.
    Therefore the shorter string has higher order.*/
    if (str1[i] == '\0' && str2[i] != '\0'){
      return 1;
    }
    if(str2[i] == '\0' && str1[i] != '\0'){
      return -1;
    }
    /*have not reach the end of the string*/
    /*char comparison*/

    /*str1's current character has a lower order*/
    if(str1[i] < str2[i]){
      return -1;
    }
    /*str2's current character has a lower order*/
    if(str2[i] < str1[i]){
      return 1;
    }
    /*Both strings have reach their end. They are the same.*/
    if(str1[i] == '\0' && str2[i] == '\0'){
      return 0;
    }
    i++;
  }

  exit(EXIT_FAILURE);
}
