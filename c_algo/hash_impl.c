#include <stdio.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char *str);
void test_my_hash_idea();

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
  char *arr[1000];
  printf("out of index:%s \n", arr[999]);
  char *names[] = {"robin", "advid", "asdf"};
  for (int i = 0; i < 3; i++)
  {
    int sum = 0;
    for (int j = 0; names[i][j]; j++)
    {
      sum += names[i][j];
    }
    int index = sum % 1000;
    arr[index] = names[i];
  }
}

unsigned long hash_function(char *str)
{
  unsigned long i = 0;
  for (int j = 0; str[j]; j++)
    i += str[j];
  return i % CAPACITY;
}
