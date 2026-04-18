//使用数组创建完全二叉树
//这种方法假设你有一个按照层序遍历顺序的数组。

#include <iostream>
#include <vector>
using namespace std;

// 创建完全二叉树的节点结构
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 使用数组创建完全二叉树
TreeNode* createCompleteBinaryTree(const vector<int>& nums, int index, int n) {
	if (index >= n || nums[index] == -1) return nullptr;
	TreeNode* root = new TreeNode(nums[index]);
	root->left  = createCompleteBinaryTree(nums, 2 * index + 1, n);
	root->right = createCompleteBinaryTree(nums, 2 * index + 2, n);
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
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	TreeNode* root = createCompleteBinaryTree(nums, 0, nums.size());
	preorderTraversal(root);
	cout << endl;
	return 0;
}
