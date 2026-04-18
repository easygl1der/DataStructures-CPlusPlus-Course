/*************************************************
    对应教材2.4.2节, 单链表类LinkList的使用范例 
**************************************************/
#include <iostream>                  //引入输入输出流
using namespace std;
#define endl '\n'

template <typename DataType>
struct Node
{
	DataType data;               //数据域
    Node<DataType> *next;       //指针域
};

template <typename DataType>
class LinkList
{
public:
	LinkList( );                      //无参构造函数，建立只有头结点的空链表
	LinkList(DataType a[ ], int n);       //有参构造函数，建立有n个元素的单链表
	~LinkList( );                     //析构函数
	Node<DataType> *Getfirst();       //**获取链表头指针
	int Length( );                     //求单链表的长度
	int Empety();
	DataType Get(int i);               //按位查找。查找第i个结点的元素值
	int Locate(DataType x);            //按值查找。查找值为x的元素序号
	void Insert(int i, DataType x);       //插入操作，第i个位置插入值为x的结点
	DataType Delete(int i);            //删除操作，删除第i个结点
	void Purge();                      //**单链表删除相同值算法
	void PrintList( );                  //遍历操作，按序号依次输出各元素
	void IsIncrease();					//判断是否为递增序列
	void Reverse();						//逆置
	void Clone(DataType a);						//克隆复制单链表功能
private:
	Node<DataType> *first;           //单链表的头指针
};

//判断是否为递增序列
template <typename DataType>
void LinkList<DataType> :: IsIncrease()
{
	Node<DataType> *p = first->next;
	while (p->next != NULL)
	{
		if (p->data > p->next->data)
		{
			cout << "不是递增序列" << endl;
			return;
		}
		p = p->next;
	}
	cout << "是递增序列" << endl;
}

//逆置
template <typename DataType>
void LinkList<DataType> :: Reverse()
{
	Node<DataType> *p = first->next;  // 指向第一个节点
	first->next = NULL;  // 头节点指向NULL
	Node<DataType> *q;  // 临时指针
	
	while (p != NULL)
	{
		q = p->next;  // 保存下一个节点
		p->next = first->next;  // 当前节点指向头节点的下一个节点
		first->next = p;  // 头节点指向当前节点
		p = q;  // 移动到下一个节点
	}
	delete q;
}


template <typename DataType>
LinkList<DataType> :: LinkList( )
{
	first = new Node<DataType>;              //生成头结点
  	first->next = NULL;                      //头结点的指针域置空
}

template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
  	Node<DataType> *q = NULL;
  	while (first != NULL)        //释放单链表的每一个结点的存储空间
  	{
    	q = first;                 //暂存被释放结点
    	first = first->next;         // first指向被释放结点的下一个结点
    	delete q;    
 	}
}

template <class DataType>
Node<DataType> *LinkList<DataType> ::Getfirst()       //**获取链表头指针
{ return first; }

template <typename DataType>
int LinkList<DataType> :: Empety()
{
	if(first->next == NULL)
		return 1;
	else 
		return 0;
}

template <typename DataType>
void LinkList<DataType> :: PrintList( )
{
	Node<DataType> *p = first->next;                //工作指针p初始化
  	while (p != NULL)
  	{
    	cout << p->data << " ";
    	p = p->next;                 //工作指针p后移，注意不能写作p++
  	}
}

template <typename DataType>
int LinkList<DataType> :: Length( )
{
   	Node<DataType> *p = first->next;   //工作指针p初始化为开始接点
   	int count = 0;                    //累加器count初始化
   	while (p != NULL)
   	{
    	p = p->next;
    	count++;
   	}
    return count;              //注意count的初始化和返回值之间的关系
}

template <typename DataType>  
DataType LinkList<DataType> :: Get(int i) 
{
	Node<DataType> *p = first->next;    //工作指针p初始化
	int count = 1;                     //累加器count初始化
  	while (p != NULL && count < i)    
  	{
		p = p->next;                   //工作指针p后移
		count++;
	}
	if (p == NULL) throw "位置";
	else return p->data;
}

template <typename DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
	Node<DataType> *p = first->next;   //工作指针p初始化
  	int count = 1;                     //累加器count初始化
  	while (p != NULL)    
  	{
  		if (p->data == x) return count;     //查找成功，结束函数并返回序号
  		p = p->next;                   
  		count++;
  	}
  	return 0;                        //退出循环表明查找失败
}

template <typename DataType>  
void LinkList<DataType> :: Insert(int i, DataType x)
{
	Node<DataType> *p = first, *s = NULL ;        //工作指针p初始化
	int count = 0;               
    while (p != NULL && count < i - 1)            //查找第i – 1个结点
    {
    	p = p->next;                              //工作指针p后移
      	count++;
    }
    if (p == NULL) throw "位置";        //没有找到第i – 1个结点
    else { 
      	s = new Node<DataType>; s->data = x;      //申请结点s，数据域为x
      	s->next = p->next; p->next = s;     //将结点s插入到结点p之后
    }
 }

// 头插法构造 
//template <typename DataType>  
//LinkList<DataType> :: LinkList(DataType a[ ], int n)
//{
//	first = new Node<DataType>; first->next = NULL;     //初始化一个空链表
//	for (int i = 0; i < n; i++)
//	{ 
//		Node<DataType> *s;
//		s = new Node<DataType>; s->data = a[i];    
// 		s->next = first->next; first->next = s;    //将结点s插入到头结点之后
//	}
//}

template <typename DataType>  
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
  	first = new Node<DataType>;                    //生成头结点
  	Node<DataType> *r = first, *s = NULL;           //尾指针初始化
  	for (int i = 0; i < n; i++)
  	{	 
  		s = new Node<DataType>; s->data = a[i]; 
  		r->next = s; r = s;                 //将结点s插入到终端结点之后
  	}
	r->next = NULL;        //单链表建立完毕，将终端结点的指针域置空
}

template <typename DataType>  
DataType LinkList<DataType> :: Delete(int i)
{
	DataType x;
  	Node<DataType> *p = first, *q = NULL;        //工作指针p指向头结点
  	int count = 0;               
  	while (p != NULL && count < i - 1)           //查找第i-1个结点
  	{
    	p = p->next;
    	count++;
  	}
  	if (p == NULL || p->next == NULL)  //结点p不存在或p的后继结点不存在
  		throw "位置"; 
  	else {
   		q = p->next; x = q->data;         //暂存被删结点
   		p->next = q->next;              //摘链
   		delete q; 
   		return x;
  	}
}

template <typename DataType>  
void LinkList<DataType> :: Purge() 
{
  	Node<DataType> *p = first->next, *q = first;        //工作指针p指向头结点       
  	while (p ->next!= NULL )           //查找第i-1个结点
  	{
    	if(p->data==p->next->data) 
    	{  q=p->next;
    	   p->next=q->next;
    	   delete q;
    	   			
		} 
		else  p=p->next; 
  	}
}


template <typename T>    
void Purge(Node<T> *first)   //普通的删除函数 
{
  	Node<T> *p = first->next, *q = first;        //工作指针p指向头结点       
  	while (p ->next!= NULL )           //查找第i-1个结点
  	{
    	if(p->data==p->next->data) 
    	{  q=p->next;
    	   p->next=q->next;
    	   delete q;
    	   			
		} 
		else  p=p->next; 
  	}
}

template <typename T>    
void Purge(LinkList<T> &LA)   //普通的删除函数 
{
  	Node<T> *q =LA.Getfirst(), *p = q->next;        //工作指针p指向头结点       
  	while (p ->next!= NULL )           //查找第i-1个结点
  	{
    	if(p->data==p->next->data) 
    	{  q=p->next;
    	   p->next=q->next;
    	   delete q;
    	   			
		} 
		else  p=p->next; 
  	}
}

template <typename T>    
Node<T> *Copy(Node<T> *first)   //普通的复制链表，返回一个新链表 
{
  	
}

template <typename T>    
LinkList<T> & Copy(LinkList<T> &LA,LinkList<T> &LB)   //普通的复制链表 LB=LA 
{
   
     return LB;
 }

int main( )
{
	int r[6] = {1, 2, 3,4, 4, 5}, i, x;
  	LinkList<int> L(r, 6), LA;
  	cout << "当前线性表的数据为：";
  	L.PrintList( );  
	cout<<endl; 
	                       //输出当前链表1 2 3 4 4 5
	cout<<"输出复制的新链表"<<endl; 
	
	
   
    Copy(L, LA);
    LA.PrintList();
    cout << "1*******" << endl;
    
    Copy(L, LA).PrintList();
	 
  	cout <<"2*******"<< endl; 
  	    //*** 
  		try 
	    	{
	      	L.Purge();                         //在第2个位置插入值为8的结点
	      	//Purge(L.Getfirst());     //**调用普通的删除函数 
	      	//Purge(L);     //**调用普通的删除函数 
	      	cout << "执行插入操作后数据为："; 
	      	L.PrintList( );                         //输出插入后链表1 8 2 3 4 5
	      	cout << endl;
	    	} catch(char* str){
	    		cout << str << endl;
	    	}
  	    //***
  	try 
  	{
    	L.Insert(2, 8);                         //在第2个位置插入值为8的结点
    	cout << "执行插入操作后数据为："; 
    	L.PrintList( );                         //输出插入后链表1 8 2 3 4 5
    	cout << endl;
  	} catch(const char* str){
  		cout << str << endl;
  	}
  
	cout << "当前单链表的长度为：" << L.Length( ) << endl;      //输出单链表长度6
	cout << "请输入查找的元素值：";
	cin >> x;
	i = L.Locate(x); 
    if (1 <= i) cout << "元素" << x << "的元素位置为：" << i << endl;   
    else cout << "单链表中没有元素" << x << endl;
    try
    {
    	cout << "请输入要删除第几个元素：";
    	cin >> i;
    	x = L.Delete(i);                                 //删除第i个元素
    	cout << "删除的元素值是" << x << "执行删除操作后数据为：";
    	L.PrintList( );                                 //输出删除后链表
    } catch(const char* str) {
  		cout << str << endl;
  }
  return 0;
}
