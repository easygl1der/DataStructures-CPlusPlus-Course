#include <iostream>
#include <stack>

// 二叉树节点结构
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 二叉排序树类（非递归实现）
class BinarySearchTree {
private:
    TreeNode* root;
    
    // 非递归插入节点
    void insertIterative(int value) {
        TreeNode* newNode = new TreeNode(value);
        
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        
        while (current != nullptr) {
            parent = current;
            if (value < current->value) {
                current = current->left;
            } else if (value > current->value) {
                current = current->right;
            } else {
                // 值已存在，不插入（可根据需求修改）
                delete newNode;
                return;
            }
        }
        
        if (value < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    
    // 非递归查找节点
    bool searchIterative(int value) const {
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (value == current->value) {
                return true;
            } else if (value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        return false;
    }
    
    // 非递归中序遍历
    void inorderIterative() const {
        std::cout << "Inorder traversal: ";
        std::stack<TreeNode*> s;
        TreeNode* current = root;
        
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            
            current = s.top();
            s.pop();
            std::cout << current->value << " ";
            
            current = current->right;
        }
        std::cout << std::endl;
    }
    
    // 非递归前序遍历
    void preorderIterative() const {
        std::cout << "Preorder traversal: ";
        if (root == nullptr) return;
        
        std::stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            std::cout << current->value << " ";
            
            if (current->right != nullptr) {
                s.push(current->right);
            }
            if (current->left != nullptr) {
                s.push(current->left);
            }
        }
        std::cout << std::endl;
    }
    
    // 非递归后序遍历
    void postorderIterative() const {
        std::cout << "Postorder traversal: ";
        if (root == nullptr) return;
        
        std::stack<TreeNode*> s1, s2;
        s1.push(root);
        
        while (!s1.empty()) {
            TreeNode* current = s1.top();
            s1.pop();
            s2.push(current);
            
            if (current->left != nullptr) {
                s1.push(current->left);
            }
            if (current->right != nullptr) {
                s1.push(current->right);
            }
        }
        
        while (!s2.empty()) {
            std::cout << s2.top()->value << " ";
            s2.pop();
        }
        std::cout << std::endl;
    }
    
    // 查找最小节点（非递归）
    TreeNode* findMin(TreeNode* node) const {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // 非递归删除节点
    void removeIterative(int value) {
        TreeNode* parent = nullptr;
        TreeNode* current = root;
        
        // 查找要删除的节点及其父节点
        while (current != nullptr && current->value != value) {
            parent = current;
            if (value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        
        if (current == nullptr) {
            // 未找到要删除的节点
            return;
        }
        
        // 情况1: 节点没有子节点或只有一个子节点
        if (current->left == nullptr || current->right == nullptr) {
            TreeNode* newChild = nullptr;
            
            if (current->left == nullptr) {
                newChild = current->right;
            } else {
                newChild = current->left;
            }
            
            if (parent == nullptr) {
                // 删除的是根节点
                root = newChild;
            } else if (current == parent->left) {
                parent->left = newChild;
            } else {
                parent->right = newChild;
            }
            
            delete current;
        }
        // 情况2: 节点有两个子节点
        else {
            // 找到右子树的最小节点
            TreeNode* successorParent = current;
            TreeNode* successor = current->right;
            
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }
            
            // 用后继节点的值替换当前节点的值
            current->value = successor->value;
            
            // 删除后继节点（后继节点最多有一个右子节点）
            if (successor == successorParent->left) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }
            
            delete successor;
        }
    }
    
    // 非递归计算树的高度
    int heightIterative() const {
        if (root == nullptr) return 0;
        
        std::stack<TreeNode*> nodeStack;
        std::stack<int> heightStack;
        nodeStack.push(root);
        heightStack.push(1);
        
        int maxHeight = 0;
        
        while (!nodeStack.empty()) {
            TreeNode* current = nodeStack.top();
            nodeStack.pop();
            int currentHeight = heightStack.top();
            heightStack.pop();
            
            if (currentHeight > maxHeight) {
                maxHeight = currentHeight;
            }
            
            if (current->right != nullptr) {
                nodeStack.push(current->right);
                heightStack.push(currentHeight + 1);
            }
            
            if (current->left != nullptr) {
                nodeStack.push(current->left);
                heightStack.push(currentHeight + 1);
            }
        }
        
        return maxHeight;
    }
    
    // 非递归销毁树
    void destroyTreeIterative() {
        if (root == nullptr) return;
        
        std::stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* current = s.top();
            s.pop();
            
            if (current->left != nullptr) {
                s.push(current->left);
            }
            if (current->right != nullptr) {
                s.push(current->right);
            }
            
            delete current;
        }
        
        root = nullptr;
    }
    
public:
    BinarySearchTree() : root(nullptr) {}
    
    ~BinarySearchTree() {
        destroyTreeIterative();
    }
    
    // 插入值
    void insert(int value) {
        insertIterative(value);
    }
    
    // 查找值
    bool search(int value) const {
        return searchIterative(value);
    }
    
    // 删除值
    void remove(int value) {
        removeIterative(value);
    }
    
    // 中序遍历
    void inorder() const {
        inorderIterative();
    }
    
    // 前序遍历
    void preorder() const {
        preorderIterative();
    }
    
    // 后序遍历
    void postorder() const {
        postorderIterative();
    }
    
    // 获取树的高度
    int height() const {
        return heightIterative();
    }
    
    // 检查树是否为空
    bool isEmpty() const {
        return root == nullptr;
    }
};

// 测试函数
int main() {
    BinarySearchTree bst;
    
    // 插入测试
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    
    // 遍历测试
    bst.inorder();
    bst.preorder();
    bst.postorder();
    
    // 查找测试
    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;
    
    // 删除测试
    std::cout << "\nDeleting 20 (no children)" << std::endl;
    bst.remove(20);
    bst.inorder();
    
    std::cout << "\nDeleting 30 (one child)" << std::endl;
    bst.remove(30);
    bst.inorder();
    
    std::cout << "\nDeleting 50 (two children)" << std::endl;
    bst.remove(50);
    bst.inorder();
    
    // 高度测试
    std::cout << "\nTree height: " << bst.height() << std::endl;
    
    return 0;
}
