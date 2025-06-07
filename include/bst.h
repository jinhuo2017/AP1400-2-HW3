#ifndef BST_H
#define BST_H

#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using std::ostream;

class BST {
public:
    class Node {
    public:
        Node(int value, Node *left, Node *right);
        Node();
        Node(const Node &node);

        int value;
        Node *left;
        Node *right;

        friend std::ostream &operator<<(std::ostream &os, const Node &node);

        // 比较运算符（Node vs int）
        bool operator>(int val) const;
        bool operator>=(int val) const;
        bool operator<(int val) const;
        bool operator<=(int val) const;
        bool operator==(int val) const;

        // 比较运算符（int vs Node，声明为友元函数）
        friend bool operator>(int val, const Node &node);
        friend bool operator>=(int val, const Node &node);
        friend bool operator<(int val, const Node &node);
        friend bool operator<=(int val, const Node &node);
        friend bool operator==(int val, const Node &node);
    };

    Node *&get_root();
    const Node *get_root() const;
    void bfs(std::function<void(Node *&node)> func);
    size_t length();
    bool add_node(int value);
    Node **find_node(int value);
    Node **find_parrent(int value);
    Node **find_successor(int value);
    bool delete_node(int value);

    friend std::ostream& operator<<(std::ostream& os, const BST& bst);

private:
    Node *root;
};

#endif //BST_H
