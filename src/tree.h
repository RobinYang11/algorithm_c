
#define MAX 10
typedef struct TreeNode
{
  char value; 
  int parent;
} TreeNode;

typedef struct Tree
{

  TreeNode nodes[MAX];
  int nodeNum;
} Tree;