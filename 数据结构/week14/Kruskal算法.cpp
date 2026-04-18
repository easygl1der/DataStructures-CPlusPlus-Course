/********************************** 
   对应教材6.4.2节，Kruskal算法 
***********************************/
#include <iostream>
#define endl '\n' 

using namespace std;

struct EdgeType                              //定义边集数组的元素类型
{
  int from, to, weight;                  //假设权值为整数
};

const int MaxVertex = 10;                //图中最多顶点数
const int MaxEdge = 100;                //图中最多边数
template <typename DataType>           //定义模板类
class EdgeGraph                              
{
public:
  	EdgeGraph(DataType a[ ], int n, int e);   //构造函数，生成n个顶点e条边的连通图
	~EdgeGraph( );                      //析构函数
	void Kruskal( );                      //Kruskal算法求最小生成树
private:
	int FindRoot(int parent[ ], int v);         //求顶点v所在集合的根
	
	DataType vertex[MaxVertex];          //存储顶点的一维数组
  	EdgeType edge[MaxEdge];            //存储边的边集数组
	int vertexNum, edgeNum;        
};

template <typename DataType>
EdgeGraph<DataType> :: EdgeGraph(DataType a[ ], int n, int e)
{
	int i, j, k, w;
	vertexNum = n; edgeNum = e;
	for (i = 0; i < vertexNum; i++)
		vertex[i] = a[i];
	for (k = 0; k < edgeNum; k++)
	{
		cout << "请输入边依附的两个顶点的编号，以及边上的权值：";
		cin >> i >> j >> w;                       //输入边依附的两个顶点的编号
		edge[k].from = i; edge[k].to = j; edge[k].weight = w;
	}
}

template <typename DataType>
EdgeGraph<DataType> :: ~EdgeGraph( )
{
	
}

template <typename DataType>
void EdgeGraph<DataType> :: Kruskal( )
{
	int num = 0, i, vex1, vex2;
	int parent[vertexNum];                        //双亲表示法存储并查集
	for (i = 0; i < vertexNum; i++)
  		parent[i] = -1;                             //初始化n个连通分量
	for (num = 0, i = 0; num < vertexNum-1 ; i++)    //依次考察最短边
	{
  		vex1 = FindRoot(parent, edge[i].from);
  		vex2 = FindRoot(parent, edge[i].to);
  		if (vex1 != vex2) {                         //位于不同的集合
    		cout << "(" << edge[i].from << "," << edge[i].to << ")" << edge[i].weight << endl;
			parent[vex2] = vex1;                      //合并集合
    		num++;
		}
	}
}

template <typename DataType>
int EdgeGraph<DataType> :: FindRoot(int parent[ ], int v)           //求顶点v所在集合的根
{
	int t = v;
	while (parent[t] > -1)                 //求顶点t的双亲一直到根
		t = parent[t];          
	return t;
}

int main( )
{
	/* 测试数据使用教材 图6-18 所示带权无向图，输入边依次为 
	(1 4 12)(2 3 17)(0 5 19) (2 5 25)(3 5 25)(4 5 26)(0 1 34)(3 4 38)(0 2 46)  */ 
	//1 4 12 2 3 17 0 5 19 2 5 25 3 5 25 4 5 26 0 1 34 3 4 38 0 2 46
	char ch[ ]={'A','B','C','D','E','F'};       
	EdgeGraph<char> EG(ch, 6, 9);             
	EG.Kruskal( );
	return 0;
}
