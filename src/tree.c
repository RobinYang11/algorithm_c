
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

int main(int argc, char const *argv[])
{
	Tree tree;
	initTree(&tree);
	char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M',
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'	
	};
	insertTreeNode(-1, letters[0], &tree);
	insertTreeNode(0, letters[1], &tree);
	insertTreeNode(0, letters[2], &tree);
	insertTreeNode(0, letters[3], &tree);
	insertTreeNode(1, letters[4], &tree);
	insertTreeNode(1, letters[5], &tree);
	insertTreeNode(1, letters[6], &tree);
	insertTreeNode(2, letters[7], &tree);
	insertTreeNode(2, letters[8], &tree);
	insertTreeNode(2, letters[9], &tree);
	insertTreeNode(4, letters[10], &tree);
	insertTreeNode(10,letters[11],&tree);
	RDisplay(&tree, 0, 0);
	int deep =	treeDepth(&tree);
	printf("depth of the tree is:%d \n",deep);
	return 0;
}