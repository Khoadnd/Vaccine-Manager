#pragma once
#include "ListVaccine.h"
class Menu
{
private:
	ListVaccine* vaccine;

public:
	Menu(ListVaccine* _vaccine = NULL) : vaccine(_vaccine) {}
	~Menu()
	{
		delete this->vaccine;
	}

	void menu();
	void displayMenu();
};

