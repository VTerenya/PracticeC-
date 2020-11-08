#include <iostream>
#include "set.h"
#include "Model.h"
#include "View.h"
#include "Controller.h"

using namespace std;

int main() {
	Model model;
	View view(&model);
	Controller constroller(&model);
	constroller.start();
	return 0;
}