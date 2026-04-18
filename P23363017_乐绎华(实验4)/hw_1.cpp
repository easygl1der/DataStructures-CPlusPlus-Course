#include <iostream>
using namespace std;

int main() {
    cout << "百钱买百鸡问题的所有解:" << endl;
    cout << "公鸡\t母鸡\t小鸡" << endl;
    
    // x:公鸡数量 y:母鸡数量 z:小鸡数量
    for(int x = 0; x <= 20; x++) {  // 公鸡最多20只(5*20=100)
        for(int y = 0; y <= 33; y++) {  // 母鸡最多33只(3*33=99)
            int z = 100 - x - y;  // 总数需要为100只
            if(z % 3 == 0 && z >= 0) {  // 小鸡数量必须是3的倍数
                if(5*x + 3*y + z/3 == 100) {  // 总价为100钱
                    cout << x << "\t" << y << "\t" << z << endl;
                }
            }
        }
    }
    return 0;
}
