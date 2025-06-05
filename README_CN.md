# 高级编程 - 作业3

<p align="center"> <b>作业 3 - 2022 年春季学期 <br> 截止日期：法尔瓦丁月 14 日（周日）晚上 11:59</b> </p>
## 大纲
在本次作业中，我们将实现一个*二叉搜索树（Binary Search Tree, BST）*。*二叉树*是一种树形图，其中每个节点最多可以有 2 个子节点。*二叉搜索树*是一种二叉树，其中每个节点的右子节点的值大于左子节点的值。
我们将实现两个类，其中一个名为 `Node`，它表示图中的每个节点；另一个名为 `BST`，它负责以一种构建二叉搜索树的方式连接节点。由于 `Node` 类是 `BST` 类的直接属性，因此它应该在 `BST` 类内部定义。
**注意**：你只允许修改 `bst.cpp/h` 文件以及 `main.cpp` 文件中的调试部分。
</br>
# 节点类
使用下面的代码片段来实现这个类。**注意**：如果需要，你可能需要为这些函数添加一些关键字。除了这些关键字之外，你不允许更改这些函数，也不允许向这个类添加新的成员函数，**除非以下另有说明**。
```cpp
class Node
{
public:
 Node(int value, Node* left, Node* right);
 Node();
 Node(const Node& node);
 int value;
 Node* left;
 Node* right;
};
```
---
每个节点都有一个整数值，并且可以使用左指针和右指针指向它的子节点。如果一个或多个子节点不存在，则将 `nullptr` 赋值给它们。
- **标准输出（std::cout）**
实现 `<<` 运算符，以便你可以使用 `std::cout` 以美观的方式在一行中打印一个节点。输出应包含节点的地址、节点的值、节点的左子节点地址和节点的右子节点地址。
- **与整数的比较运算**
实现适当的函数，以便可以对节点和整数进行所有可能的比较运算，例如：
```cpp
node > 4 node >= 5 node < 6 node <= 5 node == 3
5 < node 6 <= node 2 > node 2 >= node 3 == node
```
</br>
# 二叉搜索树类
使用下面的代码片段来实现这个类。**注意**：如果需要，你可能需要为这些函数添加一些关键字。除了这些关键字之外，你不允许更改这些函数，也不允许向这个类添加新的成员函数，**除非以下另有说明**。
```cpp
class BST
{
public:
 Node*& get_root();
 void bfs(std::function<void(Node*& node)> func);
 size_t length();
 bool add_node(int value);
 Node** find_node(int value);
 Node** find_parrent(int value);
 Node** find_successor(int value);
 bool delete_node(int value);
private:
 Node* root;
};
```
---
这个类负责以适当的方式连接节点来构建一个二叉搜索树图。`root` 是这个类的唯一成员变量，它指向二叉搜索树的第一个节点。
- **获取根节点（get_root）**
返回私有成员变量 `root`。
- **广度优先搜索（bfs）**
*广度优先搜索（Breadth-first search, BFS）* 是一种通过遍历树中的每个节点来搜索树的算法。请实现这个算法！这个函数有一个 `std::function` 类型的输入，这种类型的行为类似于函数指针，可以包装 C++ 中的任何可调用对象，例如普通函数或 lambda 函数。在本次作业中，你将使用 lambda 函数，所以可以自由搜索并学习相关知识。用户应该能够使用这个参数并对树的节点应用任何函数，即对 BFS 算法找到的每个节点调用对象 `func`。
- **节点数量（length）**
返回二叉搜索树中存在的节点数量。
- **添加节点（add_node）**
将一个新节点添加到二叉搜索树的适当位置。**注意**：用户不应该能够添加已经存在于树中的值。
- **查找节点（find_node）**
在树中查找具有指定值的节点，并返回该节点指针的指针。**注意**：不要使用 BFS 算法来查找节点，而是使用二叉搜索树的特性：*这就是我们首先使用它们的原因*。
- **查找父节点（find_parrent）**
查找具有指定值的节点的父节点，并返回该父节点指针的指针。**注意**：不要使用 BFS 算法来查找节点。
- **查找后继节点（find_successor）**
查找具有指定值的节点的后继节点。
- **删除节点（delete_node）**
删除具有指定值的节点。如果不存在具有该值的节点，则返回 false。
- **标准输出（std::cout）**
实现 `<<` 运算符，以便你可以使用 `std::cout` 以美观的方式打印一个二叉搜索树。为此，请打印二叉搜索树的每个节点。如果你能生成如下所示的输出，你将获得额外的分数（星号是输出的一部分）。
```cpp
********************************************************************************
0x188dee70 => value:25 left:0x188dedd0 right:0x188dedf0 
0x188dedd0 => value:10 left:0x188dee30 right:0x188ded90 
0x188dedf0 => value:50 left:0 right:0x188dee50 
0x188dee30 => value:7 left:0 right:0 
0x188ded90 => value:15 left:0 right:0 
0x188dee50 => value:53 left:0 right:0 
binary search tree size: 6
******************************************************************************** 
```
- **自增运算符（operator++）**
实现两个 `++` 运算符，以便它们可以将树中每个节点的值加 1。别忘了 `bst++` 和 `++bst` 之间的区别。
- **析构函数**
如你所知，当在类中处理动态对象时，创建析构函数是必要的。幸运的是，我将亲自承担你析构函数的实现，所以请将以下代码作为你的类析构函数来实现。
```cpp
BST::~BST()
{
 std::vector<Node*> nodes;
 bfs([&nodes](BST::Node*& node){nodes.push_back(node);});
 for(auto& node: nodes)
 delete node;
}
```
- **构造函数**
为该类实现 3 个构造函数：**I)** 默认构造函数。**II)** 拷贝构造函数。**III)** 移动构造函数。
- **赋值运算符（operator=）**
实现 `operator=` 的两个版本（拷贝和移动版本）。
</br> 
# 挑战
- 如果你到达了这一部分，恭喜你，只剩下最后一部分了，而且这部分很简单。进行相应的安排，以便你可以使用构造函数添加任意数量的节点。这意味着以下代码应该能够正常工作。
```cpp
BST bst1{5, 1, 10, 2, 8, 50, 4, 60};
BST bst2{3, 2, 100, 20, 8, 50, 4, 60, 44, 23};
```
</br>
# 最后
如前所述，除非另有说明，否则不要修改已经填充的其他文件。如果你想测试你的代码，可以使用 `main.cpp` 文件中的 `debug` 部分。
```cpp
if (true) // 将其设为 false 以运行单元测试 
{ 
// 调试部分 
} 
else 
{ 
::testing::InitGoogleTest(&argc, argv); 
std::cout << "RUNNING TESTS ..." << std::endl; 
int ret{RUN_ALL_TESTS()}; 
if (!ret) 
std::cout << "<<<SUCCESS>>>" << std::endl; 
else 
std::cout << "FAILED" << std::endl; 
} 
return 0;
```
<br/>
<p align="center"> <b>祝你好运</b> </p>