#include <iostream>
#include "ListVaccine.h"

using namespace std;

int main()
{
	ListVaccine* vaccine = new ListVaccine();

	vaccine->input();
	vaccine->display();

	system("pause");


	return 0;
}