#include <iostream>
using namespace std;
#include "MGraph.cpp"                                         //引用graph.cpp文件
int visited[MaxSize]={0};

int main( )
{  /* 测试数据图6-7六条边是：(0 1)(0 2)(0 5)(1 2)(1 4)(2 3)  */  
	//输入时的数据：0 1 0 2 0 5 1 2 1 4 2 3 
	char ch[]={'A','B','C','D','E','F'};
	MGraph<char> MG(ch, 6, 6);
	cout<<"输出邻接矩阵"<<endl; 
	MG.printMG();
	for (int i=0; i<MaxSize; i++)
		visited[i]=0;
	cout<<"深度优先遍历序列是：";
	MG.DFSTraverse(0);
	cout<<endl;
	for (int i=0; i<MaxSize; i++)
		visited[i]=0;
    cout<<"广度优先遍历序列是：";
	MG.BFSTraverse(0);
	cout<<endl;
    return 0;
}
