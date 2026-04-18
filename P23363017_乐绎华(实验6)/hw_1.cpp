#include <iostream>
using namespace std;

void exchange(int &x, int &y, int &z) {
    // 临时变量用于交换
    int temp;
    // 比较并交换,确保 x >= y >= z
    if (x < y) {
        temp = x;
        x = y;
        y = temp;
    }
    if (x < z) {
        temp = x;
        x = z;
        z = temp;
    }
    if (y < z) {
        temp = y;
        y = z;
        z = temp;
    }
}

int main() {
    int a, b, c;
    cout << "请输入三个整数:" << endl;
    cin >> a >> b >> c;
    
    exchange(a, b, c);
    
    cout << "从大到小排序结果:" << endl;
    cout << a << " " << b << " " << c << endl;
    
    return 0;
}
