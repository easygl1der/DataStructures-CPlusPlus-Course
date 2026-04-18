#include <iostream>
using namespace std;

int main() {
    int num, positiveCount = 0, negativeCount = 0;
    
    cout << "请输入多个数字（输入0结束）：" << endl;
    
    while (true) {
        cout << "请输入一个整数：";
        cin >> num;
        
        if (num == 0) {
            break;
        } else if (num > 0) {
            positiveCount++;
        } else {
            negativeCount++;
        }
    }
    
    cout << "正数个数：" << positiveCount << endl;
    cout << "负数个数：" << negativeCount << endl;
    
    return 0;
}
