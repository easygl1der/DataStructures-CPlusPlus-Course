#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelOrder(TreeNode* root) {
	if (!root) return;
	queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
	TreeNode* current = q.front();
	cout << current->val << " ";
	if (current->left) q.push(current->left);
	if (current->right) q.push(current->right);
	q.pop(); // 移除当前节点
}
}

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	
	levelOrder(root);
	delete root; // 释放内存
	return 0;
}

