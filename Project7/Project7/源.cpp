#include<iostream>
using namespace std;

//int cnt = 0;
ostream& operator << (ostream& _cout, date&d)
{
	_cout << d._year << " " << d._month << " " << d._day << endl;
}
istream& operator >>(istream& _cin, date& d)
{
	_cin >> d._year >> d._month >> d._day;
}
class B
{
	//如果一个类是另一个类的友元类，则此类中所有成员函数即为另一个类的友元函数
	//友元关系是单向的，类似于单相思
	//友元关系不能传递
public:
	void display(const date d)
	{
		cout << d._year << " " << d._month << " " << d._day << endl;
	}
};
class date {
public:
	friend istream& operator >>(istream& _cin, date& d);
	friend ostream& operator <<(ostream& _cout, date& d);
	friend class B;
	//date()
	//{}
	date(int year = 2020, int month = 12, int day = 25)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		++cnt;
		cout << "date(int int int)" << endl;
	}
	date(const date& d) 
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		++cnt;
		cout << "date(const int&)" << endl;
	}
	//返回输出流是为了支持连续赋值
	friend ostream& operator << (ostream& _cout, date& d) 
	{
		_cout << d._year << " " << d._month << " " << d._day << endl;
		return _cout;
	}
	//静态成员函数内部没有this指针
	static int getc()
	{
		//静态成员函数不能访问非静态成员函数/变量,因非静态成员函数需this指针，但是静态成员函数内部缺少this指针，所以不能访问
		//display();
		//cout <<_year<<_month<<_day;
		return cnt;
	}
	void display()
	{
		cout << _year << " " << _month << " " << _day << endl;
		//非静态成员函数可以访问静态成员函数/变量
		getc();
		cout << cnt << endl;
	}
private:
	//c++初始化方式，相当于给一个缺省值
	//最后一种候选
	int _year = 1;
	int _month = 1;
	int _day = 1;
	//静态成员变量，所有对象共享此成员，可以看成类成员
	//静态成员变量不能在声明的时候给默认值
	//静态成员不在对象模型中，一般存在在数据段，不能再初始化列表中初始化
public:
	static int cnt;
};
int date::cnt = 0;
date fun(date d) {
	return d;//
}
void test() {
	date d;
	date d2(2020, 5, 26);
}
void test2() 
{
	date d;//构造
	date d2 = fun(d);//拷贝构造//fun：经过优化，只有两次拷贝构造，传参，创建d2
	//cout << cnt << endl;
	//对象访问
	cout << d.getc() << endl;
	cout << d2.getc() << endl;
	cout << &d.cnt << endl;
	cout << d2.cnt << endl;
	//类名+作用域限定符

}
void test3() 
{
	date d(2020, 5, 23);
	date d2(2020, 5, 22);
	cout << d << d;
	//d << cout;
	operator<<(operator<<(cout, d), d2);
}
void test4() 
{
	B b;
	date d1(2029, 2, 2);
	b.display(d1);
}
class color
{
private:
	int r;
	int g;
	int y;
};
class C
{
public:
	//在一个类内部定义一个新的类
	//内部类天然的作为外部类的友元类
	//内部类作为一个独立的类存在，不附属于外部类
	//外部类不能看着内部类的友元类
	class D
	{
	public:
		void fun(const C& c)
		{
			//可以通过类成员访问外部类的私有成员
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << c._color << endl;
			cout << C::_sc << endl;
			//可以直接访问外部类的static成员
			cout << _sc << endl;
		}
	private:
		int _d;
	};
private:
	//内部类可以在类的任何地方定义
	class E
	{

	};
	int _c;
	static int _sc;
	color _color;
};
int main() {
	test3();
	return 0;
}
//静态成员：static +成员变量/成员函数
/*
1、静态成员函数内部没有this指针
2、
静态成员访问形式
1、对象访问
2、类名+
*/