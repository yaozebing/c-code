#include<iostream>
using namespace std;

//1.普通的命名空间
namespace N1 {//N1为命名空间的名称
	int a = 10;
	int Add(int left, int right) {
		return left + right;
	}
}
//2.命名空间可以嵌套
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

//3.同一个工程中允许多个相同的名称的命名空间，编译器最后会合成同一个命名空间
namespace N1{
	int Mul(int left, int right) {
		return left * right;
	}
}
//注意，一个命名空间就定义了一个新的作用域，命名空间中的所有内容都局限于该命名空间中

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
//	printf("%d\n", a);//该语句编译错误，无法识别
//	return 0;
//}

////加命名空间名称及作用域限定符
//int main() {
//	printf("%d\n", N::a);
//	return 0;
//}
////使用using将命名空间成员引入
//using N::b;
//int main() {
//	printf("%d\n", N::a);
//	printf("%d\n", b);
//	return 0;
//}
//
////使用using namespace命名空间名称引入
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
	//int& ra = a; // 该语句编译时会出错，a为常量
	const int& ra = a;
	// int& b = 10; // 该语句编译时会出错，b为常量
	const int& b = 10;
	double d = 12.34;
	//int& rd = d; // 该语句编译时会出错，类型不同
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