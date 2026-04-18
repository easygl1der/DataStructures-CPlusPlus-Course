// // 找到数组A[n]中最大和次大的元素
// #include <algorithm> // 为了使用std::max和std::min函数

// // 找到数组中最大和次大的元素
// void Max_NextMax(int A[], int n, int &max1, int &max2) {
//     if (n < 2) {
//         // 处理数组元素不足两个的情况
//         if (n == 1) {
//             max1 = A[0];
//             max2 = A[0]; // 或者设置为某个特定值表示没有次大元素
//         }
//         return;
//     }
    
//     // 初始化max1和max2
//     max1 = std::max(A[0], A[1]);
//     max2 = std::min(A[0], A[1]);
    
//     // 遍历数组找出最大和次大元素
//     for (int i = 2; i < n; i++) {
//         if (A[i] > max1) {
//             max2 = max1;
//             max1 = A[i];
//         } else if (A[i] > max2) {
//             max2 = A[i];
//         }
//     }
// }

// 设计算法将数组A[n]中的奇数放在左边，偶数放在右边
void SeparateOddEven(int A[], int n) {
    // 创建临时数组存储奇数和偶数
    int* B = new int[n]; // 存储奇数
    int* C = new int[n]; // 存储偶数
    
    int j = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 1) // 奇数放入B数组
            B[j++] = A[i];
        else // 偶数放入C数组
            C[k++] = A[i];
    }
    
    // 将奇数复制回原数组的左边
    for (int i = 0; i < j; i++)
        A[i] = B[i];
    
    // 将偶数复制回原数组的右边
    for (int i = j; i < n; i++)
        A[i] = C[i-j];
    
    // 释放临时数组
    delete[] B;
    delete[] C;
}













