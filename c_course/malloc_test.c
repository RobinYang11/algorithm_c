
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char *str;
  str = (char *)malloc(15);
  strcpy(str, "robin");
  printf("%s, %u", str, str);
  return 0;
}