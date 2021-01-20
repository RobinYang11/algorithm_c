
### 数据结构和算法 C语言复习

#### 树的存储方式
##### 一 双亲存储方法. 
 - 1. 找父节点容易O(1).
 - 2. 找子节点需要遍历O(n).
 - 3. 用数组存储所有节点 .
 - 4. 每个节点记录父节点索引.
 - 5. 核心方法以及最优时间复杂度
   - a. 获取根节点 O(n)
   - b. 按层次输出树 最好的情况O(n) 最坏的情况O(n^2)  空间复杂度O(nlogn)
   - c. 获取树的深度，因为双亲表示法找父节点容易，所以获取树的深度，我可以遍历每个节点，然后向上找父节点。然后对比 获取其中最大的那个深度。时间复杂度O(n^2)

节点的定义:
 ```c
  //节点定义
  typedef struct Node {
    char value;
    int parent;
    int index;
  };
```
树的定义: 
```c
  #define MAX 100;
  //树的定义
  typedef struct Tree {
    //所有节点
    Node nodes[MAX];
    //节点数量
    int nodeNum;
  } 

 ```
#### 主要方法
  - 获取树的深度
    - 时间复杂度 O(n^2)
      - 没有优化的空间
    - 空间复杂度 O(1)

  ```c
    int treeDepth(Tree *tree){

      int i,j,maxDepth = 0;

      for(i = 0 ; i < tree->nodeNum; i++)
      {
        int depth = 0;
        // j从i 开始,执行完后，指向tree->nodes[j] 的parent
        for(j = i; j => 0 ; j = tree->nodes[j].parent){
          depth ++ ;
        }
      }

      if(depth > maxDepth)
      {
        maxDepth = depth;
      }
      return maxDepth;
    }

  ```