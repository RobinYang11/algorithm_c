
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header/hash.h"

struct linked_list
{
  HashItem *item;
  LinkedList *next;
};

LinkedList *create_list()
{
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  return list;
}

LinkedList *linked_list_insert(LinkedList *list, HashItem *item)
{
  if (!list)
  {
    LinkedList *head = create_list();
    head->item = item;
    head->next = NULL;
    list = head;
    return list;
  }
  else if (list->next == NULL)
  {
    LinkedList *node = create_list();
    node->item = item;
    node->next = NULL;
    list->next = node;
    return list;
  }

  // 获取list中的最后一个元素
  LinkedList *temp = list;
  while (temp->next->next)
  {
    temp = temp->next;
  }

  LinkedList *node = create_list();
  node->item = item;
  node->next = NULL;
  // 插入list的最后一个元素后面
  temp->next = node;
  return list;
}

HashItem *linked_list_remove(LinkedList *list)
{

  if (!list)
  {
    return NULL;
  }
  if (!list->next)
  {
    return NULL;
  }

  LinkedList *node = list->next;
  LinkedList *temp = list;

  temp->next = NULL;
  list = node;
  HashItem *it = NULL;
  memcpy(temp->item, it, sizeof(HashItem));
  free(temp->item->key);
  free(temp->item->value);
  free(temp->item);
  free(temp);
  return it;
}

void free_linked_list(LinkedList *list)
{
  LinkedList *temp = list;
  while (list)
  {
    temp = list;
    list = list->next;
    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
  }
}

int main()
{
  printf("OK /n");
  return 0;
}