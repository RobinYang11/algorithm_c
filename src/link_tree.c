
#include <stdio.h>
#include <string.h>
#include "link_tree.h"

Node *insertChild(char type,
                  struct ChildLinkTree *tree,
                  char value,
                  struct Node *parent)
{
  struct Node *node;
  node->value = value;

  if (parent == NULL)
  {
    tree->root = node;
    return node;
  }

  if (strcmp(type, CHILD))
  {
    parent->firstChild = node;
  }
  else
  {
    parent->nextSiblings = node;
  }
  return node;
}

/**
 * 初始化树 
 **/
void initTree(ChildLinkTree *tree)
{
  tree->length = 0;
  tree->root = NULL;
}

/**
 * 获取树的深度 
 **/
int treeDepth(ChildLinkTree *tree)
{
  int depth = 0;
  Node *currentNode = tree->root;

  if (currentNode == NULL)
  {
    return 0;
  }

  while (currentNode != NULL)
  {
    currentNode = currentNode->firstChild;
    depth++;
  }
  return depth;
}

int main(int argc, char const *argv[])
{
  ChildLinkTree tree;
  initTree(&tree);
  Node *node;
  node = insertChild(CHILD, &tree, 'A', NULL);
  node = insertChild(CHILD, &tree, 'B', node);
  node = insertChild(CHILD, &tree, 'C', node);
  node = insertChild(CHILD, &tree, 'D', node);
  node = insertChild(CHILD, &tree, 'E', node);
  node = insertChild(CHILD, &tree, 'F', node);
  node = insertChild(CHILD, &tree, 'G', node);
  node = insertChild(CHILD, &tree, 'H', node);

  printf("%c \n", node->value);
  return 0;
}
