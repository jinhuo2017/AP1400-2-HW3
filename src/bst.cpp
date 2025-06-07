#include "bst.h"

// Node类实现
BST::Node::Node(int value, Node *left, Node *right)
    : value(value), left(left), right(right) {
}

BST::Node::Node()
    : value(0), left(nullptr), right(nullptr) {
}

BST::Node::Node(const Node &node)
    : value(node.value), left(node.left), right(node.right) {
}

// 重载 Node << 操作
std::ostream& operator<<(std::ostream& os, const BST::Node& node) {
    os << &node << " => value:" << node.value << " left:" << node.left << " right:" << node.right;
    return os;
}

// 重载 BST << 操作
std::ostream& operator<<(std::ostream& os, const BST& bst) {
    // 使用 BFS 按层级打印树结构
    const BST::Node* root = bst.get_root();
    if (root == nullptr) {
        os << "(空树)";
        return os;
    }

    std::queue<const BST::Node*> q;
    q.push(root);

    while (!q.empty()) {
        size_t levelSize = q.size();
        for (size_t i = 0; i < levelSize; ++i) {
            const BST::Node* current = q.front();
            q.pop();
            os << current->value << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        os << "\n";  // 每层结束后换行
    }
    return os;
}

// 新增 const 版本的 get_root
const BST::Node* BST::get_root() const {
    return root;
}


// Node vs int 的比较
bool BST::Node::operator>(int val) const { return value > val; }
bool BST::Node::operator>=(int val) const { return value >= val; }
bool BST::Node::operator<(int val) const { return value < val; }
bool BST::Node::operator<=(int val) const { return value <= val; }
bool BST::Node::operator==(int val) const { return value == val; }

// int vs Node 的比较（友元函数）
bool operator>(int val, const BST::Node &node) { return val > node.value; }
bool operator>=(int val, const BST::Node &node) { return val >= node.value; }
bool operator<(int val, const BST::Node &node) { return val < node.value; }
bool operator<=(int val, const BST::Node &node) { return val <= node.value; }
bool operator==(int val, const BST::Node &node) { return val == node.value; }

// BST类实现
BST::Node *&BST::get_root() {
    return root;
}

void BST::bfs(std::function<void(Node * &node)> func) {
    if (root == nullptr) return;
    std::queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node * current = q.front();
        q.pop();

        func(current);
        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

bool BST::add_node(int value) {
    if (root == nullptr) {
        root = new Node(value, nullptr, nullptr);
        return true;
    }

    Node * current = root;
    while (true) {
        if (value == current->value) {
            return false; // 值已存在
        } else if (value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node(value, nullptr, nullptr);
                return true;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                current->right = new Node(value, nullptr, nullptr);
                return true;
            }
            current = current->right;
        }
    }
}

size_t BST::length() {
    size_t count = 0;
    bfs([&count](Node *&node) {
        count++;
    });
    return count;
}

BST::Node** BST::find_node(int val) {
    // 指向指针的指针
    Node** current = &root;
    while (*current != nullptr) {
        if (val == (*current)->value) {
            return current;
        } else if (val < (*current)->value) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    return nullptr;

}

BST::Node** BST::find_parrent(int val) {
    if (root == nullptr) return nullptr;

    // 如果BST的根结点和当前的相同
    if (root->value == val) return nullptr;

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        if (val < current->value) {
            parent = current;
            current = current->left;
        } else if (val > current->value) {
            parent = current;
            current = current->right;
        } else {
            // 找到节点，返回父节点指针的指针
            if (parent == nullptr) {
                return &root;
            }
            return &parent;
        }
    }
    return nullptr;


}




