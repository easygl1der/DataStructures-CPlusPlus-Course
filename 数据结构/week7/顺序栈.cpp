/************************************************
   对应教材3.2.2节，顺序栈类SeqStack的使用范例 
*************************************************/
#include <iostream>
using namespace std;

const int StackSize = 10;           //10是示例性的数据，根据实际问题具体定义
template <typename DataType>         //定义模板类SeqStack
class SeqStack
{
public:
    SeqStack( );                 //构造函数，初始化一个空栈
    ~SeqStack( );               //析构函数
    void Push( DataType x );      //入栈操作，将元素x入栈
    DataType Pop( );            //出栈操作，将栈顶元素弹出
    DataType GetTop( );         //取栈顶元素（并不删除）
    int Empty( );                //判断栈是否为空
private:
    DataType data[StackSize];    //存放栈元素的数组
    int top;                    //游标，栈顶指针，为栈顶元素在数组中的下标
};

template <typename DataType>
SeqStack<DataType> :: SeqStack()
{
	top = -1;
}

template <typename DataType>
SeqStack<DataType> :: ~SeqStack()
{
	
}

template <typename DataType>
int SeqStack<DataType> :: Empty()
{
	if(top == -1)
		return 1;
	else 
		return 0;
}

template <typename DataType>
DataType SeqStack<DataType> :: GetTop( )
{
	if(top == -1)
		throw "下溢异常";
	else
		return data[top];
}

template <typename DataType>
void SeqStack<DataType> :: Push(DataType x)
{
	if (top == StackSize - 1) throw "上溢";
	data[++top] = x;
}

template <typename DataType>
DataType SeqStack<DataType> :: Pop( )
{
	DataType x;
	if (top == -1) throw "下溢";
	x = data[top--];
	return x;
}

int main( )
{    
    int x;
	SeqStack<int> S;                          //定义顺序栈变量S
    cout << "对15和10执行入栈操作，";
	S.Push(15); S.Push(10);   
    cout << "当前栈顶元素为：" << S.GetTop( ) << endl;       //输出栈顶元素10
    try 
	{ 
		x = S.Pop( );
		cout << "执行一次出栈操作，删除元素" << x << endl;    //输出出栈元素10
    } catch(const char* str){
       	cout << str << endl;
	} 
	try
    {
		cout << "请输入待入栈元素：";
    	cin >> x;
   		S.Push(x);
    } catch(const char* str){
    	cout << str << endl;	
	} 
    if (S.Empty( ) == 1) cout << "栈为空" << endl;
	else cout << "栈非空" << endl;                   //栈有2个元素，输出栈非空
    return 0;
}

