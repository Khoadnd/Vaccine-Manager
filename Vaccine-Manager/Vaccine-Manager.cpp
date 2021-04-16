#include <iostream>
#include "ListVaccine.h"
#include "Menu.h"

using namespace std;

int main()
{
	ListVaccine* vaccine = new ListVaccine();

	Menu* menu = new Menu(vaccine);

	menu->menu();

	system("pause");


	return 0;
}