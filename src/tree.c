
#include <stdio.h>
#include <string.h>
#include "tree.h"

/**
 * @param tree 树
 * 初始化树
 * */
void initTree(Tree *tree)
{
  for (int i = 0; i < MAX; i++)
  {
    tree->nodes[i].value = '#';
    tree->nodes[i].parent = -1;
  }
  tree->nodeNum = 0;
}

/**
 * @param parent  父节点索引
 * @param value   新节点值 
 * @param tree    树
**/
void insertTreeNode(int parent, char value, Tree *tree)
{
  // printf("%d\n", tree->nodeNum);
  tree->nodes[tree->nodeNum].value = value;
  tree->nodes[tree->nodeNum].parent = parent;
  tree->nodes[tree->nodeNum].index = tree->nodeNum;
  tree->nodeNum = tree->nodeNum + 1;
}

/**
 * @param tree 树
 * 获取树的根节点
 **/
TreeNode getTreeRoot(Tree *tree)
{
  TreeNode treeNode;
  if (tree->nodeNum < 0)
  {
    return treeNode;
  }
  for (int i = 0; i < tree->nodeNum; i++)
  {
    if (tree->nodes[i].parent < 0)
    {
      treeNode = tree->nodes[i];
    }
  }
  return treeNode;
}


/**
 * 按层次展示树
 **/
void RDisplay(Tree *tree, int index, int gap)
{
  //层次缩进
  for (int i = 0; i < gap; i++)
  {
    printf("_"); //用来显示树的层次
  }
  printf("%c \r\n", tree->nodes[index].value);

  //循环查找当前节点的子节点，递归展示
  for (int i = index; i < tree->nodeNum; i++)
  {
    if (index == tree->nodes[i].parent)
    {
      RDisplay(tree, i, gap + 1);
    }
  }
}

/**
 * @param tree  树 
 *  获取树的深度 
 **/
int treeDepth(Tree *tree)
{
  int maxDeep =0;
  for(int i = 0 ;i<tree->nodeNum;i++)
  {
    int deep =0;
    //每次执行完，指向父节节点 
    for(int j=i;j>=0;j=tree->nodes[j].parent)
    {
      deep++; 
    }

    if(deep>maxDeep){
      maxDeep = deep;
    }
  }
  return maxDeep;
}
