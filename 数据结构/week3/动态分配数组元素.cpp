#include <iostream>     // 包含输入输出流库
using namespace std; 
#include <stdlib.h>     // 包含标准库函数，如随机数生成
#include <time.h>       // 包含时间相关函数，用于随机数种子
#define endl '\n'       // 定义换行符

// 函数声明
void print(int r[ ], int n);    // 打印数组元素的函数
void create(int r[ ], int n);   // 创建随机数组的函数

// 定义Array类，用于动态管理整型数组
class Array
{ public:
	Array(){ data=NULL;length=0;  // 默认构造函数，初始化为空数组
	}
	Array(int *a, int n);         // 带参构造函数，从已有数组创建
	~Array(){                      // 析构函数，释放动态分配的内存
	 cout<<"Destructor"<<endl;    // 输出析构信息
	 delete []data;               // 释放动态数组内存
	}
   void show_value();             // 显示数组元素的方法
  private:
   int *data;                     // 指向动态分配的整型数组
   int length;                    // 数组长度
};

// Array类的带参构造函数实现
Array::Array(int *a, int n)
{ int i;
  data=new int[n];               // 动态分配n个整型的内存空间
  length=n;                      // 设置数组长度
  for (i=0;i<n;i++)              // 复制数组元素
   *(data+i)=*(a+i);             // 使用指针算术复制元素
}

// 显示数组元素的方法实现
void Array::show_value()
{  int i;
   for (i=0;i<length;i++)        // 遍历数组
   cout<<*(data+i)<<",";         // 输出每个元素，用逗号分隔
}

// 主函数
int main()
{ 
   int n;    //int a[10];         // 声明变量n，注释掉的是固定大小数组
   cin>>n;                        // 从用户输入获取数组大小
   int *a=NULL;                   // 声明整型指针并初始化为NULL
   //记住要初始化为空指针，避免动太分配空间时的问题 
   a=new int[n];                  // 动态分配n个整型的内存空间
   create(a,n);                   // 调用函数创建随机数组
   print(a,n);                    // 打印数组元素
   
   
   
  // Array arr(a,n),arr1,arr2,arr3;  // 注释掉的代码：创建Array对象
  // arr.show_value();                // 注释掉的代码：显示数组元素
   //arr1=arr;                        // 注释掉的代码：对象赋值
   delete []a;                        // 释放动态分配的内存
  return 0;                           // 程序正常结束
}

// 创建随机数组的函数实现
void create(int *r, int n)
{
	int i = 0;
	srand(time(NULL));              // 初始化随机数生成器
	for (i = 0; i < n; i++)         // 遍历数组
		//r[i] = 1 + rand() % 100;  // 注释掉的是使用数组下标语法
		*(r+i) =1+ rand() % 100;    // 使用指针算术生成1到100的随机数
}

// 打印数组元素的函数实现
void print(int *r, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)         // 遍历数组
	//	cout<<r[i]<<"  ";          // 注释掉的是使用数组下标语法
	cout<<*(r+i)<<"  ";             // 使用指针算术输出数组元素
}
