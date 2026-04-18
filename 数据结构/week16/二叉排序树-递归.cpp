#include <iostream>

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    void insert(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
        } else if (value < node->value) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    bool search(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        } else if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            // 找到要删除的节点
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // 找到右子树的最小值（后继节点）
            TreeNode* temp = findMin(node->right);
            node->value = temp->value;  // 替换值
            node->right = deleteNode(node->right, temp->value);  // 删除后继节点
        }
        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inorderTraversal(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    void clear(TreeNode* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clear(root);
    }

    void insert(int value) {
        insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorderTraversal() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    int searchValue = 4;
    if (bst.search(searchValue)) {
        std::cout << searchValue << " is found in the tree." << std::endl;
    } else {
        std::cout << searchValue << " is not found in the tree." << std::endl;
    }

    std::cout << "Deleting 3..." << std::endl;
    bst.deleteNode(3);
    std::cout << "Inorder Traversal after deletion: ";
    bst.inorderTraversal();

    std::cout << "Deleting 5..." << std::endl;
    bst.deleteNode(5);
    std::cout << "Inorder Traversal after deletion: ";
    bst.inorderTraversal();

    return 0;
}


