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
	//1.�޲ι��캯��
	date() {

	}
	//2.���ι��캯��
	//�����������ȱʡ�β�
	//date(int year = 1990, int month = 10, int day = 4) {
	date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	//3.���ع��캯��
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

// Ĭ�Ϲ��캯��
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
	date d1;//�����޲ι��캯��
	d1.display();

	date d3();
	//ע�⣺ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	//����d3�������ú����޲Σ�����һ���������͵Ķ���

	date d2(2020, 6, 1);
	d2.display();
}

int main() {
	test2();
	return 0;
}