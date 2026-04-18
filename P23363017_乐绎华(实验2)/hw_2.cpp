#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const double PI = 3.14159;
    double r, h;

    cout << "请输入圆的半径: ";
    cin >> r;
    cout << "请输入圆柱的高: ";
    cin >> h;

    // 计算各种结果
    double circumference = 2 * PI * r;
    double circleArea = PI * r * r;
    double sphereSurfaceArea = 4 * PI * r * r;
    double sphereVolume = (4.0 / 3.0) * PI * pow(r, 3);
    double cylinderVolume = PI * r * r * h;

    // 输出结果
    cout << "圆周长: " << circumference << endl;
    cout << "圆面积: " << circleArea << endl;
    cout << "圆球表面积: " << sphereSurfaceArea << endl;
    cout << "圆球体积: " << sphereVolume << endl;
    cout << "圆柱体积: " << cylinderVolume << endl;

    return 0;
}
