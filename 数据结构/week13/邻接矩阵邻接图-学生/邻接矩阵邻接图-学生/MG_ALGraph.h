#ifndef MGraph_H                    //定义头文件
#define MGraph_H

const int MaxSize = 10;           //图中最多顶点个数

template <class DataType>     //注意这里前向引用声明
class ALGraph;

template <class DataType>       //注意这里前向引用声明
class  MGraph;

template <class DataType>
class MGraph
{
public:
   MGraph(DataType a[ ], int n, int e);    //构造函数，建立具有n个顶点e条边的图
   ~MGraph( ) { }                     //析构函数为空
   void DFSTraverse(int v);              //深度优先遍历图
   void BFSTraverse(int v);               //广度优先遍历图
   void printMG();                        //输出邻接矩阵
   //注意下面是定义友元函数
   template <class T> friend  void MatToList(MGraph<T>& A, ALGraph<T>& B);
private:
    DataType vertex[MaxSize];          //存放图中顶点的数组
    int arc[MaxSize][MaxSize];          //存放图中边的数组
    int vertexNum, arcNum;             //图的顶点数和边数
};


struct ArcNode   //定义边表结点
{
    int adjvex;  //邻接点域
    ArcNode* next;
};
template <class DataType>
struct VertexNode   //定义顶点表结点
{
    DataType vertex;
    ArcNode* firstedge;
};

template <class DataType>
class ALGraph
{
public:
    ALGraph(DataType a[], int n, int e);   //构造函数，建立一个有n个顶点e条边的图
    ~ALGraph();                        //析构函数，释放邻接表中各边表结点的存储空间
    void DFSTraverse(int v);             //深度优先遍历图
    void BFSTraverse(int v);              //广度优先遍历图
    void printALG();                      //输出邻接表
    template <class T> friend  void MatToList(MGraph<T>& A, ALGraph<T>& B);
private:
    VertexNode<DataType> adjlist[MaxSize];           //存放顶点表的数组
    int vertexNum, arcNum;              //图的顶点数和边数
};

#endif
