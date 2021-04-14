#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(int initDay, int initMonth, int initYear)
{
	this->iDay = initDay;
	this->iMonth = initMonth;
	this->iYear = initYear;
}

Date::Date(const Date& initDate)
{
	this->iDay = initDate.iDay;
	this->iMonth = initDate.iMonth;
	this->iYear = initDate.iYear;
}

Date::~Date()
{

}

bool Date::setDay(int initDay)
{
	if (initDay > 31 || initDay < 0)
		return 0;

	this->iDay = initDay;

	return 1;
}

bool Date::setMonth(int initMonth)
{
	if (initMonth > 12 || initMonth < 0)
		return 0;

	this->iMonth = initMonth;

	return 1;
}

bool Date::setYear(int initYear)
{
	if (initYear < 0)
		return 0;

	this->iYear = initYear;

	return 1;
}



bool Date::setDate(Date initDate)
{
	bool bSuccess = 1;

	if (!this->setDay(initDate.iDay))
		bSuccess = 0;

	if (!this->setMonth(initDate.iMonth))
		bSuccess = 0;

	if (!this->setYear(initDate.iYear))
		bSuccess = 0;

	return bSuccess;
}

void Date::display()
{
	cout << this->iDay << '/' << this->iMonth << '/' << this->iYear << endl;
}

bool Date::isLeap(int year)
{
	if (year % 400 == 0)
		return 1;

	if ((year % 4 == 0) && (year % 100 != 0))
		return 1;

	return 0;
}

bool Date::isLegit(Date date)
{
	int iDayLookUp[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeap(date.iYear))
	{
		iDayLookUp[1] = 29;
	}

	if (date.iDay > iDayLookUp[date.iMonth - 1])
		return 0;

	return 1;
}

void Date::input()
{
	int initDay, initMonth, initYear;

	do
	{
		do
		{
			cout << "Nhap Day: ";
			cin >> initDay;
		} while (!this->setDay(initDay));

		do
		{
			cout << "Nhap Month: ";
			cin >> initMonth;
		} while (!this->setMonth(initMonth));

		do
		{
			cout << "Nhap Year: ";
			cin >> initYear;
		} while (!this->setYear(initYear));
	} while (!isLegit(*this));
}

int Date::getDay()
{
	return this->iDay;
}

int Date::getMonth()
{
	return this->iMonth;
}

int Date::getYear()
{
	return this->iYear;
}