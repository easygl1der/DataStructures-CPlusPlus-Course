/************************************************ 
   对应教材3.3.3节,链队列类LinkQueue的使用范例 
*************************************************/
#include <iostream>
using namespace std;

template <typename DataType>  
struct Node
{
	DataType data;               //数据域
	Node<DataType> *next;       //指针域
};

template <typename DataType>
class LinkQueue
{
public:
    LinkQueue( );               //构造函数，初始化一个空的链队列
    ~LinkQueue( );              //析构函数，释放链队列各结点的存储空间
    void EnQueue(DataType x);    //入队操作，将元素x入队
    DataType DeQueue( );        //出队操作，将队头元素出队
    DataType GetQueue( );        //取链队列的队头元素
    int Empty( );                //判断链队列是否为空
private:
    Node<DataType> *front, *rear;       //队头和队尾指针，分别指向头结点和终端结点
};

template <typename DataType>
LinkQueue<DataType> :: LinkQueue( )
{
	Node<DataType> *s = NULL;
  	s = new Node<DataType>; s->next = NULL;              //创建头结点s
  	front = rear = s;                //将队头指针和队尾指针都指向头结点s
}

template <typename DataType>
LinkQueue<DataType> :: ~LinkQueue()
{
	Node<DataType> *q = NULL;
  	while (front != NULL)        //释放单链表的每一个结点的存储空间
    {
    	q = front;                 //暂存被释放结点
    	front = front->next;         // front指向被释放结点的下一个结点
    	delete q;    
    }
}

template <typename DataType>
void LinkQueue<DataType> :: EnQueue(DataType x)
{
  	Node<DataType> *s = NULL;
  	s = new Node<DataType>;                 //申请结点s
  	s->data = x; s->next = NULL; 
  	rear->next = s; rear = s;                   //将结点s插入到队尾
}

template <typename DataType>
DataType LinkQueue<DataType> :: DeQueue( )
{
	DataType x;
	Node<DataType> *p = NULL;
	if (rear == front) throw "下溢";
	p = front->next; x = p->data;           //暂存队头元素
	front->next = p->next;                //将队头元素所在结点摘链
	if (p->next == NULL) rear = front;      //判断出队前队列长度是否为1
	delete p;
  	return x;
}

template <typename DataType>
DataType LinkQueue<DataType> :: GetQueue()
{
	if(front == rear)
		throw "下溢异常";
	else
		return front->next->data;
}

template <typename DataType>
int LinkQueue<DataType> :: Empty()
{
	if(front == rear)
		return 1;
	else 	
		return 0;
}

int main( )
{    
    int x;
	LinkQueue<int> Q;                                      //定义对象变量Q
    cout << "对5和8执行入队操作，";
	Q.EnQueue(5); Q.EnQueue(8);
	cout << "当前队头元素为：" << Q.GetQueue( ) << endl;        //输出队头元素5
	
	try
	{
		x = Q.DeQueue( );
		cout << "执行一次出队操作，出队元素是：" << x << endl;   //输出出队元素5
	} catch(const char* str){
		cout << str << endl;
	}
	
	try
	{
		cout << "请输入入队元素：";
		cin >> x;
		Q.EnQueue(x);
    } catch(const char* str){
    	cout << str << endl;	
	}
    
	if (Q.Empty( ) == 1) cout << "队列为空" << endl;
	else cout << "队列非空" << endl;              //队列有2个元素，输出队列非空
    return 0;
}
