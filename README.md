# c++ list


### 参考STL 实现了一个简易版本的list， 目前功能还不全。

## 支持的功能：
+ ### public 方法:

  
  

  
  |方法|描述|
  |  ----  | ----  |
  |iterator begin()|头部迭代器械|
  |iterator end()|尾部迭代器|
  |void push_back(T value)|尾部添加一个元素|
  |void push_front(T value)|头部添加一个元素|
  |void pop_back()|移除尾部元素|
  | void pop_front()|移除头部元素|
  | iterator erase(iterator position)|擦出迭代器指向一个元素|
  |void clear()|清除所有元素|
  |iterator erase(iterator first,iterator last)|擦出迭代器fisrt- last中的元素|
  |iterator insert(iterator position, const T& value)|插入一个元素|
  |void insert(iterator position, iterator first, iterator last)|插入一个区间的元素|
  |void insert(iterator position, unsigned int  n, const T& x)|插入 n 个元素|
  |reference front()|返回头部元的引用|
  |reference back()|返回尾部元素的引用|
  |bool empty()|判断是否为空|
  

+ ### protected 方法:
 
  |方法|描述|
  |  ----  | ----  |
  |void destory(linknode position)|清除内部节点内存(erase 内部调用)|
  
  
### 备注：
#### 只是自己代码练习，正在学习STL的同学也可参考， 会比STL 源码更清晰，更好理解，c++11 实现

### 编译：不依赖任何环境
+ #### mkdir build
+ #### cd build
+ #### cmake .. 
+ #### make



