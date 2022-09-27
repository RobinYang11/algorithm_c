
#include <stdio.h>
#include <string.h>
#include "link_tree.h"

Node *insertChild(char *type,
                  struct ChildLinkTree *tree,
                  char *value,
                  struct Node *currentNode)
{
  struct Node node = {"P", NULL, NULL};
  struct Node *pnode = NULL;
  pnode = &node;
  pnode->value = value;

  if (currentNode == NULL)
  {
    tree->root = pnode;
    return pnode;
  }
  // printf("not empty \n");
  if (0 == strcmp(type, CHILD))
  {
    // printf("equal \n");
    currentNode->firstChild = pnode;
  }
  else
  {
    // printf("not equal");
    currentNode->nextSiblings = pnode;
  }
  return pnode;
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

void display(Node *node, int gap)
{

  int g = 0;
  while (g < gap)
  {
    printf("_");
    g++;
  }

  printf("%s\n", node->value);
  if (node->firstChild != NULL)
  {
    printf("%s",node->firstChild->value);
    // display(node->firstChild, gap++);
  }
  // else
  // {
  //   return;
  // }

  // if(node->nextSiblings != NULL)
  // {
  //   display(node->nextSiblings,gap++);
  // }
}

int main(int argc, char const *argv[])
{
  ChildLinkTree tree;
  initTree(&tree);
  Node *node;

  node = insertChild(CHILD, &tree, "A", NULL);
  // printf("%s", node->value);
  node = insertChild(CHILD, &tree, "B", node);
  // printf("%s", node->value);

  node = insertChild(CHILD, &tree, "C", node);
  node = insertChild(CHILD, &tree, "D", node);
  node = insertChild(CHILD, &tree, "E", node);
  node = insertChild(CHILD, &tree, "F", node);
  node = insertChild(CHILD, &tree, "G", node);
  node = insertChild(CHILD, &tree, "H", node);
  display(tree.root, 0);

  return 0;
}
