#include <iostream>
#include <cmath>

double f(double x) {
    if (x < 1) {
        return 2.5 * x * x;
    } else if (x < 2) {
        return (4.0 * x / 9.0) * log2(x);
    } else {
        return 2 * x * sqrt(3 * x);
    }
}

int main() {
    double x;
    std::cout << "请输入 x 的值: ";
    std::cin >> x;
    
    double y = f(x);
    std::cout << "f(" << x << ") = " << y << std::endl;
    
    return 0;
}

