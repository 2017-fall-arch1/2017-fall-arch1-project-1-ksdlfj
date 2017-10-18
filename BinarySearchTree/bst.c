#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/* Create a new 'empty' list*/
BSTItem *alloc(){
  BSTItem *root = (BSTItem *)malloc(sizeof(BSTItem));
  root->lesser = root->greater = NULL;
  root->name = "";
  return root;
}

/* Recycle a list, discarding all items it contains */
void freeList(BSTItem *root){
  emptyList(root);
  free(root);
}

/* Delete all elments off the list */
void emptyList(BSTItem *root){
  if(root == NULL){
    return;
  }
  emptyList(root->lesser);
  free(root->name);
  emptyList(root->greater);
  free(root);
  }

/* Inserts an item into the list*/
void insert(BSTItem *root, char *name){
  if(name == NULL){ // return if the name is nonexistent
    return;
  }
  if(root == NULL){
    root = createItem(name); 
  }
  char cmp_result = strcmp(name, root->name); // Compares names to check where it belongs
  if(cmp_result <= 0){
    insert(root->lesser,name); //Name to be inserted is less than current name
  }
  else{
    insert(root->greater,name); //Name to be inserted is greater than current name
  }
}

/* Create a new item */
BSTItem *createItem(char *name){
  int length; // Determines the length of the string
  char *scopy; // Copy of name
  BSTItem *newItem; //New item to be returned
  for(length = 0; name[length]; length++)
    ;
  scopy = (char *)malloc(length+1);
  for(length = 0; name[length]; length++)
    scopy[length] = name[length];
  scopy[length] = 0;

  // creation of item
  newItem = (BSTItem *)malloc(sizeof(BSTItem));
  newItem->name = scopy;
  newItem->lesser = NULL;
  newItem->greater = NULL;
  return newItem;
}

/* Prints the contents of the list inorder*/
void printList(BSTItem *root){
  if(root == NULL){
    return;
  }
  printList(root->lesser);
  printf("[%s]\n\n", root->name);
  printList(root->greater);
}
