#include<iostream>
#include<fstream>

using namespace std;
const int N=4;


int main()
{
	int data[N][N] = { 0 };//定义一个矩阵，用于存放数据
	ifstream infile;//定义读取文件流，相对于程序来说是in
	infile.open("data.txt");//打开文件
	
	for (int i = 0; i < N; i++)// 行循环
	{
		for (int j = 0; j < N; j++)// 列循环
			infile >> data[i][j];//读取矩阵中元素
	}
	
	infile.close();//读取完成之后关闭文件
	
	for (int i = 0; i < N; i++)//行循环
	{
		for (int j = 0; j < N; j++)//列循环
			cout<<data[i][j]<<"\t";//输出矩阵元素
		cout<<endl;
	}
	
	system("pause");
	return 0;
}
