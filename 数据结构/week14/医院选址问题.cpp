/********************************** 
   对应教材6.8.2节，医院选址问题 
***********************************/
#include <iostream>
#include <iomanip>
using namespace std;

const int MaxValue = 100;                  //定义const常量 100
const int N = 5;                                //假设图中有5个顶点
class Hospital
{
public:
    Hospital(char v[N],int e[N][N], int n);        //构造函数
    ~Hospital( );                                     //析构函数
    void Floyd(int dist[N][N]);                          //求任意两个顶点之间的最短路径
    int Center( );                                        //求图的中心点，返回中心点的下标
    void printMG();                        //输出邻接矩阵
private:
    char vertex[N] ;                                 //一维数组存放顶点信息
    int edge[N][N];                                  //二维数组存放邻接关系
    int vertexNum;                                //顶点个数
};

Hospital :: Hospital(char v[N], int e[N][N], int n)
{
    for (int i = 0; i < n; i++)                       //初始化顶点信息
        vertex[i] = v[i];
    for(int i = 0; i < n; i++)                        //初始化邻接矩阵
        for (int j = 0; j < n; j++)
            edge[i][j] = e[i][j] ;
    vertexNum = n;
}

Hospital :: ~Hospital( )
{

}

void Hospital::printMG()
{
	for (int i = 0; i < vertexNum; i++) {
		for (int j = 0; j < vertexNum; j++)
			cout <<setw(4) <<edge[i][j] ;
		cout << endl;
	}
}
 
void Hospital :: Floyd(int dist[N][N])
{
    int i, j, k;
    for (i = 0; i < vertexNum; i++)                       //初始化结果矩阵dist
        for (j = 0; j < vertexNum; j++)
	        dist[i][j] = edge[i][j];
    for (k = 0; k < vertexNum; k++)                     //进行N次迭代
        for (i = 0; i < vertexNum; i++)                  //顶点i和j之间是否经过顶点k
            for (j = 0; j < vertexNum; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

int Hospital :: Center( )
{
    int wayCost, minCost = MaxValue;
    int i, k,j, index, dist[N][N];                              //矩阵dist存储顶点之间的最短路径长度
    Floyd(dist);                                            //顶点i到其他顶点的路径长度之和
    for (i = 0; i < vertexNum; i++)                         //输出dist 
      {
	    for (j = 0; j < vertexNum; j++)     
          cout<<setw(4)<<dist[i][j];
          cout<<endl;
       }
	for (k = 0; k < vertexNum; k++)                          //依次求每个顶点的往返代价
    {
        wayCost = 0;                                          //往返代价初始化为0
        for (i = 0; i < vertexNum; i++)                     //顶点i到其他顶点的路径长度之和
            wayCost = wayCost + dist[i][k];
        for (i = 0; i < vertexNum; i++)                    //其他顶点到顶点i的路径长度之和
            wayCost = wayCost + dist[k][i];
        if (wayCost < minCost) {
            minCost = wayCost;
     		index = k;                                         //顶点k为当前的中心点
        }
    }
    return index;                                           //返回中心点的下标
}

int main( )
{
    char vertex[N] = {'A','B','C','D','E'};     
    int edge[N][N] = { {0,13,MaxValue,4,MaxValue}, 
		               {13,0,15,MaxValue,5},
                       {MaxValue,MaxValue,0,12,MaxValue}, 
        		       {4,MaxValue,12,0,MaxValue},
                       {MaxValue,MaxValue,6,3,0}          };
    int minPoint;
    Hospital H(vertex, edge, 5);                  //定义对象H
    cout<<"输出初始的图矩阵"<<endl; 
    H.printMG();
    cout<<endl<<"Floyd算出的最短路径矩阵"<<endl;
    minPoint = H.Center( );                       //调用函数Center求中心点
    cout << "应该设在点:" << vertex[minPoint] << endl;
    return 0;
}
