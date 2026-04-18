#include <iostream> //预处理命令
using namespace std;
int min(int x, int y) // 定义max函数,函数值为整型,形式参数x,y为整型
{                     // max函数体开始
    int z;            // 变量声明,定义本函数中用到的变量z为整型
    if (x < y)
        z = x; // if语句,如果x>y,则将x的值赋给z
    else
        z = y;  // 否则,将y的值赋给z
    return (z); // 将z的值返回,通过max带回调用处
} // max函数结束

int min_of_3_numbers(int x, int y, int z)
{
    int w;
    w = min(x, y);
    w = min(w, z);
    return (w);
}

int main()                         // 主函数
{                                  // 主函数体开始
    int a, b, c, m;                // 变量声明
    cin >> a >> b >> c;            // 输入变量a和b和c的值
    m = min_of_3_numbers(a, b, c); // 调用max函数,将得到的值赋给m
    cout << "min = " << m << '\n'; // 输出大数m的值
    return 0;                      // 如程序正常结束,向操作系统返回一个零值
} // 主函数结束