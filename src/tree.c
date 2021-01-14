
#include <stdio.h>
#include <string.h>
#include "tree.h"

void initTree(Tree *tree)
{
  for (int i = 0; i < MAX; i++)
  {
    tree->nodes[i].value = '#';
    tree->nodes[i].parent = -1;
  }
  tree->nodeNum = 0;
}

void insertTreeNode(int parent, char value, Tree *tree)
{
  tree->nodes[tree->nodeNum].value = value;
  tree->nodes[tree->nodeNum].parent = parent;
  tree->nodeNum++;
}

