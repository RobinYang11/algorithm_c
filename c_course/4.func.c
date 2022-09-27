
#include <stdio.h>
#define FALSE 0;

// 测试函数返回数组
int *test_return_array(int *arr);

int main(){
  int arr[4];
  int *n;
  n =test_return_array(arr);

  for(int i = 0 ; i<4;i++){
    printf("%d",n[i]);
  }
}

int *test_return_array(int *arr){
  for(int i = 0 ; i<4;i++){
    arr[i] =i;
    printf("%d",arr[i]);
  }
  return arr;
}
