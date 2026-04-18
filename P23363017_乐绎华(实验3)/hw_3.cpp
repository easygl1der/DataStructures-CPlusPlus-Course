#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num;
    cout << "请输入一个3位数: ";
    cin >> num;

    if (num < 100 || num > 999) {
        cout << "输入错误，请输入一个3位数。" << endl;
        return 1;
    }

    int a = num / 100;        // 百位
    int b = (num / 10) % 10;  // 十位
    int c = num % 10;         // 个位

    int sum = pow(a, 3) + pow(b, 3) + pow(c, 3);

    if (sum == num) {
        cout << num << " 是水仙花数。" << endl;
    } else {
        cout << num << " 不是水仙花数。" << endl;
    }

    return 0;
}
