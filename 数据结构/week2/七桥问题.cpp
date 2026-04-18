/*******************************
    对应教材1.1.1节，七桥问题 
********************************/
#include <iostream>
using namespace std;

const int MaxSize = 4;

class EulerCircuit{
public:
	EulerCircuit(int a[][MaxSize], int n);     //构造函数
    ~EulerCircuit( ){ }                        //析构函数为空
    int oddVertexNum( );        	          //求图中度为奇数的顶点个数
private:
	int mat[MaxSize][MaxSize];	           	 //二维数组存储图
    int vertexNum;	         	              //顶点个数
};

EulerCircuit :: EulerCircuit(int a[][MaxSize], int n)
{
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mat[i][j] = a[i][j];
    vertexNum = n;
}
int EulerCircuit :: oddVertexNum( ) 
{
    int count = 0, i, j, degree;		
    for (i = 0; i < vertexNum; i++) 		// 依次累加每一行元素
    {
    	degree = 0;				        	// 记录通过顶点i的边数
      	for (j = 0; j < vertexNum; j++) 
        	degree = degree + mat[i][j];
      	if (degree % 2 != 0)	 
		  	count++;
    }
    return count;		
}
                                                       
int main( )
{
    int a[4][4] = {{0, 1, 2, 2},{1, 0, 1, 1},{2, 1, 0, 0},{2, 1, 0, 0}};
    EulerCircuit G(a, 4);
	int num = G.oddVertexNum( );          //调用函数得到通奇数桥的顶点个数
    if (num >= 2)                         //两个以上的顶点通奇数桥
      	cout << num << " places with odd number of bridges, no Euler circuit exists" << endl; 
    else                                 //没有顶点通奇数桥
	  	cout << "Euler circuit exists" << endl;             
    return 0;                    
} 
