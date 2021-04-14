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

	void display();
	void input();

	void sell();
	void buy();
};

