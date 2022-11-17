
#include <stdio.h>

struct Node
{
  int value;
  struct Node *next;
  struct Node *pre;kjkj
};

struct Node *arr2list(int *arr, int size)
{

  struct Node *root;
  root->value = *(arr);
  for (int i = 1; i < size; i++)
  {
      
    struct Node *next;
    next->value = *(arr+i);
    root->next =next; 
    root = next;
  }
  return root;
}

void foreachList(struct Node *list)
{
  if (list != NULL)
  {
    printf("%d", list->value);
    if (list->next != NULL)
    {
      foreachList(list->next);
    }
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 6, 7, 9, 18, 20, 28, 33, 44, 78};
  struct Node *list = arr2list(arr, sizeof(arr) / sizeof(int));
  foreachList(list);
  return 0;
}