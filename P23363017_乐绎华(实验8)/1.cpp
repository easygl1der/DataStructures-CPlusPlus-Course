#include <iostream>
#include <cstring>        // ??C++????????
using namespace std;

class Teacher                                // ???
{
public:
    Teacher(int, const char[], char);               // ??????
    void display();                          // ??????
private:
    int num;
    char name[20];
    char sex;
};

Teacher::Teacher(int n, const char* nam, char s)    // ??????
{
    num = n;
    strcpy_s(name, nam);
    sex = s;
}

void Teacher::display()                      // ??????
{
    cout << "?????" << num << endl;
    cout << "?????" << name << endl;
    cout << "?????" << sex << endl;
}

class BirthDate                               // ???
{
public:
    BirthDate(int, int, int);                   // ??????
    void display();                           // ??????
    void change(int, int, int);                 // ??????
private:
    int year;
    int month;
    int day;
};

BirthDate::BirthDate(int y, int m, int d)       // ??????
{
    year = y;
    month = m;
    day = d;
}

void BirthDate::display()                     // ??????
{
    cout << "??:" << year << "_" << month << "_" << day << endl;
}

void BirthDate::change(int y, int m, int d)     // ??????
{
    year = y;
    month = m;
    day = d;
}

class Professor :public Teacher                         // ???
{
public:
    Professor(int n, const char* nam, char s, int y, int m, int d, double a);    // ??????
    void display();                                   // ??????
    void change(int y, int m, int d);                         // ??????
private:
    double area;
    BirthDate birthday;                               // ??BirthDate??????????
};

Professor::Professor(int n, const char nam[20], char s, int y, int m, int d, double a):
    Teacher(n,nam,s),birthday(y,m,d),area(a){}
// ??????

void Professor::display()                             // ??????
{
    Teacher::display();
    birthday.display();
    cout << "??????:" << area << endl;
}

void Professor::change(int y, int m, int d)             // ??????
{
    birthday.change(y, m, d);
}

int main()
{
    Professor prof1(3012, "Zhang", 'f', 1949, 10, 1, 125.4);   // ??Professor??prof1
    cout << endl << "????:" << endl;
    prof1.display();                     // ??prof1???display??
    cout << endl << "???:" << endl;
    prof1.change(1950, 11, 2);       // ??prof1???change??
    prof1.display();                                  // ??prof1???display??
    return 0;
};
