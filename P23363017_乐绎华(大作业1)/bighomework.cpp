#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 3;  // 三门课程

struct Student {
    int num;           // 学号 
    string name;       // 姓名
    float score[N];    // 3门课 
    float ave;         // 3门课的平均分
    int rank;          // 排名
};

// 从文件读入学生数据
void ReadFromFile(Student *stu, int n) {
    ifstream inFile("bighomework/student.txt");
    if (!inFile) {
        cout << "无法打开文件！" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        inFile >> stu[i].num >> stu[i].name;
        for (int j = 0; j < N; j++) {
            inFile >> stu[i].score[j];
        }
    }
    inFile.close();
}

// 输入学生数据
void input(Student *stu, int n) {
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个学生的学号和姓名：";
        cin >> stu[i].num >> stu[i].name;
        cout << "请依次输入数学、语文、英语成绩：";
        for (int j = 0; j < N; j++) {
            cin >> stu[i].score[j];
        }
    }
}

// 输出学生数据
void print(Student *stu, int n) {
    cout << "\n学生成绩表：" << endl;
    cout << left << setw(10) << "学号" 
         << setw(15) << "姓名"
         << right << setw(14) << "数学" 
         << setw(10) << "语文"
         << setw(10) << "英语" 
         << setw(12) << "平均分"
         << setw(10) << "排名" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << stu[i].num 
             << setw(15) << stu[i].name
             << right;
        for (int j = 0; j < N; j++) {
            cout << setw(8) << stu[i].score[j];
        }
        cout << setw(10) << fixed << setprecision(2) << stu[i].ave
             << setw(8) << stu[i].rank << endl;
    }
}

// 计算每个学生的平均分
void average(Student *stu, int n) {
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            sum += stu[i].score[j];
        }
        stu[i].ave = sum / N;
    }
}

// 按平均成绩排序
void sort_average(Student *stu, int n) {
    // 先排序
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stu[j].ave < stu[j + 1].ave) {
                swap(stu[j], stu[j + 1]);
            }
        }
    }
    
    // 计算排名（考虑并列情况）
    stu[0].rank = 1;
    for (int i = 1; i < n; i++) {
        if (stu[i].ave == stu[i-1].ave) {
            stu[i].rank = stu[i-1].rank;
        } else {
            stu[i].rank = i + 1;
        }
    }
}

// 输出排名第一的学生
void top1(Student *stu, int n) {
    cout << "\n成绩最好的学生：" << endl;
    for (int i = 0; i < n && stu[i].rank == 1; i++) {
        cout << "学号：" << stu[i].num << " 姓名：" << stu[i].name 
             << " 数学：" << stu[i].score[0]
             << " 语文：" << stu[i].score[1]
             << " 英语：" << stu[i].score[2]
             << " 平均分：" << stu[i].ave
             << " 排名：" << stu[i].rank << endl;
    }
}

// 按姓名排序
void sort_name(Student *stu, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stu[j].name > stu[j + 1].name) {
                swap(stu[j], stu[j + 1]);
            }
        }
    }
}

// 输出不及格学生
void print_fail(Student *stu, int n) {
    cout << "\n不及格学生名单：" << endl;
    bool hasFailStudent = false;
    for (int i = 0; i < n; i++) {
        bool hasFail = false;
        for (int j = 0; j < N; j++) {
            if (stu[i].score[j] < 60) {
                hasFail = true;
                hasFailStudent = true;
                break;
            }
        }
        if (hasFail) {
            cout << "学号：" << stu[i].num << " 姓名：" << stu[i].name 
                 << " 数学：" << stu[i].score[0]
                 << " 语文：" << stu[i].score[1]
                 << " 英语：" << stu[i].score[2] << endl;
        }
    }
    if (!hasFailStudent) {
        cout << "没有不及格的学生！" << endl;
    }
}

// 找出数学最高分
void topmath(Student *stu, int n) {
    float maxMath = stu[0].score[0];
    for (int i = 1; i < n; i++) {
        if (stu[i].score[0] > maxMath) {
            maxMath = stu[i].score[0];
        }
    }
    cout << "\n数学最高分：" << maxMath << endl;
    cout << "获得最高分的学生：" << endl;
    for (int i = 0; i < n; i++) {
        if (stu[i].score[0] == maxMath) {
            cout << "学号：" << stu[i].num << " 姓名：" << stu[i].name << endl;
        }
    }
}

// 计算每门课的平均分
void score_average(Student *stu, float *avg, int n) {
    for (int j = 0; j < N; j++) {
        float sum = 0;
        for (int i = 0; i < n; i++) {
            sum += stu[i].score[j];
        }
        avg[j] = sum / n;
    }
}

// 输出每门课的平均分
void print_avg(float *avg, int n) {
    cout << "\n全班课程平均分：" << endl;
    cout << "数学：" << fixed << setprecision(2) << avg[0] << endl;
    cout << "语文：" << avg[1] << endl;
    cout << "英语：" << avg[2] << endl;
}

int main() {
    Student *stu;
    int n;
    float avg[N];    // 全班每门课的平均分
    
    cout << "请输入学生人数：";
    cin >> n;
    stu = new Student[n];    // 动态分配n个学生的存储空间
    
    ReadFromFile(stu, n);     // 从文件读入学生数据
    // input(stu, n);           // 输入n个学生数据
    
    average(stu, n);         // 求每个学生三门课的平均分
    sort_average(stu, n);    // 按平均成绩排序并计算排名
    cout << "\n按平均成绩排序后：" << endl;
    print(stu, n);
    
    top1(stu, n);           // 输出排名第一的学生
    
    sort_name(stu, n);      // 按姓名排序
    cout << "\n按姓名排序后：" << endl;
    print(stu, n);
    
    print_fail(stu, n);     // 输出不及格学生
    topmath(stu, n);        // 输出数学最高分
    
    score_average(stu, avg, n);  // 计算每门课平均分
    print_avg(avg, N);          // 输出每门课平均分
    
    delete []stu;           // 释放内存
    return 0;
}
