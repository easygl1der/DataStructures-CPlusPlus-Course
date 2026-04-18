/*3.用虚函数和抽象类的方法，实现下图的继承和派生，分别声明Person 类、Teacher(教师)类和Cadre(干部)类，采用多重继承方式派生出新类Teacher_Cadre(教师兼干部)类。要求： 
(1) 包含姓名、年龄、性别、地址、电话等数据成员。
(2) 在Teacher类中还包含数据成员title(职称)，在Cadre类中还包含数据成员post(职务)。在Teacher_Cadre类中还包含数据成员wages(工资)。
(3) 在类体中声明成员函数，在类外定义成员函数。
(4) 类的成员函数display，输出每个类对象的信息。
(5) 定义5个Teacher_Cadre对象，用指向基类的指针，输出5个Teacher_Cadre对象的信息。*/
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
class Person
{
	public:
		Person(string n,int a,char s,string a1,int t):name(n),age(a),sex(s),address(a1),telephone(t){}
		virtual void print()
		{
			cout<<name<<' '<<age<<' '<<sex<<' '<<address<<' '<<telephone<<endl;
		}
	protected:
		string name;
		int age;
		char sex;//1男 2女
		string address;
		int telephone; 
};
class Teacher:virtual public Person
{
	public:
		Teacher(string n,int a,char s,string a1,int t,string t1):Person(n,a,s,a1,t),title(t1){}
		void print()
		{
			this->Person::print();
			cout<<title<<endl;
		}
	protected:
		string title;
};
class Cadre:virtual public Person
{
	public:
		Cadre(string n,int a,char s,string a1,int t,string p):Person(n,a,s,a1,t),post(p){}
		void print()
		{
			this->Person::print();
			cout<<post<<endl;
		}
	protected:
		string post;
};
class Teacher_Cadre:public Teacher,public Cadre
{
	public:
		Teacher_Cadre(string n,int a,char s,string a1,int t,string t1,string p,int w):
			Person(n,a,s,a1,t),Teacher(n,a,s,a1,t,t1),Cadre(n,a,s,a1,t,p),wages(w){}
		void print()
		{
			this->Person::print();
			cout<<title<<' '<<post<<' '<<wages<<endl;
		}
	protected:
		int wages;
};
int main()
{
	Person *pt[5];
	Teacher_Cadre tc[5]=
	{
		Teacher_Cadre("王明", 56, '1', "北京市海淀区", 832169, "副教授", "宣传委员", 32582),
		Teacher_Cadre("李华", 83, '1', "上海市浦东新区", 5449261, "教授", "组织委员", 18273),
		Teacher_Cadre("张丽", 23, '2', "广州市天河区", 647624, "讲师", "生活委员", 13522),
		Teacher_Cadre("刘强", 57, '1', "深圳市南山区", 587393, "助理教授", "文娱委员", 12471),
		Teacher_Cadre("周婷", 26, '2', "成都市武侯区", 385727, "博士后", "无", 1233)
	};
	int i;
	for(i=0;i<5;i++)
	{
		pt[i]=&tc[i];
		pt[i]->print();
	} 
	return 0;
}
