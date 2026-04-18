/********************************** 
   对应教材6.5.1节，Dijkstra算法 
***********************************/
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
	void Dijkstra(int v);
private:
    int Min(int r[ ], int n);
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
void MGraph<DataType> :: Dijkstra(int v)                      //从源点v出发
{
  	int i, k, num, dist[MaxSize];
  	string path[MaxSize];
	for (i = 0; i < vertexNum; i++)            //初始化数组dist和path
	{
   		dist[i] = edge[v][i];
   		if (dist[i] != 1000)                    //假设1000为边上权的最大值
			path[i] = vertex[v] + vertex[i];       //+为字符串连接操作
   		else path[i] = "";
   	}
   	cout<<endl; 
	for (num = 1; num < vertexNum; num++)
	{ 
	   for (i = 0; i < vertexNum; i++) 
		  cout<<setw(5)<<dist[i];
		  cout<<endl; 
		for (i = 0; i < vertexNum; i++) 
		  cout<<setw(5)<<path[i];
		  cout<<endl; 
	
		k = Min(dist, vertexNum);      //在dist数组中找最小值并返回其下标
  		cout << setw(5)<<path[k] <<":" <<setw(5)<< dist[k] << endl;
  		for (i = 0; i < vertexNum; i++)             //修改数组dist和path
    		if (dist[i] > dist[k] + edge[k][i]) {
       			dist[i] = dist[k] + edge[k][i];
       			path[i] = path[k] + vertex[i];         //+为字符串连接操作
    		}
		dist[k] = 0;                            //将顶点k加到集合S中
		
		
	}
}

template <class DataType>
int MGraph<DataType> ::Min(int r[ ], int n)
{
	int index = 0, min = 1000;
	for (int i = 0; i < n; i++)
		if (r[i] != 0 && r[i] < min)
		{
			min = r[i]; index = i;		
		}
	return index;
}

int main( )
{
	int i;
	string ch[ ]={"A","B","C","D","E"};       
	/* 测试数据使用 图6-20(b)，输入边七条边是：
	(0 1 10)(0 4 100)(0 3 30)(1 2 50)(2 4 10)(3 2 20)(3 4 60)  */ 
	// 0 1 10 0 4 100 0 3 30 1 2 50 2 4 10 3 2 20 3 4 60
	MGraph<string> MG(ch, 5, 7);              //建立具有5个顶点6条边的无向图
	MG.Dijkstra(0);
	return 0;
}
