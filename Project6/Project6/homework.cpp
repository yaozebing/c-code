#include<iostream>
using namespace std;

//class Date {
//public:
//	void SetDate(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Display() {
//		cout << _year << ' ' << _month << ' ' << _day << ' ' << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class date {
public:
	//1.无参构造函数
	date() {

	}
	//2.带参构造函数
	//这里可以设置缺省形参
	//date(int year = 1990, int month = 10, int day = 4) {
	date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	//3.重载构造函数
	date(float a) {

	}
	void display() {
		cout << _year << " " << _month << " " << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

// 默认构造函数
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

class time {
public:

private:
	int hour;
	int minute;
	int second;
};
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print() {
		cout << _year << " " << _month << " " << _day << " " << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	time _t;
};
void test2() {
	Date d1;

}
void Test()
{
	Date d1;
}
void test1() {
	date d1;//调用无参构造函数
	d1.display();

	date d3();
	//注意：通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	//声明d3函数，该函数无参，返回一个日期类型的对象

	date d2(2020, 6, 1);
	d2.display();
}

int main() {
	test2();
	return 0;
}