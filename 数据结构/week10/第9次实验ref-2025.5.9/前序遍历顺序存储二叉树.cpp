#include <iostream>
#include <vector>
#include <optional> // C++17 or later for std::optional

// 简要的前序遍历递归函数
// tree: 顺序存储的二叉树 (用vector<optional<T>>表示)
// index: 当前节点的索引
void preorder_sequential_brief(const std::vector<std::optional<int>>& tree, int index) {
    // 1. 越界或当前节点为空，则返回
    if (index >= tree.size() || !tree[index].has_value()) {
        return;
    }

    // 2. 访问根节点（当前节点）
    std::cout << tree[index].value() << " ";

    // 3. 递归遍历左子树
    preorder_sequential_brief(tree, 2 * index + 1);

    // 4. 递归遍历右子树
    preorder_sequential_brief(tree, 2 * index + 2);
}

// 主函数 - 调用示例
int main() {
    // 示例树:
    //       10 (索引0)
    //      /  \
    //     20   30 (索引1, 2)
    //    /      \
    //   40       50 (索引3, 6)
    // 为了存储索引6，vector大小至少为7
    std::vector<std::optional<int>> my_tree(7); // 初始化为空

    my_tree[0] = 10;
    my_tree[1] = 20;
    my_tree[2] = 30;
    my_tree[3] = 40; // 20的左孩子
    // my_tree[4] 为空 (20的右孩子)
    // my_tree[5] 为空 (30的左孩子)
    my_tree[6] = 50; // 30的右孩子

    std::cout << "前序遍历: ";
    if (!my_tree.empty() && my_tree[0].has_value()) {
        preorder_sequential_brief(my_tree, 0); // 从根节点（索引0）开始
    } else {
        std::cout << "树为空或根节点不存在";
    }
    std::cout << std::endl; // 输出: 10 20 40 30 50

    // 另一个例子: 只有根
    std::vector<std::optional<int>> root_only_tree(1);
    root_only_tree[0] = 5;
    std::cout << "前序遍历 (只有根): ";
    if (!root_only_tree.empty() && root_only_tree[0].has_value()) {
        preorder_sequential_brief(root_only_tree, 0);
    }
    std::cout << std::endl; // 输出: 5

    return 0;
}