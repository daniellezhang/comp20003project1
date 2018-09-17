/*Written by L.Zhang for COMP20003, 19/8/18 */

#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <string.h>
#include "bst.h"



int main(int argc, char **argv){
  struct athlete_t *head = NULL;
  FILE *datafile;
  FILE *outputfile;
  char *key;
  char s[MAX_INPUT+1];
  int count;

  /*check if the input of command line is correct*/
  if(argc < 3){
    printf("Incorrect input.\n");
    exit(EXIT_FAILURE);
  }

  /*open the datafile*/
  datafile = fopen(argv[1],"r");

  /*make bst for the datafile*/
  head = makedict(datafile);

  /*finish creating bst from the datafile. close the file*/
  fclose(datafile);

  /*create outputfile*/
  outputfile = fopen(argv[2], "w");

  /*read the key from command line and search for the key in bst*/
  while(fgets(s, MAX_STRING+1, stdin)){
    /*remove the newline character from the key*/
    key = strtok(s, "\n");
    key = strtok(s, "\r");

    count = search(head, key, outputfile, 0);
    printf("%s -->%d\n", key, count);

  }

  /*finish the search. Free the tree*/
  free_tree(head);

  /*finish writing the file. close the file*/
  fclose(outputfile);
  return 0;

}
