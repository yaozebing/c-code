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
	//���һ��������һ�������Ԫ�࣬����������г�Ա������Ϊ��һ�������Ԫ����
	//��Ԫ��ϵ�ǵ���ģ������ڵ���˼
	//��Ԫ��ϵ���ܴ���
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
	//�����������Ϊ��֧��������ֵ
	friend ostream& operator << (ostream& _cout, date& d) 
	{
		_cout << d._year << " " << d._month << " " << d._day << endl;
		return _cout;
	}
	//��̬��Ա�����ڲ�û��thisָ��
	static int getc()
	{
		//��̬��Ա�������ܷ��ʷǾ�̬��Ա����/����,��Ǿ�̬��Ա������thisָ�룬���Ǿ�̬��Ա�����ڲ�ȱ��thisָ�룬���Բ��ܷ���
		//display();
		//cout <<_year<<_month<<_day;
		return cnt;
	}
	void display()
	{
		cout << _year << " " << _month << " " << _day << endl;
		//�Ǿ�̬��Ա�������Է��ʾ�̬��Ա����/����
		getc();
		cout << cnt << endl;
	}
private:
	//c++��ʼ����ʽ���൱�ڸ�һ��ȱʡֵ
	//���һ�ֺ�ѡ
	int _year = 1;
	int _month = 1;
	int _day = 1;
	//��̬��Ա���������ж�����˳�Ա�����Կ������Ա
	//��̬��Ա����������������ʱ���Ĭ��ֵ
	//��̬��Ա���ڶ���ģ���У�һ����������ݶΣ������ٳ�ʼ���б��г�ʼ��
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
	date d;//����
	date d2 = fun(d);//��������//fun�������Ż���ֻ�����ο������죬���Σ�����d2
	//cout << cnt << endl;
	//�������
	cout << d.getc() << endl;
	cout << d2.getc() << endl;
	cout << &d.cnt << endl;
	cout << d2.cnt << endl;
	//����+�������޶���

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
	//��һ�����ڲ�����һ���µ���
	//�ڲ�����Ȼ����Ϊ�ⲿ�����Ԫ��
	//�ڲ�����Ϊһ������������ڣ����������ⲿ��
	//�ⲿ�಻�ܿ����ڲ������Ԫ��
	class D
	{
	public:
		void fun(const C& c)
		{
			//����ͨ�����Ա�����ⲿ���˽�г�Ա
			cout << c._c << endl;
			cout << c._sc << endl;
			cout << c._color << endl;
			cout << C::_sc << endl;
			//����ֱ�ӷ����ⲿ���static��Ա
			cout << _sc << endl;
		}
	private:
		int _d;
	};
private:
	//�ڲ������������κεط�����
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
//��̬��Ա��static +��Ա����/��Ա����
/*
1����̬��Ա�����ڲ�û��thisָ��
2��
��̬��Ա������ʽ
1���������
2������+
*/