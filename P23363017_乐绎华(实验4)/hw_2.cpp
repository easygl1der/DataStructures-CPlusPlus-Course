#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 1.0;  // 最终结果需要乘2
    double term = 1.0;  // 当前项
    int i = 1;  // 项数计数器
    
    while (term >= 1e-6) {
        term *= (double)i / (2 * i + 1);  // 计算下一项
        pi += term;  // 累加到结果中
        i++;
    }
    
    pi *= 2;  // 最后乘以2得到π的值
    cout << fixed << setprecision(6);
    cout << "π ≈ " << pi << endl;
    
    return 0;
}
