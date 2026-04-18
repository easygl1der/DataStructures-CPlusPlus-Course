/************************************************ 
   对应教材6.3.1节，邻接矩阵类MGraph的使用范例 
*************************************************/
#include <iostream>
#include <string>
using namespace std;

const int MaxSize = 10;                   //图中最多顶点个数
int visited[MaxSize] = {0};              //全局数组变量visited初始化
template <class DataType>
class MGraph
{
public:
   MGraph(DataType a[ ], int n, int e);     //构造函数，建立具有n个顶点e条边的图
   ~MGraph( ){    };                        //析构函数
   void DFTraverse(int v);               //递归深度优先遍历图
   void DFTraverse1(int v);               //非递归深度优先遍历图
   void BFTraverse(int v);               //广度优先遍历图
private:
    DataType vertex[MaxSize];           //存放图中顶点的数组
    int edge[MaxSize][MaxSize];           //存放图中边的数组
    int vertexNum, edgeNum;              //图的顶点数和边数
 };
  
template <class DataType>
MGraph<DataType> :: MGraph(DataType a[ ], int n, int e) 
{
   	int i, j, k;
   	vertexNum = n; edgeNum = e;
   	for (i = 0; i < vertexNum; i++)          //存储顶点
   		vertex[i] = a[i];
   	for (i = 0; i < vertexNum; i++)          //初始化邻接矩阵
 		for (j = 0; j < vertexNum; j++)
   			edge[i][j] = 0;             
   	for (k = 0; k < edgeNum; k++)           //依次输入每一条边
   	{
   		cout << "请输入边依附的两个顶点的编号：";
		cin >> i >> j;                       //输入边依附的两个顶点的编号
		edge[i][j] = 1; edge[j][i] = 1;           //置有边标志
   	}
}

template <class DataType>
void MGraph<DataType> :: DFTraverse(int v)  
{
	cout <<v<<vertex[v]<<" "; visited[v] = 1;
	for (int j = 0; j < vertexNum; j++)
		if (edge[v][j] == 1 && visited[j] == 0) DFTraverse( j );
}


template <typename DataType> 
void MGraph<DataType> :: DFTraverse1(int v) 
{
	
	int S[100];       //顺序栈，最多100个结点指针
	int top = -1,j;                     //采用顺序栈并假设不会发生溢出
	cout <<v<<vertex[v]<<" "; visited[v] = 1; S[++top]=v;
	while (top != -1)      
	{   v=S[top];
    	for (j = 0; j < vertexNum; j++)
	    	if (edge[v][j] == 1 && visited[j] == 0) 
	    	{
	    	  cout <<j<<vertex[j]<<" "; visited[j] = 1; S[++top]=j;
			  break;	
			}
	    if (j==vertexNum)  top--;
	}
}

template <class DataType>
void MGraph<DataType> :: BFTraverse(int v) 
{
	int w, j, Q[MaxSize];                   //采用顺序队列
	int front = -1, rear = -1;                 //初始化队列
 	cout <<v<<vertex[v]<<" "; visited[v] = 1; Q[++rear] = v;   //被访问顶点入队
 	while (front != rear)                    //当队列非空时
 	{
	   	w = Q[++front];                    //将队头元素出队并送到v中
   	 	for (j = 0; j < vertexNum; j++)
       	if (edge[w][j] == 1 && visited[j] == 0 ) {
        	cout <<j<<vertex[j]<<" "; visited[j] = 1; Q[++rear] = j;
       	}
    }
}

int main( )
{
	int i;
	string ch[ ]={"A就经济","Bd dfg ","Cdsfdsf","Ddsfdsfsa","Edsfds","和和F"};       
	/* 测试数据图6-7六条边是：(0 1)(0 2)(0 5)(1 2)(1 4)(2 3)  */  
	//输入时的数据：0 1 0 2 0 5 1 2 1 4 2 3 
	MGraph<string> MG(ch, 6, 6);              //建立具有6个顶点6条边的无向图
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout <<endl<< "递归深度优先遍历序列是：" ;
	MG.DFTraverse(0);                     //从顶点0出发进行深度优先遍历
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout <<endl<< "非递归深度优先遍历序列是：" ;
	MG.DFTraverse1(0);                     //从顶点0出发进行深度优先遍历
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
    cout <<endl<< "广度优先遍历序列是：" ;
	MG.BFTraverse(0);                     //从顶点0出发进行广度优先遍历
	return 0;
}
 

