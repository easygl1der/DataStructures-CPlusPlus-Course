/************************************************ 
   对应教材6.3.2节，邻接表类ALGraph的使用范例 
*************************************************/
#include <iostream>
using namespace std;

struct EdgeNode       //定义边表结点
{
  int adjvex;         //邻接点域
  EdgeNode *next;
};

template <class DataType>
struct VertexNode     //定义顶点表结点
{
  DataType vertex;
  EdgeNode *firstEdge;
};

const int MaxSize = 10;                  //图的最多顶点数
int visited[MaxSize] = {0};
template <class DataType>
class ALGraph
{
public:
	ALGraph(DataType a[ ], int n, int e);   //构造函数，建立n个顶点e条边的图
   	~ALGraph( );                            //析构函数，释放邻接表各边表结点的存储空间
   	void DFTraverse(int v);                 //深度优先遍历图
   	void BFTraverse(int v);                 //广度优先遍历图
private:
   	VertexNode<DataType> adjlist[MaxSize];          //存放顶点表的数组
   	int vertexNum, edgeNum;                       //图的顶点数和边数
};

template <class DataType>
ALGraph<DataType> :: ALGraph(DataType a[ ], int n, int e)
{
	int i, j, k;
	EdgeNode *s = NULL;
	vertexNum = n; edgeNum = e;
	for (i = 0; i < vertexNum; i++)     //输入顶点信息，初始化顶点表
	{ 
		adjlist[i].vertex = a[i];
	 	adjlist[i].firstEdge = NULL;      
	}
	for (k = 0; k < edgeNum; k++)      //依次输入每一条边
	{ 
		cout << "输入边所依附的两个顶点的编号：";
	   	cin >> i >> j;                     //输入边所依附的两个顶点的编号
	   	s = new EdgeNode; s->adjvex = j;  //生成一个边表结点s
	   	s->next = adjlist[i].firstEdge;   //将结点s插入到第i个边表的表头
	   	adjlist[i].firstEdge = s;
	}
}

template <class DataType>
ALGraph<DataType> :: ~ALGraph( )
{
	EdgeNode *p = NULL, *q = NULL;
  	for (int i = 0; i < vertexNum; i++)
  	{
  		p = q = adjlist[i].firstEdge;
	  	while (p != NULL)
	  	{
	  		p = p->next;
	  		delete q; 
			q = p;
	  	}
  	}
}

template <class DataType>
void ALGraph<DataType> :: DFTraverse(int v)
{
	int j;
	EdgeNode *p = NULL;
	cout << v<<adjlist[v].vertex<<" ";  visited[v] = 1;
	p = adjlist[v].firstEdge;             //工作指针p指向顶点v的边表
	while (p != NULL)                        //依次搜索顶点v的邻接点
	{
		j = p->adjvex;
	  	if (visited[j] == 0) DFTraverse(j);
	  	p = p->next;           
	}
}

template <class DataType>
void ALGraph<DataType> :: BFTraverse(int v) 
{
	int w, j, Q[MaxSize];                     //采用顺序队列
   	int front = -1, rear = -1;               //初始化队列
   	EdgeNode *p = NULL;
   	cout <<v<<adjlist[v].vertex<<" "; visited[v] = 1; Q[++rear] = v;   //被访问顶点入队
   	while (front != rear)                 //当队列非空时
   	{
    	w = Q[++front];
     	p = adjlist[w].firstEdge;         //工作指针p指向顶点v的边表
    	while (p != NULL) 
    	{
       		j = p->adjvex;
       		if (visited[j] == 0) {
         		cout <<j<<adjlist[j].vertex<<" "; visited[j] = 1;Q[++rear] = j;
       		}
       		p = p->next;
    	}
   	}
}

int main( )
{
	//测试数据是图6-20(a)，边是(0 1)(0 3)(0 4)(1 2)(2 4)(3 2)(3 4)
	//输入：0 1 0 3 0 4 1 2 2 4 3 2 3 4 
	char ch[ ] = {'A','B','C','D','E'};
	int i;
	ALGraph<char> ALG(ch, 5, 7);               //建立具有5个顶点6条边的有向图
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout <<endl<< "深度优先遍历序列是：";
	ALG.DFTraverse(0);                       //从顶点0出发进行深度优先遍历
	for (i = 0; i < MaxSize; i++)
		visited[i] = 0;
	cout <<endl<< "广度优先遍历序列是："; 
	ALG.BFTraverse(0);                      //从顶点0出发进行广度优先遍历
	return 0;
}
