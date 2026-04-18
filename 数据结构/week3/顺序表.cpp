/***********************************************
    对应教材2.3.3节，顺表类SeqList的使用范例 
************************************************/
#include <iostream>
using namespace std; 

const int MaxSize = 100;            //100只是示例性的数据，根据实际问题具体定义
template <class DataType>          //定义模板类SeqList
class SeqList
{
public:
   	SeqList( );                     //无参构造函数，建立空的顺序表
   	SeqList(DataType a[ ], int n);      //有参构造函数，建立长度为n的顺序表
   	~SeqList( );                    //析构函数
   	int Length( );                   //求线性表的长度
   	int Empety();                    //判断线性表是否为空
   	DataType Get(int i);              //按位查找，查找第i个元素的值
   	int Locate(DataType x );          //按值查找，查找值为x的元素序号
   	void Insert(int i, DataType x);      //插入操作，在第i个位置插入值为x的元素
   	DataType Delete(int i);            //删除操作，删除第i个元素
   	void PrintList( );                 //遍历操作，按序号依次输出各元素
   	void Reverse( );               //**将顺序表逆置,实验书p37
   	void Insert(DataType x);         //**在有序顺序表中插入操作x的元素,并保持表L仍递增有序
    //void Delete(DataType x);        //**这样不行，不能重载，在顺序表中删除所有元素值为x的元素，要求空间复杂度为O(1)
    
	DataType *GetSeqList() ;         //获取顺序表数组指针
	template <class T> friend void Delete1(SeqList<T> &L, T x);        //**在顺序表中删除所有元素值为x的元素，要求空间复杂度为O(1)
    
    template <class T> friend void Delete2(T a[MaxSize], T x);        //**在顺序表中删除所有元素值为x的元素，要求空间复杂度为O(1)
  private:
   	DataType data[MaxSize];          //存放数据元素的数组
   	int length;                       //线性表的长度
};

template<class DataType>
SeqList<DataType> :: ~SeqList()
{
	// 析构函数，不需要做任何事情，因为data是静态数组	
}

template<class DataType>
DataType *SeqList<DataType> :: GetSeqList()
{
  return data;  // 返回数组指针，用于外部访问
}
	 
template <class DataType>
SeqList<DataType> :: SeqList()
{
	length = 0;  // 初始化空顺序表，长度为0
}

template <class DataType>
int SeqList<DataType> :: Empety()
{
	if(length == 0)  // 判断顺序表是否为空
		return 1;    // 为空返回1
	else
		return 0;    // 不为空返回0
}

template <class DataType>
int SeqList<DataType> :: Length()
{
  // 返回顺序表的长度
  return length;
}

template <class DataType>  
SeqList<DataType> :: SeqList(DataType a[ ], int n)
{
	if (n > MaxSize)  // 检查参数合法性
		throw "参数非法";
	for (int i = 0; i < n; i++)  // 复制数组元素到顺序表
		data[i] = a[i];
	length = n;  // 设置顺序表长度
}

template <class DataType>  
void SeqList<DataType> :: PrintList( )
{
  	for (int i = 0; i < length; i++)  // 遍历顺序表
    	cout << data[i]<<" ";         // 依次输出线性表的元素值
}

template <class DataType>  
int SeqList<DataType> :: Locate(DataType x)
{
   	for (int i = 0; i < length; i++)  // 遍历顺序表
    	if (data[i] == x) return i+1;  // 找到元素x，返回其序号i+1
   	return 0;                         // 退出循环，说明查找失败
}

template <class DataType>  
DataType SeqList<DataType> :: Get(int i)
{
	if (i < 1 && i > length)  // 检查位置是否合法
		throw "查找位置非法";
	else 
		return data[i - 1];  // 返回第i个元素的值
}

template <class DataType>  
DataType SeqList<DataType> :: Delete(int i)
{
	if (length == 0)  // 检查是否为空表
		throw "下溢";
	if (i < 1 || i > length)  // 检查位置是否合法
		throw "位置";
	int x = data[i - 1];      // 取出位置i的元素
	for (int j = i; j < length; j++)  // 将后面的元素前移
		data[j - 1] = data[j];       // 此处j已经是元素所在的数组下标
	length--;  // 长度减1
	return x;  // 返回被删除的元素
}

template <class DataType>  
void SeqList<DataType> :: Insert(int i, DataType x)
{
  	if (length >= MaxSize)  // 检查是否已满
	  	throw "上溢";
  	if (i < 1 || i > length + 1)  // 检查位置是否合法
	  	throw "位置";
  	for (int j = length; j >= i; j--)  // 将元素后移
		data[j] = data[j - 1];        // 第j个元素存在数组下标为j-1处
  	data[i - 1] = x;  // 在位置i插入新元素
  	length++;  // 长度加1
}


template <class DataType>   //**顺序表逆序   
void SeqList<DataType> :: Reverse()
{  
  // 实现顺序表的逆置操作
  DataType temp;
  for(int i = 0; i < length/2; i++) {
    temp = data[i];
    data[i] = data[length-1-i];
    data[length-1-i] = temp;
  }
}

template <class DataType>   //**在有序顺序表中插入x   
void SeqList<DataType> :: Insert(DataType x)
{   
  // 在有序顺序表中插入元素x，保持有序性
  int i;
  if(length >= MaxSize)  // 检查是否已满
    throw "上溢";
    
  // 找到插入位置
  for(i = 0; i < length; i++) {
    if(data[i] > x)
      break;
  }
  
  // 将元素后移
  for(int j = length; j > i; j--)
    data[j] = data[j-1];
    
  data[i] = x;  // 插入新元素
  length++;  // 长度加1
}

/*template <class DataType>   //**这样不行，不能重载删除所有元素值为x的元素  
void SeqList<DataType>::Delete(DataType x)
{   

}*/

template <class DataType>   //**用普通函数实现，删除所有元素值为x的元素 
void Delete1(SeqList<DataType> &L, DataType x)
{
  // 删除顺序表L中所有值为x的元素
  int k = 0;  // k记录不等于x的元素个数
  
  for(int i = 0; i < L.length; i++) {
    if(L.data[i] != x) {  // 如果当前元素不等于x
      L.data[k] = L.data[i];  // 保留该元素
      k++;  // 不等于x的元素计数加1
    }
  }
  
  L.length = k;  // 更新顺序表长度
}

template <class T>   //**用普通函数实现，删除所有元素值为x的元素 
void Delete2(T a[MaxSize], T x)  
{
  // 这个函数需要知道数组的实际长度才能正确工作
  // 由于参数中没有提供长度信息，此函数实现可能不完整
  // 实际使用时需要传入长度参数或者在数组中标记结束
}

int main( )
{
	int r[5] = {1, 2, 3, 6, 7},  i, x;             
   	SeqList<int> L(r, 5);                  //建立具有5个元素的顺序表
   	cout << "当前线性表的数据为：";
   	L.PrintList( );  
   	Delete1(L,2);   //参数是线性表L，删除所有值为2的元素
   	Delete2(L.GetSeqList(),2);   //参数是数组，删除所有值为2的元素
	    
	try 
   	{
   		L.Insert(2, 8);                        //在第2个位置插入值为8的元素
   		cout << endl << "执行插入操作后数据为：";
   		L.PrintList( );                        //输出插入后的线性表1 8 2 3 4 5
   		cout << endl;
   	}
	catch(const char* str){
   		cout << str << "插入操作错误！" << endl;  //捕获并处理插入异常
   	}
   
  	cout << "当前线性表的长度为：" << L.Length( );    //输出线性表的长度6
   	cout << endl;
   	cout << "请输入查找的元素值：";
   	cin >> x;
   	i = L.Locate(x);  //查找元素x的位置
   	if (0 == i) cout << "查找失败" << endl;  //未找到元素
   	else cout << "元素" << x << "的位置为：" << i << endl;  //输出元素位置
   	try
   	{
   		cout << "请输入查找第几个元素值：";
   		cin >> i;
   		cout << "第" << i << "个元素值是" << L.Get(i) << endl;  //获取第i个元素
   	}
	catch(const char* str){
   		cout << "线性表中没有该元素" << endl;  //捕获并处理查找异常
   	} 
   	
   	try 
   	{
		cout << "请输入要删除第几个元素：";
	   	cin >> i;
	   	x = L.Delete(i);                              //删除第i个元素
	   	cout << "删除的元素是" << x <<"，删除后数据为：";
   	   	L.PrintList( );                           //输出删除后的线性表
   	}
	catch(const char* str){
   		cout << "删除错误！" << endl;  //捕获并处理删除异常
   	} 
   
	return 0;  //程序正常结束
}
