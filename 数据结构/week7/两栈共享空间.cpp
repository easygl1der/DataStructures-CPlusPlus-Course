/*******************************************
   对应教材3.4.1节,两栈共享空间及使用范例 
********************************************/
#include <iostream>
using namespace std;

const int StackSize = 10;           //10是示例性的数据，根据实际问题具体定义
template <typename DataType>         //定义模板类SeqStack
class BothStack
{
public:
    BothStack( );                 //构造函数，初始化一个空栈
    ~BothStack( );               //析构函数
    void Push(int i, DataType x );      //入栈操作，将元素x入栈
    DataType Pop(int i);            //出栈操作，将栈顶元素弹出
    DataType GetTop(int i);         //取栈顶元素（并不删除）
    int Empty(int  i);                //判断栈是否为空
private:
    DataType data[StackSize];    //存放栈元素的数组
    int top1, top2;                    //游标，栈顶指针，为栈顶元素在数组中的下标
};

template <typename DataType>
BothStack<DataType> :: BothStack()
{
	top1 = -1;
	top2 = StackSize;
}

template <typename DataType>
int BothStack<DataType> :: Empty(int i)
{
	if (i == 1) {
		if(top1 == -1)
			return 1;
		else 
			return 0;
	}
	else {
		if(top2 == StackSize)
			return 1;
		else 
			return 0;
	}
}

template <typename DataType>
BothStack<DataType> :: ~BothStack()
{
	
}

template <typename DataType>
DataType BothStack<DataType> :: GetTop(int i)
{
	if(i == 1) {
		if(top1 == -1)
			throw "下溢异常";
		else
			return data[top1];
	}
	else {
		if(top2 == StackSize)
			throw "下溢异常";
		else
			return data[top2];
	} 
}

template <typename DataType>
void BothStack<DataType> :: Push(int i, DataType x)
{
	if (top1 == top2  - 1) throw "上溢";
	if (i == 1) 
		data[++top1] = x;	
	else
		data[--top2] = x;	
}

template <typename DataType>
DataType BothStack<DataType> :: Pop(int i)
{
	DataType x;
	if (i == 1) {
		if (top1 == -1) throw "下溢";
		x = data[top1--];	
	}
	else {
		if (top2 == StackSize) throw "下溢";
	 	x = data[top2++];
	}
	return x;
}

int main( )
{    
    int x;
	BothStack<int> S;                          //定义顺序栈变量S
    cout << "对15执行栈1的入栈操作，";
	S.Push(1, 15);
	cout << "当前栈1的栈顶元素为：" << S.GetTop(1) << endl;       //输出栈顶元素15
	cout << "对10执行栈2的入栈操作，";
	S.Push(2, 10);   
    	cout << "当前栈2的栈顶元素为：" << S.GetTop(2) << endl;       //输出栈顶元素10 
    try 
	{ 
		x = S.Pop(1);
		cout << "对栈1执行一次出栈操作，删除元素" << x << endl;    //输出出栈元素15 
    } catch(const char* str){
       	cout << str << endl;
	} 
	try
    {
		cout << "请输入待入栈元素：";
    	cin >> x;
   		S.Push(2, x);
    } catch(const char* str){
    	cout << str << endl;	
	} 
    if (S.Empty(1) == 1) cout << "栈1为空" << endl;
	else cout << "栈1非空" << endl;                   //栈1空
    if (S.Empty(2) == 1) cout << "栈2为空" << endl;
	else cout << "栈2非空" << endl;                   //栈2有2个元素，输出栈非空
	return 0;
}
