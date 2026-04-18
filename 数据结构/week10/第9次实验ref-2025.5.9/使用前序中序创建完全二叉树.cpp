//递归构建二叉树通常涉及到创建根节点，然后根据输入的值递归地创建左子节点和右子节点。这种方法简单直观，但可能会导致栈溢出错误。

#include <iostream>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int preOrder[] , int inOrder[], int start, int end) {
	if (start >= end) return NULL;
	int rootVal = inOrder[start];
	TreeNode* root = new TreeNode(rootVal);
	int index = start;
	while (true) {
		// 找到根节点的值在inOrder中的位置
		while (preOrder[index] != rootVal) index++;
		if (index == end) break;
		// 创建当前节点的左子树
		root->left = buildTree(preOrder, inOrder, start, index - 1);
		// 创建当前节点的右子树
		root->right = buildTree(preOrder, inOrder, index + 1, end);
	}
	return root;
}

int main() {
	int preOrder[] = {3, 4, 20, 10, 15};
	int inOrder[] = {8, 9, 10, 20, 15};
	TreeNode* root = buildTree(preOrder, inOrder, 0, 4);
	delete root; // 记得释放内存
	return 0;
}



