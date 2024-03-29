#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/hash.h"
#define CAPACITY 5000

struct hash_item
{
  char *key;
  char *value;
};

struct hash_table
{
  HashItem **items; // Contains an array of pointers to items;
  LinkedList **overflow_buckets;
  int size;
  int count;
};

struct linked_list
{
  HashItem *item;
  LinkedList *next;
};

int hash_func(char *key);
void handle_collision(HashTable *table, int index, HashItem *item);

HashTable *create_table(int size);
HashItem *create_item(char *key, char *value);
void hash_insert(HashTable *table, char *key, char *value);
char *hash_search(HashTable *table, char *key);
void hash_delete(HashTable *table, char *key);

void free_table(HashTable *table);
void print_search(HashTable *table, char *key);
void print_table(HashTable *table);

LinkedList **create_overflow_buckets(HashTable *table);
void free_overflow_buckets(HashTable *table);

LinkedList *create_list();
LinkedList *linked_list_insert(LinkedList *list, HashItem *item);
void free_linked_list(LinkedList *list);
HashItem *linked_list_remove(LinkedList *list);

int main()
{
  printf("1:%d \n", hash_func("1"));
  printf("Hel:%d \n", hash_func("Hel"));
  printf("Hel:%d \n", hash_func("Cau"));

  HashTable *h_table = create_table(CAPACITY);
  hash_insert(h_table, "name", "robin");
  hash_insert(h_table, "age", "33");
  hash_insert(h_table, "address", "china");
  hash_insert(h_table, "Hel", "Third address");
  hash_insert(h_table, "Cau", "Fourth address");
  print_search(h_table, "name");
  print_search(h_table, "age");
  print_search(h_table, "address");
  print_search(h_table, "Hel");
  print_search(h_table, "Cau");

  printf("OK \n");
  return 0;
}

HashItem *create_item(char *key, char *value)
{
  HashItem *item = (HashItem *)malloc(sizeof(HashItem));
  item->key = (char *)malloc(strlen(key) + 1);
  item->value = (char *)malloc(strlen(value) + 1);
  strcpy(item->key, key);
  strcpy(item->value, value);
  return item;
}

HashTable *create_table(int size)
{
  HashTable *table = (HashTable *)malloc(sizeof(HashTable));
  table->size = size;
  table->count = 0;
  table->items = (HashItem **)calloc(table->size, sizeof(HashItem *));
  for (int i = 0; i < table->size; i++)
  {
    table->items[i] = NULL;
  }
  table->overflow_buckets = create_overflow_buckets(table);
  return table;
}

int hash_func(char *key)
{
  int sum = 0;
  for (int i = 0; key[i]; i++)
  {
    sum += key[i];
  }
  return sum % CAPACITY;
}

void handle_collision(HashTable *table, int index, HashItem *item)
{
  LinkedList *head = table->overflow_buckets[index];
  if (head == NULL)
  {
    head = create_list();
    head->item = item;
    table->overflow_buckets[index] = head;
    return;
  }
  else
  {
    table->overflow_buckets[index] = linked_list_insert(head, item);
  }
}

void free_item(HashItem *item)
{
  free(item->key);
  free(item->key);
  free(item);
}

void free_table(HashTable *table)
{
  // Frees the table
  for (int i = 0; i < table->size; i++)
  {
    HashItem *item = table->items[i];
    if (item != NULL)
      free_item(item);
  }
  free_overflow_buckets(table);
  free(table->items);
  free(table);
}

void hash_insert(HashTable *table, char *key, char *value)
{
  // 创建hash 元素
  HashItem *item = create_item(key, value);
  // 计算hash index
  int index = hash_func(key);

  HashItem *current_item = table->items[index];

  // 判断 hash表当前位置是否有值
  if (current_item == NULL)
  {
    // 判断 hash表是否已经满了
    if (table->count == table->size)
    {
      printf("Insert Error: Hash Table is full \n");
      free_item(item);
      return;
    }
    table->items[index] = item;
    table->count++;
  }
  else
  {
    // 如果表中已经存在key 我们需要更新
    if (strcmp(current_item->key, key) == 0)
    {
      strcpy(table->items[index]->value, value);
      return;
    }
    else
    {
      handle_collision(table, index, item);
      return;
    }
  }
}

char *hash_search(HashTable *table, char *key)
{
  // Search the key in the hashtable
  // and returns NULL if it doesn't exist
  int index = hash_func(key);
  HashItem *item = table->items[index];
  LinkedList *head = table->overflow_buckets[index];

  while (item != NULL)
  {
    if (strcmp(item->key, key) == 0)
      return item->value;
    if (head == NULL)
      return NULL;
    item = head->item;
    head = head->next;
  }
  return NULL;
}

void hash_delete(HashTable *table, char *key)
{
  int index = hash_func(key);
  HashItem *item = table->items[index];
  LinkedList *head = table->overflow_buckets[index];
  if (item == NULL)
  {
    return;
  }
  else
  {
    if (head == NULL && strcmp(item->key, key) == 0)
    {
      table->items[index] = NULL;
      free_item(item);
      table->count--;
      return;
    }
    else if (head != NULL) // hash 冲突
    {
      if (strcmp(item->key, key) == 0)
      {
        free_item(item);
        LinkedList *node = head;
        head = head->next;
        node->next = NULL;
        table->items[index] = create_item(node->item->key, node->item->value);
        free_linked_list(node);
        table->overflow_buckets[index] = head;
        return;
      }

      LinkedList *curr = head;
      LinkedList *prev = NULL;
      while (curr)
      {
        if (strcmp(curr->item->key, key) == 0)
        {
          if (prev == NULL)
          {
            free_linked_list(head);
            table->overflow_buckets[index] = NULL;
            return;
          }
          else
          {
            prev->next = curr->next;
            curr->next = NULL;
            free_linked_list(curr);
            table->overflow_buckets[index] = head;
            return;
          }
        }
        curr = curr->next;
        prev = curr;
      }
    }
  }
}

void print_table(HashTable *table)
{
  for (int i = 0; i < table->size; i++)
  {
    if (table->items[i])
    {
      printf("%d,%s,%s \n", i, table->items[i]->key, table->items[i]->value);
    }
  }
}

void print_search(HashTable *table, char *key)
{
  char *val;
  if ((val = hash_search(table, key)) == NULL)
  {
    printf("key %s does not exist \n", key);
    return;
  }
  printf("Key:%s, Value:%s \n", key, val);
}

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

LinkedList **create_overflow_buckets(HashTable *table)
{
  LinkedList **buckets = (LinkedList **)calloc(table->size, sizeof(LinkedList **));
  for (int i = 0; i < table->size; i++)
  {
    buckets[i] = NULL;
  }
  return buckets;
}

void free_overflow_buckets(HashTable *table)
{
  LinkedList **buckets = table->overflow_buckets;
  for (int i = 0; i < table->size; i++)
  {
    free_linked_list(buckets[i]);
  }
  free(buckets);
}
