#include<iostream>
using namespace std;
class Shape
{
public:
	virtual void printArea() const = 0;
	virtual double area()const = 0;
};
class Circle :public Shape
{
public:
	Circle(double r):radius(r){}
	void printArea()const
	{
		cout << "Circle:" << 3.14159 * radius * radius << endl;
	}
	double area()const
	{
		return 3.14159 * radius * radius;
	}
private:
	double radius;
};
class Square :public Shape
{
public:
	Square(double l) :length(l) {}
	void printArea()const
	{
		cout << "Square:" << length * length << endl;
	}
	double area()const
	{
		return length * length;
	}
private:
	double length;
};
class Rectangle :public Shape
{
public:
	Rectangle(double l,double w):length(l),width(w){}
	void printArea()const
	{
		cout << "Rectangle:" << length * width << endl;
	}
	double area()const
	{
		return length * width;
	}
private:
	double length;
	double width;
};
class Trapezoid :public Shape
{
public:
	Trapezoid(double u, double l, double h) :upperbase(u), lowerbase(l), height(h) {}
	void printArea()const
	{
		cout << "Trapezoid:" << 0.5 * (upperbase + lowerbase) * height << endl;
	}
	double area()const
	{
		return 0.5 * (upperbase + lowerbase) * height;
	}
private:
	double upperbase;
	double lowerbase;
	double height;
};
class Triangle :public Shape
{
public:
	Triangle(double b, double h) : base(b), height(h) {}
	void printArea()const
	{
		cout << "Triangle:" << 0.5*base * height << endl;
	}
	double area()const
	{
		return 0.5 * base * height;
	}
private:
	double base;
	double height;
};
int main()
{
	Shape* pt[5];
	Circle c1(3.3);
	Square s1(8);
	Rectangle r1(4,6.3);
	Trapezoid t1(2.2, 3.4, 7);
	Triangle t2(1,4.7);

	pt[0] = &c1;
	pt[0]->printArea();
	pt[1] = &s1;
	pt[1]->printArea();
	pt[2] = &r1;
	pt[2]->printArea();
	pt[3] = &t1;
	pt[3]->printArea();
	pt[4] = &t2;
	pt[4]->printArea();

	cout << "面积之和：" << pt[0]->area() + pt[1]->area() + pt[2]->area() + pt[3]->area() + pt[4]->area() << endl;
	return 0;
}
