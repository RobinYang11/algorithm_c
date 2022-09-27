
#define MAX 100
typedef struct TreeNode
{
  char value; 
  int parent;
  int index;
} TreeNode;

typedef struct Tree
{

  TreeNode nodes[MAX];
  int nodeNum;
} Tree;