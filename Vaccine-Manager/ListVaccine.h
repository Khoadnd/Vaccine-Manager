#pragma once
#include "Vaccine.h"
#include <vector>
class ListVaccine
{
private:
	std::vector<Vaccine>* vaccine;

public:
	ListVaccine();
	~ListVaccine();

	void display(int = -1);
	void displayNameOfVaccine();

	void input();

	void sell();
	void buy();

	void delVac();

	bool isEmpty();
};

