#pragma once
#include "Model.h"
#include "set.h"
#include "iostream"
#include "IController.h"

class Controller : public IController{
public:
	Controller(std::vector<Model*> m, View* v): view(v), _model(m) {
		view->setController(this);
		for (auto& t : _model) {
			t->
		}
	}

	void add(View* v) {
		
	}

	void start() {
		int size;
		std::cin >> size;
		do {
			Set<string> t(size);
			for (int i = 0; i < size; i++)
			{
				string str;
				cin >> str;
				t.Insert(str);
			}
			_model->set(t);
			cin >> size;
		} while (size != 0);
	}
private:
	Set<string> _model;
	View* view;
};