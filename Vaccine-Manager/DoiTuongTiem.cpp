#include "DoiTuongTiem.h"
#include <iostream>
#include "Vaccine.h"

using namespace std;

DoiTuongTiem::DoiTuongTiem(char* initGioiTinh, char* initNhomMau, 
	unsigned int initDoTuoi)
{
	this->gioiTinh = new char[5];
	this->nhomMau = new char[5];

	strcpy_s(this->gioiTinh, 5, initGioiTinh);
	strcpy_s(this->nhomMau, 5, initNhomMau);
	this->doTuoi = initDoTuoi;
}

DoiTuongTiem::DoiTuongTiem(const DoiTuongTiem& initDoiTuong)
{
	this->gioiTinh = new char[5];
	this->nhomMau = new char[5];

	strcpy_s(this->gioiTinh, 5, initDoiTuong.gioiTinh);
	strcpy_s(this->nhomMau, 5, initDoiTuong.nhomMau);
	this->doTuoi = initDoiTuong.doTuoi;
}

DoiTuongTiem::DoiTuongTiem()
{
	this->gioiTinh = new char[5];
	this->nhomMau = new char[5];
	this->doTuoi = 0;
}

DoiTuongTiem::~DoiTuongTiem()
{
	delete[] this->gioiTinh, this->nhomMau;
}

void DoiTuongTiem::input()
{
	char* initNhomMau = new char[5],
		* initGioiTinh = new char[5];

	unsigned int initdoTuoi = 0;

	do
	{
		cout << "Nhap nhom mau: ";
		cin.getline(initNhomMau, 5);
	} while (!setNhomMau(initNhomMau));

	do
	{
		cout << "Nhap gioi tinh: ";
		cin.getline(initGioiTinh, 5);
	} while (!setGioiTinh(initGioiTinh));

	cout << "Nhap do tuoi: ";
	cin >> this->doTuoi;

	delete[] initNhomMau, initGioiTinh;
}

void DoiTuongTiem::display()
{
	cout << "Nhom mau: ";
	puts(this->nhomMau);
	cout << "Gioi tinh: ";
	puts(this->gioiTinh);
	cout << "Do tuoi: " << this->doTuoi << endl;
}

char* DoiTuongTiem::getGioiTinh()
{
	return this->gioiTinh;
}

char* DoiTuongTiem::getNhomMau()
{
	return this->nhomMau;
}

unsigned int DoiTuongTiem::getDoTuoi()
{
	return this->doTuoi;
}

int DoiTuongTiem::setGioiTinh(char* initGioiTinh)
{
	if (!Vaccine().isStringEmpty(initGioiTinh))
		if (this->isGioiTinh(initGioiTinh))
		{
			strcpy_s(this->gioiTinh, 5, initGioiTinh);
			return 1;
		}

	return 0;
}

int DoiTuongTiem::setNhomMau(char* initNhomMau)
{
	if (!Vaccine().isStringEmpty(initNhomMau))
		if (this->isNhomMau(initNhomMau))
		{
			strcpy_s(this->nhomMau, 5, initNhomMau);
			return 1;
		}

	return 0;
}

void DoiTuongTiem::setDoTuoi(unsigned int initTuoi)
{
	this->doTuoi = initTuoi;
}

bool DoiTuongTiem::isNhomMau(char* nhomMau)
{
	for (int i = 0; i < _NumberOBloodType; i++)
		if (strcmp(nhomMau, _BloodType[i]) == 0)
			return 1;
	
	return 0;
}

bool DoiTuongTiem::isGioiTinh(char* gioiTinh)
{
	for (int i = 0; i < _NumberOSex; i++)
		if (strcmp(gioiTinh, _Sex[i]) == 0)
			return 1;

	return 0;
}