#include <iostream>
#include <cmath>
using namespace std;

// 计算平方根的函数
double mysqrt(double x) {
    if (x < 0) return -1;  // 负数无实数平方根
    if (x == 0) return 0;
    
    double x0 = x;  // 初始值
    double x1 = (x0 + x/x0) / 2.0;
    
    // 当两次迭代结果非常接近时停止
    while (fabs(x1 - x0) > 1e-10) {
        x0 = x1;
        x1 = (x0 + x/x0) / 2.0;
    }
    
    return x1;
}

int main() {
    // 测试mysqrt函数
    cout << "2的平方根=" << mysqrt(2) << endl;
    
    // 测试一元二次方程求根
    // 例1：两个不同实根
    double a1 = 1, b1 = 3, c1 = 1;
    cout << "方程: x^2+" << b1 << "x+" << c1 << "=0的根如下" << endl;
    double delta1 = b1*b1 - 4*a1*c1;
    if (delta1 > 0) {
        double sqrt_delta = mysqrt(delta1);
        double root1 = (-b1 + sqrt_delta)/(2*a1);
        double root2 = (-b1 - sqrt_delta)/(2*a1);
        cout << "Root1:" << root1 << " root2:" << root2 << endl;
    }
    
    cout << endl;
    
    // 例2：两个相同实根
    double a2 = 1, b2 = 2, c2 = 1;
    cout << "方程: x^2+" << b2 << "x+" << c2 << "=0的根如下" << endl;
    double delta2 = b2*b2 - 4*a2*c2;
    if (fabs(delta2) < 1e-10) {
        double root = -b2/(2*a2);
        cout << "Root1:" << root << " root2:" << root << endl;
    }
    
    cout << "\n按任意键关闭此窗口..." << endl;
    
    return 0;
}

