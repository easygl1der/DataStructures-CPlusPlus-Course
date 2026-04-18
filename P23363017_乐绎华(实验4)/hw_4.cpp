#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

// 计算阶乘
double factorial(int n) {
    double result = 1.0;
    for(int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 计算sin(x)的近似值
double mySin(double x) {
    double sum = 0;
    for(int k = 0; k < 10; k++) { // 取前10项
        sum += pow(-1, k) * pow(x, 2*k+1) / factorial(2*k+1);
    }
    return sum;
}

// 计算cos(x)的近似值 
double myCos(double x) {
    double sum = 0;
    for(int k = 0; k < 10; k++) { // 取前10项
        sum += pow(-1, k) * pow(x, 2*k) / factorial(2*k);
    }
    return sum;
}

int main() {
    cout << fixed << setprecision(6);
    
    cout << "我的sin函数计算结果:" << endl;
    cout << "sin(PI/6) = " << mySin(PI/6) << endl;
    cout << "sin(PI/4) = " << mySin(PI/4) << endl; 
    cout << "sin(PI/3) = " << mySin(PI/3) << endl;
    cout << "sin(PI/2) = " << mySin(PI/2) << endl;
    cout << "sin(2*PI/3) = " << mySin(2*PI/3) << endl;
    cout << "sin(2*PI) = " << mySin(2*PI) << endl;
    
    cout << "\n系统sin函数计算结果:" << endl;
    cout << "sin(PI/6) = " << sin(PI/6) << endl;
    cout << "sin(PI/4) = " << sin(PI/4) << endl;
    cout << "sin(PI/3) = " << sin(PI/3) << endl;
    cout << "sin(PI/2) = " << sin(PI/2) << endl;
    cout << "sin(2*PI/3) = " << sin(2*PI/3) << endl;
    cout << "sin(2*PI) = " << sin(2*PI) << endl;
    
    cout << "\n按任意键继续..." << endl;
    
    return 0;
}
