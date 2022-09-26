
#include <stdio.h>
#define ZERO 0;

int main()
{

  int arr[] = {1, 2, 3, 4};
  // 数组本身就是一个指针    p =  arr = &arr[0]  这3个都代表数组第一个元素的地址 即:数组首地址
  int *p = arr;

  //访问数组的元素 arr[i]  p[i]  或者 *(p+i)
  printf("%d arr[i]: \n", arr[1]);
  printf("%d p[i]: \n", p[1]);
  printf("%d *(p+i): \n", *(p + 1));

  // 遍历数组

  for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
  {
    printf("%d \n", *(p + i));
    printf("%d \n", p[i]);
    printf("%d \n", arr[i]);
  }
  return ZERO;
}
