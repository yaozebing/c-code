#include<iostream>
using namespace std;

//1.��ͨ�������ռ�
namespace N1 {//N1Ϊ�����ռ������
	int a = 10;
	int Add(int left, int right) {
		return left + right;
	}
}
//2.�����ռ����Ƕ��
namespace N2 {
	int a;
	int b;
	int Add(int left, int right) {
		return left + right;
	}
	namespace N3 {
		int c;
		int d;
		int Sub(int left, int right) {
			return left - right;
		}
	}
}

//3.ͬһ����������������ͬ�����Ƶ������ռ䣬����������ϳ�ͬһ�������ռ�
namespace N1{
	int Mul(int left, int right) {
		return left * right;
	}
}
//ע�⣬һ�������ռ�Ͷ�����һ���µ������������ռ��е��������ݶ������ڸ������ռ���

namespace N {
	int a = 10;
	int b = 20;
	int Add(int left, int right) {
		printf("%d\n", left + right);
		return left + right;
	}
	int Sub(int left, int right) {
		return left - right;
	}
}

//int main() {
//	printf("%d\n", a);//������������޷�ʶ��
//	return 0;
//}

////�������ռ����Ƽ��������޶���
//int main() {
//	printf("%d\n", N::a);
//	return 0;
//}
////ʹ��using�������ռ��Ա����
//using N::b;
//int main() {
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}
//
////ʹ��using namespace�����ռ���������
//using namespace N;
//int main() {
//	printf("%d\n", N::a);
//	printf("%d\n", N::b);
//	Add(10, 20);
//	return 0;
//}


void print() {
	int a;
	double b;
	char c;
	cin >> a;
	cin >> b >> c;

	cout << a << endl;
	cout << b << " " << c << endl;
}
void testfunc(int a = 1) {
	cout << a << endl;
}
void testfunc2(int a = 1, int b = 2, int c = 3) {
	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	cout << " c = " << c << endl;
}
void testfunc3(int a , int b = 2, int c = 3) {
	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
	cout << " c = " << c << endl;
}
void testfunc4(int a){
	cout << "a = " << a << endl;
}
void testfunc5(int a = 4) {
	cout << "a = " << a << endl;
}
void testref() {
	int a = 10;
	int& ra = a;
	int& rra = ra;
	cout << &a << endl << &ra << endl << &rra << endl;

}
void TestConstRef()
{
	const int a = 10;
	//int& ra = a; // ��������ʱ�����aΪ����
	const int& ra = a;
	// int& b = 10; // ��������ʱ�����bΪ����
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // ��������ʱ��������Ͳ�ͬ
	const int& rd = d;
	cout << rd << endl;
}
int& count() {
	int n = 0;
	n++;
	return n;
}
int& add(int a, int b) {
	int c = a + b;
	return c;
}
int main() {
	int& ret = add(1, 2);
	add(3, 4);
	cout << ret << endl;
	return 0;
}