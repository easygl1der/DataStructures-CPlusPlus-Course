//用多种方式建立二叉树，提供C++完整代码。
// 使用递归创建普通二叉树

#include <iostream>
using namespace std;

// 创建二叉树的节点结构
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归创建二叉树
TreeNode* createBinaryTree() {
	int value;
	cout << "Enter the value of the node (-1 for nullptr): ";
	cin >> value;
	if (value == -1) return nullptr;
	TreeNode* root = new TreeNode(value);
	cout << "Enter the left child of " << value << endl;
	root->left = createBinaryTree();
	cout << "Enter the right child of " << value << endl;
	root->right = createBinaryTree();
	return root;
}

// 前序遍历二叉树
void preorderTraversal(TreeNode* root) {
	if (root == nullptr) return;
	cout << root->val << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

int main() {
	TreeNode* root = createBinaryTree();
	cout << "Preorder Traversal of the created binary tree: ";
	preorderTraversal(root);
	cout << endl;
	return 0;
}
