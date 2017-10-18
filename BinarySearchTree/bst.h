#ifndef bstlist_included        /* prevents multiple inclusion */
#define bstlist_included

/* a binary search tree item */
typedef struct node_s{
  struct node_s *lesser, *greater;
  char *name;
} BSTItem;

/* Create a new 'empty' list */
BSTItem *alloc();

/* Recycle a list, discarding all items it contains */
void freeList(BSTItem *root);

/* Insert an item into the list */
void insert(BSTItem *root, char *name);

/* Create a new item */
BSTItem *createItem(char *name);

/* Delete all elemtns of the list */
void emptyList(BSTItem *root);

/* Prints the contents of the list inorder */
void printList(BSTItem *root);

#endif /* included */
