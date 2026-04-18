#include <iostream>           //引用输入输出流库函数的头文件
using namespace std;

const int N=20;
void  getNext(char T[], int next[])
{
     // 初始条件
    int j = 0;
    int k = -1;
    next[0] = -1;
 
    // 根据已知的前j位推测第j+1位
    while (T[j]!='\0')
    {
        if (k == -1 || T[j] == T[k])
        {
            next[++j] = ++k;
        }
        else  k = next[k]; 
    }
}
 
 int main()
 {  char T[N];
    int next[N];
    cin>>T;
	getNext(T,next);
    for (int i=0;i<N; i++)
      cout<<next[i]<<" "; 
	return 0;
 	
 }
