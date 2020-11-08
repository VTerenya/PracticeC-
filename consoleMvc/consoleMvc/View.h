#pragma once
#include <iostream>

class View {
public:
	View(Controller* c) {
		controller = c;
		controller->add(this);
	}
	void setController(Controller* c) {
		controller = c;
	}
	
	void Print(Set<string> s) {
		for (int i =0; i< s.Size(); i++)
		{
			cout << s[i] << " ";
		}
		cout << endl;
	}	
private:
	Controller* controller;
};