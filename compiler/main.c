
#include "plain.c"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main()
{

  char *exp = "1+2*3+4";
  char items[strlen(exp)];

  for (int i = 0; i < strlen(exp); i++)
  {
    if (isdigit(*(exp + i)) == 0)
    {
      printf("number");
    }
    printf("%c \n", *(exp + i));
    items[i] = *(exp + i);
  }

  return 0;
}