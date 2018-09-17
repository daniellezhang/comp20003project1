/*Written by L.Zhang for COMP20003, 19/8/18 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "func.h"

#define MAX_INPUT 512
#define KEY_POS 1

/*node structure for each record*/
struct athlete_t{
  data_t all_data;
  char key[MAX_STRING+1];
  struct athlete_t *left, *right, *parent;
};

/*function to insert a node to the bst*/
struct athlete_t *insert(struct athlete_t *parent, struct athlete_t *new){
  /*no parent, make the current node the header*/
  if(! parent){
    parent = new;

  }
  /*add the new node to the tree*/

  /*new node's key is lower than or equal to the parent,
  go to the left of the parent*/
  else if(str_comparsion((parent->key), (new->key)) > -1){
    new->parent = parent;
    parent->left = insert(parent->left, new);
  }
  /*new node's key is higher than the parent,
  go to the right of the parent*/
  else {
    new->parent = parent;
    parent->right = insert(parent->right, new);
  }
  return parent;
}


/*function to read the csv file and make a bst from the input data*/

struct athlete_t *makedict(FILE *datafile){
  int j;
  char s[MAX_INPUT+1];
  char *token;
  struct athlete_t *head = NULL, *new = NULL;


  /*reading datafile by line*/
  while(fgets(s, MAX_INPUT+1, datafile)){

    j = 0;
    /*create new node for the new line of data*/
    new = (struct athlete_t *)malloc(sizeof(struct athlete_t));

    token = strtok(s, ",");
    strcpy(new->all_data[0], token);
    /*split the line of data by the comma*/
    for(j=1;j<N_DATA;j++){

      token = strtok(NULL, ",");

      strcpy(new->all_data[j], token);
    }

    /*set the key of the new node*/
    strcpy(new->key, (new->all_data)[KEY_POS]);

    /*insert the new node to the tree*/
    head = insert(head, new);


  }
  return head;
}

/*function to search for the node that has the given key and write
the information about the athlete in the given file
return the number of key comparisons conducted*/
int search(struct athlete_t *head, char key[MAX_STRING+1], FILE *outputfile,
  int found){
  int count =  0;

  /*current node is not empty, can do key comparsion*/
  if(head){
    count ++;
    /*key equals to the node's key*/
    if(str_comparsion(head->key, key)==0){
      /*Write the data in the file*/
      fprintf(outputfile,"%s -->", key);
      fprintf(outputfile,"ID: %s Sex: %s ||",
       (head->all_data)[0],(head->all_data)[2]);
      fprintf(outputfile," Age: %s ||",(head->all_data)[3]);
      fprintf(outputfile," Height: %s ||",(head->all_data)[4]);
      fprintf(outputfile," Weight: %s ||",(head->all_data)[5]);
      fprintf(outputfile," Team: %s ||",(head->all_data)[6]);
      fprintf(outputfile," NOC: %s ||",(head->all_data)[7]);
      fprintf(outputfile," Games: %s ||",(head->all_data)[8]);
      fprintf(outputfile," Year: %s ||",(head->all_data)[9]);
      fprintf(outputfile," Season: %s ||",(head->all_data)[10]);
      fprintf(outputfile," City: %s ||",(head->all_data)[11]);
      fprintf(outputfile," Sport: %s ||",(head->all_data)[12]);
      fprintf(outputfile," Event: %s ||",(head->all_data)[13]);
      fprintf(outputfile," Medal: %s ||\n",(head->all_data)[14]);


      /*continue search in the left tree
      information has been found. Set the marker to 1*/
      count += search(head->left, key, outputfile, 1);
    }
    /*key has lower order than the current node's key*/
    else if(str_comparsion(head->key, key) == 1){
      /*The node has a left child, continue search in the left tree*/
      if(head->left){

        count += search(head->left, key, outputfile, found);
      }

      /*The node does not have a left child.End of search*/
      else{
        /*No information has been found so far. Write in the file.*/
        if(found == 0){
          fprintf(outputfile,"%s --> NOTFOUND\n", key);
        }
      }

    }
    /*key has higher order than the current node's key*/
    else{
      /*the node has a right child, continue the search in the right tree*/
      if(head->right){

        count += search(head->right, key, outputfile, found);
      }
      /*node has no right child.End of search*/
      else{
        /*No information has been found so far. Write in the file.*/
        if(found == 0){
          fprintf(outputfile,"%s --> NOTFOUND\n", key);
        }
      }
    }
  }

  return count;
}


/*function to free the bst's memory*/
void free_tree(struct athlete_t *head){
  if (! head){

    return;
  }

  /*freeing all the children*/
  free_tree(head->left);
  free_tree(head->right);
  /*all children freed, free the parent*/
  free(head);
}
