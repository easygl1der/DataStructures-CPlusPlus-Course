#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double fahrenheit, celsius;
    
    cout << "请输入华氏温度: ";
    cin >> fahrenheit;
    
    celsius = 5.0 / 9.0 * (fahrenheit - 32);
    
    cout << "摄氏度等于 " << fixed << setprecision(2) << celsius << endl;
    
    return 0;
}


