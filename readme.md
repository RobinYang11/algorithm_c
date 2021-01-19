
### 数据结构和算法 C语言复习

#### 树的存储方式
##### 一 双亲存储方法. 
 - 1. 找父节点容易O(1).
 - 2. 找子节点需要遍历O(n).
 - 3. 用数组存储所有节点 .
 - 4. 每个节点记录父节点索引.

节点的定义:
 ```c
  //节点定义
  typedef struct Node {
    char value;
    int parent;
  };
```
树的定义: 
```c
  //树的定义
  typedef struct Tree {
    //所有节点
    Node nodes[100];
    //节点数量
    int nodeNum;
  } 

 ```
##### 