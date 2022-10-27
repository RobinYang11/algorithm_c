

#include <string.h>



typedef struct Node
{
  char value ;
  struct Node *left;
  struct Node *right;  
};


struct Node  *init_binary_tree(struct Node *root){
  struct Node *binary_tree_root;
  binary_tree_root->value =NULL;
  binary_tree_root->right =NULL;
  binary_tree_root->left = NULL;
  return binary_tree_root;
}








