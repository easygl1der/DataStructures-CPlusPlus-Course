#include<iostream>
using namespace std;
const double pi=3.1415;
class Cylinder
{
	public:
		Cylinder(double h=0,double r=0,double x1=0,double y1=0):height(h),radius(r),x(x1),y(y1){}
		~Cylinder()
		{
			cout<<"finish";
		}
		Cylinder (const Cylinder &a)
		{
			this->height=a.height;
			this->radius=a.radius;
			this->x=a.x;
			this->y=a.y;
		}
		double area() const;
		double volume() const;
		friend void set(Cylinder &a);
		friend void print(const Cylinder &a);
		friend ostream&operator<<(ostream &,Cylinder &);
		friend istream&operator>>(istream &,Cylinder &);
	private:
		double height;
		double radius;
		double x;
		double y;
};
double Cylinder::area() const
{
	return(2*pi*(this->radius)*(this->radius)+2*pi*(this->radius)*(this->height));
}
double Cylinder::volume() const
{
	return(pi*(this->radius)*(this->radius)*(this->height));
}
void set(Cylinder &a)
{
	cin>>a.height>>a.radius>>a.x>>a.y;
}
void print(const Cylinder &a)
{
	cout<<"Gao"<<a.height<<"  "<<"BanJing"<<a.radius<<"  "
		<<"YuanXinZuoBiao"<<'('<<a.x<<','<<a.y<<')'<<endl;
	cout<<"YuanZhuMianJi"<<a.area()<<"  "<<"YuanZhuTiJi"<<a.volume()<<endl; 
}
ostream &operator<<(ostream& output,Cylinder&a)
{
	output<<"Gao"<<a.height<<"  "<<"BanJing"<<a.radius<<"  "
		<<"YuanXinZuoBiao"<<'('<<a.x<<','<<a.y<<')'<<endl;
	output<<"YuanZhuMianJi"<<a.area()<<"  "<<"YuanZhuTiJi"<<a.volume()<<endl; 
	return output;

}
istream &operator>>(istream&input,Cylinder&a)
{
	input>>a.height>>a.radius>>a.x>>a.y;
	return input;
}
int main()
{
	Cylinder cy1,cy2;
	cin>>cy1>>cy2;
	cout<<"cy1="<<cy1<<endl<<"cy2="<<cy2<<endl;
	Cylinder cy3=cy1,cy4;
	cout<<"cy3="<<cy3<<endl<<"cy4="<<cy4<<endl;
	set(cy4);
	print(cy4);
	return 0;
}
