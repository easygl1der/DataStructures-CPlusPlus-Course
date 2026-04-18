/*************************************************
   对应教材3.3.2节,循环队列类CirQueue的使用范例 
**************************************************/
#include <iostream>
using namespace std;

const int QueueSize = 100;               //100是示例性数据，根据需要重新定义
template <typename DataType>             //定义模板类CirQueue
class CirQueue
{
public:
    CirQueue( );                        //构造函数，初始化空队列
    ~CirQueue( );                     //析构函数
    void EnQueue(DataType x);          //入队操作，将元素x入队
    DataType DeQueue( );              //出队操作，将队头元素出队
    DataType GetQueue( );             //取队头元素（并不删除）
    int Empty( );                     //判断队列是否为空
private:
    DataType data[QueueSize];             //存放队列元素的数组
    int front, rear;                     //游标，队头和队尾指针
};

template <typename DataType>
CirQueue<DataType> :: CirQueue()
{
	rear = front = QueueSize - 1;
}

template <typename DataType>
CirQueue<DataType> :: ~CirQueue()
{
	
}

template <typename DataType>
void CirQueue<DataType> :: EnQueue(DataType x)
{
  	if ((rear + 1) % QueueSize == front) 
  		throw "上溢";
  	rear = (rear + 1) % QueueSize;          //队尾指针在循环意义下加1
  	data[rear] = x;                       //在队尾处插入元素
}

template <typename DataType>
DataType CirQueue<DataType> :: DeQueue( )
{
	if (rear == front) throw "下溢"; 
  	front = (front + 1) % QueueSize;      //队头指针在循环意义下加1
  	return data[front];                  //读取并返回出队前的队头元素
}      

template <typename DataType>
DataType CirQueue<DataType> :: GetQueue( )
{
	if (rear == front) throw "下溢"; 
  	return data[(front + 1) % QueueSize];        //注意不修改队头指针
}

template <typename DataType>
int CirQueue<DataType> :: Empty()
{
	if(front == rear)
		return 1;
	else
		return 0;
} 

int main( )
{    
    int x;
    CirQueue<int> Q;                            //定义对象变量Q
    cout << "对5和8执行入队操作，";
	Q.EnQueue(5); Q.EnQueue(8);
	cout << "当前队头元素为：" << Q.GetQueue( ) << endl;      //输出队头元素5
	
	try
	{
		x = Q.DeQueue( );
		cout << "执行一次出队操作，出队元素是：" << x << endl;    //输出出队元素5
	}catch(const char* str){
		cout << str << endl;	
	} 
	
	try
	{
		cout <<"请输入入队元素：";
		cin >> x;
		Q.EnQueue(x);
    }catch(const char* str){
    	cout << str << endl;	
	} 
    
	if (Q.Empty( ) == 1) cout << "队列为空" << endl;
	else cout << "队列非空" << endl;                //队列有2个元素，输出队列非空
    return 0;
}
