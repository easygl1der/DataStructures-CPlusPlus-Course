/******************************* 
   对应教材6.5.2节，Floyd算法 
********************************/
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MaxSize = 10;                   //图中最多顶点个数
template <class DataType>
class MGraph
{
public:
   	MGraph(DataType a[ ], int n, int e);     //构造函数，建立具有n个顶点e条边的图
   	~MGraph( ){ };                        //析构函数
	void Floyd( );
private:
	DataType vertex[MaxSize];           //存放图中顶点的数组
    int edge[MaxSize][MaxSize];           //存放图中边的数组
    int vertexNum, edgeNum;              //图的顶点数和边数
 };
  
template <class DataType>
MGraph<DataType> :: MGraph(DataType a[ ], int n, int e) 
{
   	int i, j, k, w;
   	vertexNum = n; edgeNum = e;
   	for (i = 0; i < vertexNum; i++)          //存储顶点
   		vertex[i] = a[i];
   	for (i = 0; i < vertexNum; i++)          //初始化邻接矩阵
 		for (j = 0; j < vertexNum; j++)
   			if (i == j)
			   	edge[i][j] = 0;             
			else
			 	edge[i][j] = 1000;            //假设边上权值最大是1000 
   	for (k = 0; k < edgeNum; k++)           //依次输入每一条边
   	{
   		cout << "请输入边依附的两个顶点的编号，以及边上的权值：";
		cin >> i >> j >> w;                       //输入边依附的两个顶点的编号
		edge[i][j] = w;                           //置有边标志
   	}
}

template <class DataType>
void MGraph<DataType> :: Floyd( )
{
	int i, j, k, dist[MaxSize][MaxSize];
	string path[MaxSize][MaxSize];
	for (i = 0; i < vertexNum; i++)              //初始化矩阵dist和path
	  	for (j = 0; j < vertexNum; j++)
	  	{
	    	dist[i][j] = edge[i][j];
	     	if (dist[i][j] != 1000)                 //假设100为边上权的最大值
	       		path[i][j] = vertex[i] + vertex[j];     //+为字符串连接操作
	     	else path[i][j] = "";
	    }
	    //输出初始值
		cout<<"输出初始值"<<endl;
    for (i = 0; i < vertexNum; i++)
	{       
	    for (j = 0; j < vertexNum; j++)
	        cout <<setw(5)<< path[i][j] << ":" <<setw(5)<< dist[i][j] ;
	    cout << endl;
	} 
	for (k = 0; k < vertexNum; k++)                //进行n次迭代
	{
		for (i = 0; i < vertexNum; i++)       
	    	for (j = 0; j < vertexNum; j++)
	        	if (dist[i][k] + dist[k][j] < dist[i][j]) {
	          		dist[i][j] = dist[i][k] + dist[k][j];
	          		path[i][j] = path[i][k] + path[k][j][1];    //+为字符串连接操作
       			}
    cout<<endl<<"加入点 "<<k<<" 的结果"<<endl;
    for (i = 0; i < vertexNum; i++)
	{       
	    for (j = 0; j < vertexNum; j++)
	        cout <<setw(5)<<  path[i][j] << ":" <<setw(5)<< dist[i][j] ;
	    cout << endl;
	}
   }
}

int main( )
{
	int i;
	string ch[ ]={"A","B","C"};       
	/* 测试数据使用 图6-24，输入边五条边是：
	(0 1 4)(0 2 11)(1 0 6)(1 2 2)(2 0 3)  */  
	//0 1 4 0 2 11 1 0 6 1 2 2 2 0 3
	MGraph<string> MG(ch, 3, 5);              //建立具有5个顶点6条边的无向图
	MG.Floyd( );
	return 0;
}
