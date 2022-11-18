
## 指针就是地址,地址就是指针 !
### 指针  [指针就是地址  地址就是指针]
- 1. 我们把变量的在存储的地址叫<strong>指针</strong>
- 2. 使用&加变量名就可以获取到变量的地址
  ```c
    int a = 100; 
    &a // &a是变量的地址
  ```
- 3. 数组的的变量名本身就是一个指向数组第一个元素的指针,
所以我们不用&

```c
#include <stdio.h>
int main(){
    int a = 100;
    char str[20] = "c.biancheng.net";
    printf("%#X, %#X\n", &a, str);
    return 0;
}
```

### 2. 定义指针
#### 定义语法
```c
   datatype *name; //或者
   datatype *name = value ;
```
- 1. "*" 代表 name 是一个指针变量, datatype表示地址内存储的类型.
```c 
  int a = 100;
  int *p_a = &a;
```

### 3. 获取指针地址内存的值  *pointer;
```c
  *pointer //
```
- 1.  


