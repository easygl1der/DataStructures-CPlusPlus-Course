#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string &encrypt(string &str1, string &str2) {
    int n = str1.size();
    int i = 0;
    
    // 处理第一个字符
    if (n > 0) {
        if (isalpha(str1[0])) {
            char c = str1[0];
            if (isupper(c)) {
                str2 += (c - 'A' + 4) % 26 + 'A';
            } else {
                str2 += (c - 'a' + 4) % 26 + 'a';
            }
        } else {
            str2 += str1[0];
        }
        i = 1;
    }
    
    // 处理剩余字符
    while (i < n) {
        str2 += ' '; // 插入空格
        if (isalpha(str1[i])) {
            char c = str1[i];
            if (isupper(c)) {
                str2 += (c - 'A' + 4) % 26 + 'A';
            } else {
                str2 += (c - 'a' + 4) % 26 + 'a';
            }
        } else {
            str2 += str1[i];
        }
        i++;
    }
    
    return str2;
}

int main() {
    string str1, str2;
    
    cout << "请输入明文: ";
    getline(cin, str1);
    
    str2 = encrypt(str1, str2);
    cout << "加密后的密文: " << str2 << endl;
    
    return 0;
}
