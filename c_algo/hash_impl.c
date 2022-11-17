#include <stdio.h>

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(char *str)
{
  unsigned long i = 0;
  for (int j = 0; str[j]; j++)
    i += str[j];
  return i % CAPACITY;
}

int main()
{
  // int r = 'a' + 'b';
  // printf("%d", r);

  char *name = "robin_test_abc_deft_robin_asdfasdfasdfkgkasdgkagkgaksgkasgjaskgjkasgjkasgjkasjgkasddgj";
  unsigned long name_index = hash_function(name);
  printf("%ld", name_index);
  return 0;
}

void test_my_hash_idea(){
  int char*[];
}