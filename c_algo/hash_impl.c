#include <stdio.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char *str);
void test_my_hash_idea();
int my_hash_function(char *str, int capacity);

int main()
{
  int r = 'a' + 'b';
  printf("%d \n", r);
  char *name = "robin_test_abc_deft_robin_asdfasdfasd";
  unsigned long name_index = hash_function(name);
  printf("%ld \n", name_index);
  test_my_hash_idea();
  return 0;
}

void test_my_hash_idea()
{
  int capacity = 1000;
  char *arr[capacity];
  printf("out of index:%s \n", arr[999]);
  char *names[] = {"robin", "advid", "asdf"};
  for (int i = 0; i < 3; i++)
  {
    int index = my_hash_function(names[i], capacity);
    arr[index] = names[i];
  }
  printf("test hash: %s \n", arr[my_hash_function("robin", capacity)]);
}

int my_hash_function(char *str, int capacity)
{
  int i = 0;
  for (int j = 0; str[j]; j++)
    i += str[j];
  return i % capacity;
}

unsigned long hash_function(char *str)
{
  unsigned long i = 0;
  for (int j = 0; str[j]; j++)
    i += str[j];
  return i % CAPACITY;
}
