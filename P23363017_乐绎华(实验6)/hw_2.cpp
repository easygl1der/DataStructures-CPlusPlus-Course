#include <iostream>
using namespace std;

void input(int *p, int n) {
    cout << "请输入" << n << "个整数:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
}

void sort(int *p, int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(p[j] > p[j+1]) {
                int temp = p[j];
                p[j] = p[j+1]; 
                p[j+1] = temp;
            }
        }
    }
}

void print(int *p, int n) {
    cout << "排序后的结果:" << endl;
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "请输入要排序的整数个数:" << endl;
    cin >> n;
    
    int *p = new int[n];
    
    input(p, n);
    sort(p, n);
    print(p, n);
    
    delete[] p;
    return 0;
}
