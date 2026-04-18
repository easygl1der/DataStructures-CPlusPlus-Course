#include<iostream>
using namespace std;
class Retional
{
	public:
		Retional(int s=0,int m=0):son(s),mum(m){}
		Retional operator+(Retional &a)
		{
			return Retional(son * a.mum + a.son * mum, mum * a.mum);
		}
		Retional operator-(Retional &a)
		{
			return Retional(son * a.mum - a.son * mum, mum * a.mum);
		}
		friend ostream&operator<<(ostream&output,Retional&a);
	private:
		int son;
		int mum;
};
ostream & operator<<(ostream&output,Retional&a)
{
	int r,m,n;
	m=a.mum;
	n=a.son;
	r=m%n;
	while(r!=0)
	{
		m=n;
		n=r;
		r=m%n;
	}
	a.mum=a.mum/n;
	a.son=a.son/n;
	output<<a.son<<'/'<<a.mum<<"  "<<(double(a.son)/a.mum)<<endl;
	return output;
}
int main()
{ Retional r1(2,3),r2(1,6),r3;    
  //测试你的类的功能
  r3=r1+r2;     //   2/3+1/6=5/6
  cout<<r3;
  r3=r1-r2;    //   2/3-1/6=1/2
  cout<<r3;
 
  return 0;  
}
