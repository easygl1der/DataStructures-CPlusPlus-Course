/********************************** 
   对应教材3.5.1节，括号匹配问题 
***********************************/
#include <iostream>     
#include <string> 
#define endl '\n'
 
using namespace std;

class Matcher{
public:
	Matcher(string str);
	~Matcher(){ };
	int match();
private:
	string str;
};

Matcher :: Matcher(string str){
	this->str = str;
}

int Matcher :: match()
{
	char S[100];  //string S;                         		/*定义一个字符对象 */
	int i, top = -1;                        /* top为字符对象S的尾指针 */
	for (i = 0; str[i] != '\0'; i++)          /* 依次对str对象的每个字符, str[i]进行处理 */
	{
		if (str[i] == ')') {                 /*当前扫描的字符是右括号*/
		  if (top > -1) top--;              /*出栈前判断栈是否为空*/
		  else return -1;
	    }
		else if (str[i] == '(')               /*当前扫描的字符是左括号*/
		     S[++top] = str[i];              /*执行入栈操作*/
	}
	if (top == -1) return 0;                /*栈空则括号正确匹配*/
	else return 1;
}

                              
int main( )
{  //-6+(4+2)*3-5,   -6+((4+2)*3-5 ,    -6+(4+2)*3)-5,  -6+(4+2))*3)-5
	string str;                /*定义尽可能大的字符数组以接收键盘的输入*/
	int k;                                /*k接收调用函数Match的结果*/
	cout << "请输入一个算术表达式：";      
	cin >> str;                       /*将表达式以字符串方式输入*/
	Matcher m(str);
	k = m.match( );              /*函数调用，实参为字符数组的首地址*/
	if (k == 0)
		cout << "正确匹配\n";
	else if (k == 1)
		cout << "多左括号\n";
	else
		cout << "多右括号\n";
	return 0;                       
}
