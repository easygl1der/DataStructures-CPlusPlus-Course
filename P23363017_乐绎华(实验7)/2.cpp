#include<iostream>
using namespace std;
class Complex
{
	public:
		Complex(int r=0,int i=0):real(r),imag(i){}
		Complex operator+(Complex &c2)
		{
			return Complex(real+c2.real,imag+c2.imag);
		}
		Complex operator-(int a)
		{
			return Complex(real-a,imag);
		}
		friend Complex operator+(int a,Complex &c);
		friend istream& operator>>(istream& input,Complex &a);
		friend ostream& operator<<(ostream&output,Complex &a);
		
	private:
		int real;
		int imag;
};
Complex operator+(int a,Complex &c)
{
	return Complex(a+c.real,c.imag);
}
istream& operator>>(istream& input,Complex &a)
{
	input>>a.real>>a.imag;
	return input;
}
ostream& operator<<(ostream&output,Complex &a)
{
	output<<a.real<<'+'<<a.imag<<"i"<<endl;
	return output;
}
int main()
{
 Complex c1, c2, c3;
 cin>>c1>>c2;
 cout<<"c1="<<c1<<"c2="<<c2<<endl;
 c3=c1+c2;
 cout<<"c1+c2="<<c3<<endl;
 c3=c1-10;
 cout<<"c1+i="<<c3<<endl;
 c3=10+c2;
 cout<<"i+c1="<<c3<<endl;
 return 0;
}
