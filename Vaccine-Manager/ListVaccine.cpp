#include "ListVaccine.h"
#include "Vaccine.h"
#include <iostream>

using namespace std;

ListVaccine::ListVaccine()
{
	vaccine = new vector<Vaccine>(0);
}

ListVaccine::~ListVaccine()
{
	delete vaccine;
}

void ListVaccine::display()
{
	vector<Vaccine>::iterator it;

	for (it = vaccine->begin(); it != vaccine->end(); it++)
		it->display();
}

void ListVaccine::input()
{
	char exit = 'y';
	Vaccine* temp = new Vaccine();
	do
	{
		cout << "Nhap vaccine? (y/n) ";
		cin >> exit;
		cin.ignore();

		if (exit == 'n')
			break;

		vaccine->push_back(*temp->input());
	} while (true);
}

void ListVaccine::sell()
{

}

void ListVaccine::buy()
{

}