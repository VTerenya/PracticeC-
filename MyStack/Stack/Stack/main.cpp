#include <iostream>
#include "Stack.h"
#include <stack>
using namespace std;
int main() {
	Stack<int> b;
	b.Push(50);
	b.Push(20);
	b.Push(10);
	b.Push(123);
	cout << b.Size() << endl;
	cout << b.Top() << endl;
	cout << b << endl;
	cout << b.IsEmpty() << endl;
	b.Clear();
	cout << b.IsEmpty() << endl;
	cin >> b;
	cout << b << endl;
	Stack<int> a;
	a.Push(1);
	a.Push(3);
	a.Push(5);
	cout << "SIze A : " << a.Size() << endl;
	cout << "Top A: " << a.Top() << endl;
	cout << "A: " << a << endl;
		b.Swap(a);
		cout << "B: " << b << endl;

		cout << "A: " << a << endl;
	cout << b;
}