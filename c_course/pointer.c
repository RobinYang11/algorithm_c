#include <stdio.h>

/**获取指针地址内的值*/
void get_value_in_pointer();

/** "*"在不同地方的用法*/
void confuse_of_star_matter();

int main()
{
  int a = 100;
  char str[20] = "www.robin.com";
  printf("%p,%p\n", &a, str);
  get_value_in_pointer();
  confuse_of_star_matter();
  return 0;
}

void confuse_of_star_matter()
{
  int a = 33;
  int b = 55;
  int *p = &a;                      // 这里的*号 代表p是一个指针;
  *p = 44;                          // 这里的*号是指向 指针地址内的值;
  printf(" value in p :%d \n", *p); // 44
  p = &b;                           // 这个地方就不能加*号
  printf(" value in p :%d \n", *p); // 44
}

void get_value_in_pointer()
{
  int *p;
  int a = 330;
  p = &a;
  printf("value in p%d  \n", *p);
}
