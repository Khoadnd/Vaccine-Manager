#pragma once
class Date
{
private:
	int iDay;
	int iMonth;
	int iYear;

public:
	Date(int = 0, int = 0, int = 0);
	Date(const Date&);
	~Date();

	void input();
	void display();

	bool setDay(int);
	bool setMonth(int);
	bool setYear(int);
	bool setDate(Date = {0, 0, 0});

	int getDay();
	int getMonth();
	int getYear();

	bool isLeap(int);
	bool isLegit(Date);
};

