/***************************************************************
   对应教材7.4.3节，闭散列表的类定义、成员函数定义及使用范例 
****************************************************************/ 
#include <iostream>
using namespace std;

const int MaxSize = 11;
class HashTable1
{
public:
	HashTable1( );                     //构造函数，初始化空散列表
  	~HashTable1( );                      //析构函数
  	int Insert(int k);                     //插入
//  	int Delete(int k);                    //删除
  	int Search(int k);                    //查找
	void Print( );
private:
  	int H(int k);                           //散列函数
  	int ht[MaxSize];                    //闭散列表
};

HashTable1 :: HashTable1( )
{
	for (int i = 0; i < MaxSize; i++)
    	ht[i] = 0;                        // 0表示该散列单元为空
}

HashTable1 :: ~HashTable1( )
{
	
}

int HashTable1 :: H(int k)
{
	return k % 11;
}

void HashTable1 :: Print( )
{   for (int i = 0; i < MaxSize; i++)
	  cout <<i<< "\t";
	cout<<endl;
	for (int i = 0; i < MaxSize; i++)
		cout <<ht[i] << "\t";
	cout<<endl;
}

int HashTable1 :: Search(int k) 
{
	int i, j = H(k);                        //计算散列地址
	i = j;                               //设置比较的起始位置
	while (ht[i] != 0)
	{
		if (ht[i] == k) return i;               //查找成功
		else i = (i + 1) % MaxSize;                 //向后探测一个位置
	}
	return -1;                           //查找失败
}

int HashTable1 :: Insert(int k)
{
	int i, j = H(k);                        //计算散列地址
	i = j;                               //设置比较的起始位置
	while (ht[i] != 0)
	{
		if (ht[i] == k) return -1;        //原有元素k,不能插入 
		else i = (i + 1) % MaxSize;             //向后探测一个位置
	}
	ht[i] = k;
	return i;                             //返回插入位置 
}

int main( )
{
	//测试数据使用例7-5 
	int i, r[9] = {47, 7, 29, 11, 16, 92, 22, 8, 3};
	HashTable1 HT;
	for (i = 0; i < 9; i++)
		HT.Insert(r[i]);
	HT.Print( );
	cout<<"\n查找元素11所在的位置是:";
	cout<<HT.Search(11);	
	return 0;
}
