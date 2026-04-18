#include <iostream>
using namespace std;

int main() {
    int ascii;
    char character;

    cout << "请输入一个ASCII码整数 (65-90 或 97-122): ";
    cin >> ascii;
    if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
        cout << "对应的字符是: " << char(ascii) << endl;
    } else {
        cout << "输入的ASCII码不在指定范围内。" << endl;
    }

    cout << "请输入一个字符: ";
    cin >> character;
    cout << "该字符的ASCII码是: " << int(character) << endl;

    return 0;
}
