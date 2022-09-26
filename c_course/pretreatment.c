
#include <stdio.h>

#define ADD_EXP (m + n)
#define TURE 1
#define FALSE 0

//使用尖括号< >和双引号" "的区别在于头文件的搜索路径不同：
//使用尖括号< >，编译器会到系统路径下查找头文件；
//而使用双引号" "，编译器首先在当前目录下查找头文件，如果没有找到，再到系统路径下查找

#if __WIN32
#include <window.h>
#elif __linux__
#include <unistd.h>
#endif

void test_define_exp();
void test_define_const();

int main()
{
#if _WIN32
  Sleep(5000);
#elif __linux__
  sleep(1);
#endif
  printf("time delay!");
  test_define_exp();
  test_define_const();
  return 0;
}

void test_define_const()
{
  if (TURE)
  {
    printf("TRUE:%d \n", TURE)
  }
}

void test_define_exp()
{
  int m = 3;
  int n = 4;
  printf("m*n : %d \n", ADD_EXP);
}
