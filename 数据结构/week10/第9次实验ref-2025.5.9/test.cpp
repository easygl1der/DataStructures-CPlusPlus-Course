#include <iostream>
#include <queue>

// 假设 BiNode 定义如下（与 hw1.cpp 保持一致）
template <typename DataType>
struct BiNode {
    DataType data;
    BiNode<DataType> *lchild, *rchild;
};

template<typename DataType>
int getTreeDepthRecursiveNodes(BiNode<DataType> *root) {
    if (root == nullptr) {
        return 0; // 空树0个节点
    }
    int leftDepth = getTreeDepthRecursiveNodes(root->lchild);
    int rightDepth = getTreeDepthRecursiveNodes(root->rchild);
    return 1 + std::max(leftDepth, rightDepth);
}

// 测试代码
int main() {
    // 构造如下二叉树:
    //      A
    //     / \
    //    B   C
    //   /   / \
    //  D   E   F
    //         /
    //        G
    BiNode<char>* nodeA = new BiNode<char>{'A', nullptr, nullptr};
    BiNode<char>* nodeB = new BiNode<char>{'B', nullptr, nullptr};
    BiNode<char>* nodeC = new BiNode<char>{'C', nullptr, nullptr};
    BiNode<char>* nodeD = new BiNode<char>{'D', nullptr, nullptr};
    BiNode<char>* nodeE = new BiNode<char>{'E', nullptr, nullptr};
    BiNode<char>* nodeF = new BiNode<char>{'F', nullptr, nullptr};
    BiNode<char>* nodeG = new BiNode<char>{'G', nullptr, nullptr};

    nodeA->lchild = nodeB;
    nodeA->rchild = nodeC;
    nodeB->lchild = nodeD;
    nodeC->lchild = nodeE;
    nodeC->rchild = nodeF;
    nodeF->lchild = nodeG;

    int depth = getTreeDepthRecursiveNodes(nodeA);
    std::cout << "The depth of the tree is: " << depth << std::endl; // 预期输出: 3

    // 测试空树
    BiNode<char>* emptyRoot = nullptr;
    std::cout << "The depth of an empty tree is: " << getTreeDepthRecursiveNodes(emptyRoot) << std::endl; // 预期输出: 0

    // 释放内存
    delete nodeG;
    delete nodeF;
    delete nodeE;
    delete nodeD;
    delete nodeC;
    delete nodeB;
    delete nodeA;

    return 0;
}