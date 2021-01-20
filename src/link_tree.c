
#include <stdio.h>
#include <string.h>
#include "link_tree.h"

void insertChild(char type,
                 struct ChildLinkTree *tree,
                 char value,
                 struct Node *parent)
{
  if(parent != NULL)
  {
    if(strcmp(type,CHILD)) 
    {
      printf("hello world");
    }
  }

}

int treeDepth(ChildLinkTree* tree)
{

  int depth = 0;
  Node* currentNode =tree->root;

  if(currentNode == NULL)
  {
    return 0;
  }

  while (currentNode != NULL)
  {
   currentNode = currentNode->firstChild;    
   depth ++;
  }

  return depth;
}


int main(int argc, char const *argv[])
{
  /* code */
  printf("hello world!");
  return 0;
}

