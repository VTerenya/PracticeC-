#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List<int> list;
	list.PushBack(5);
	list.PushBack(7);
	cout << list << endl;
	cin >> list;
	cout << list << endl;
	
}
