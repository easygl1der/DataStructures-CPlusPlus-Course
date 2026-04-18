/***************************************************************
   对应教材7.4.3节，开散列表的类定义、成员函数定义及使用范例 
****************************************************************/ 
#include <iostream>
using namespace std;

template <typename DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

const int MaxSize = 11;
class HashTable2
{
public:
	HashTable2( );                       //构造函数，初始化开散列表
  	~HashTable2( );                      //析构函数，释放同义词子表结点
  	int Insert(int k);                       //插入
  	int Delete(int k);                      //删除
  	Node<int> * Search(int k);              //查找
	void Print( );
private:
  	int H(int k);                             //散列函数
  	Node<int> * ht[MaxSize];             //开散列表
};

HashTable2 :: HashTable2( )
{
	for (int i = 0; i < MaxSize; i++)
  	{
  		ht[i] = NULL;
	}
}

HashTable2 :: ~HashTable2( )
{
	Node<int> *p = NULL, *q = NULL;
	for (int i = 0; i < MaxSize; i++)
  	{
  		p = q = ht[i];
  		while (p != NULL)
  		{
    		p = p->next;
    		delete q;
    		q = p;
		}
	}
}

int HashTable2 :: H(int k)
{
	return k % 11;
}

void HashTable2 :: Print( )
{
	Node<int> *p = NULL; 
	for (int i = 0; i < MaxSize; i++)
	{
		p = ht[i];
		cout<<i;
		while (p != NULL)
		{
			cout <<"->"<< p->data << "\t";
			p = p->next;
		}
		cout << endl;
	}
	
}


Node<int> * HashTable2 :: Search(int k)
{
	int j = H(k);                              //计算散列地址
	Node<int> *p = ht[j];                      //工作指针p初始化
	while (p != NULL)
	{
		if (p->data == k) return p;
		else p = p->next;
	}
	return NULL;                             //查找失败
}

int HashTable2 :: Insert(int k)
{
	int j = H(k);                              //计算散列地址
	Node<int> *p = Search(k);
	if (p != NULL)
		return -1;                            //已存在元素k，无法插入 
	else {
		p = new Node<int>; p->data = k;
		p->next = ht[j];
		ht[j] = p;
		return 1;                              //插入成功标志 
	}
}

int main( )
{
	//测试数据使用例7-5 
	int i, r[9] = {47, 7, 29, 11, 16, 92, 22, 8, 3};
	HashTable2 HT;
	for (i = 0; i < 9; i++)
		HT.Insert(r[i]);
	HT.Print( );
	cout<<"\n查找元素11所在的位置是:";
	cout<<HT.Search(11)->data;	
	return 0;
}
