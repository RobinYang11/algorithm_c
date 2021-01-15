
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
  tree->nodes[tree->nodeNum].value = value;
  tree->nodes[tree->nodeNum].parent = parent;
  tree->nodeNum++;
}

/**
 * @param tree 树
 * 获取树的根节点
 **/
TreeNode getTreeRoot(Tree *tree)
{
  TreeNode treeNode;
  if(tree->nodeNum<0)
  {
    return treeNode;
  }
  for(int i= 0;i<tree->nodeNum;i++){
    if(tree->nodes[i].parent<0){
      treeNode= tree->nodes[i];
    }
  }
  return treeNode;
}




