
int MAX = 100;
char *CHILD = "C";
char *BROTHER = "B";

typedef struct Node
{
  char *value;
  //第一个子节点
  struct Node *firstChild;
  //兄弟节点
  struct Node *nextSiblings;
} Node;

typedef struct ChildLinkTree
{
  //根节点
  struct Node *root;
  //总元素个数
  int length;
} ChildLinkTree;