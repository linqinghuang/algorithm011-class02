# 第三周

### 排列和组合
组合是元素无序的排列

排列公式：

```math
A^m_n = \frac{n!}{(n - m)!}
```

排列公式：

```math
C^m_n = \frac{n!}{(n - m)!(m!)}
```

### 递归与回溯

#### 递归

递归难度不低，即便是有模板，但是要在脑海或者纸张上形成递归树也是不容易的。递归函数的参数如何设置，全局的还是局部的，内容又是如何变化的。终止条件是怎么样子的？这些都需要练习才行。

#### 回溯

回溯做法整体上也是递归，思考的时候只要按照递归的模板来就行了。但是需要额外加一个数据结构，用于做路径的记录以及回撤。

cpp中一般使用vector，vector是连续内存空间，等于数组，但是做回撤删除的时候并不会消耗O(n)的时间复杂度，因为vector提供的push_back以及pop_back方法都是在连续空间的尾部进行操作，时间复杂度都是O(1)的。

回溯函数中尽量不要使用局部变量，这会使得栈空间的使用大大增加，因为每层栈都会重新申请一部分空间。可以使用全局变量或者函数参数使用引用。

#### 递归模板

```cpp

void recursion(int level) {
    //terminator, total is global
    if （level == total) {
        return;
    }
    //process
    //drill down
    //merge
}

```

```cpp

void recursion(int level) {
    //terminator
    if （level == total) {
        return;
    }
    //process
    //drill down
    //backtracking
}

```