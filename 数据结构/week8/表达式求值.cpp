/********************************* 
   对应教材3.5.2节，表达式求值 
**********************************/
#include <iostream>
#include <string>
using namespace std;

class Expression
{
public:
	Expression(string str);                           //构造函数
    ~Expression( );                                     //析构函数
    int Compute( );                                     //计算表达式str的值
private:
	int Comp(char str1, char str2);                //比较str1的str2优先级
    string str;
};

Expression :: Expression(string str)              //接收键盘输入并加上定界符
{
    this->str = str + "#";
}

Expression :: ~Expression( )
{

}

int Expression :: Compute( )
{
    char OPND[100], OPTR[100];                    //定义两个顺序栈
    OPTR[0] = '#';                                       //栈OPTR初始化为定界符
    int top1 = -1, top2 = 0;                            //初始化栈OPND和OPTR的栈顶指针
    int i, k, x, y, z, op;
    for (i = 0; str[i] != '\0'; )                         //依次扫描每一个字符
    {
        if (str[i] >= 48 && str[i] <= 57)             //数字0的ASCII码是48
            OPND[++top1] = str[i++] - 48;           //将字符转换为数字压栈
        else 
		{
            k = Comp(str[i], OPTR[top2]);
            if (k == 1)                                      //str[i]的优先级高
                OPTR[++top2] = str[i++];              //将str[i]压入运算符栈
            else if (k == -1)                              //str[i]的优先级低
            {
                y = OPND[top1--];                        //从运算对象栈出栈两个元素
                x = OPND[top1--];
                op = OPTR[top2--];                      //从运算符栈出栈一个元素
                switch (op)                                 // op为运算符，进行相应运算
                {
        	        case '+': z = x + y;  break;
                    case '-':  z = x - y;   break;
            	    case '*': z = x * y;  break;
                	case '/': z = x / y;  break;
                    default:  break;
                }
                OPND[++top1] = z;                         //运算结果入运算对象栈
            }
            else 
			{                                              //str[i]与运算符栈的栈顶元素优先级相同
                top2--;                                        //匹配str[i]，扫描下一个字符
                i++;
            }
        }
    }
    return OPND[top1];                                   //运算对象栈的栈顶元素即为运算结果
}

int Expression :: Comp(char str1, char str2) 
{                    //比较str1和str2的优先级，1：str1高；0：相同；-1：str1低
    switch (str1)
    {
		case '+':  case '-':  if (str2 == '(' || str2 == '#') return 1;  else return -1;
          		              break;
        case '*':  case '/':  if (str2 == '*' || str2 == '/') return -1;  else return 1;
        	                  break;
        case '(':  return 1;  break;
        case ')':  if (str2 == '(') return 0; else return -1;
                   break;
        case '#':  if (str2 == '#') return 0; else return -1;
                   break;
        default:  break;
    }
}

int main( )                                                    
{  //(4+2)*3-5
    string str;
    cout << "请输入一个表达式：" << endl;
    cin >> str;
    Expression E(str);                           //定义对象变量E
    int result = E.Compute( );                               //result保存计算结果
    cout << "表达式的值是：" << result << endl;
    return 0;
} 
