#include <iostream>
using namespace std;
#include "ALGraph.cpp"
int visited[MaxSize] = {0};

int main()
{
	char ch[ ]={'A','B','C','D','E'};
	int i;
	//测试数据是图6-20(a)，边是(0 1)(0 3)(0 4)(1 2)(2 4)(3 2)(3 4)
	//输入：0 1 0 3 0 4 1 2 2 4 3 2 3 4 
	ALGraph<char> ALG(ch, 5, 6);
	cout<<"输出邻接表"<<endl;
	ALG.printALG() ;
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout<<"深度优先遍历序列是：";
	ALG.DFSTraverse(0);
	cout<<endl;
    for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout<<"广度优先遍历序列是：";
	ALG.BFSTraverse(0);
	cout<<endl;
	return 0;
} 
