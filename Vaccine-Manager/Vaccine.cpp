#include "Vaccine.h"
#include <iostream>
#include <string.h>

using namespace std;

unsigned int Vaccine::uiSoLuongVaccine = 0;

Vaccine::Vaccine()
{
	this->cTenVaccine = new char[100];
	this->cTenNhaPhanPhoi = new char[100];
	this->cTenNhaSanXuat = new char[100];
	this->dNgaySanXuat = new Date();
	this->dttDoiTuong = new DoiTuongTiem();
	this->uiGia = 0;
	this->uiSoLuong = 0;
	this->uiSoLuongVaccine++;
}

Vaccine::Vaccine(const Vaccine& vaccine)
{
	this->cTenVaccine = new char[100];
	this->cTenNhaPhanPhoi = new char[100];
	this->cTenNhaSanXuat = new char[100];

	strcpy_s(this->cTenVaccine, 100, vaccine.cTenVaccine);
	strcpy_s(this->cTenNhaSanXuat, 100, vaccine.cTenNhaSanXuat);
	strcpy_s(this->cTenNhaPhanPhoi, 100, vaccine.cTenNhaPhanPhoi);

	this->dNgaySanXuat = new Date(*vaccine.dNgaySanXuat);
	this->dttDoiTuong = new DoiTuongTiem(*vaccine.dttDoiTuong);

	this->uiGia = vaccine.uiGia;
	this->uiSoLuong = vaccine.uiSoLuong;

	this->uiSoLuongVaccine++;
}

Vaccine::Vaccine(char* initTenVaccine, char* initTenNhaSanXuat, char* initTenNhaPhanPhoi,
	Date* initNgaySanXuat, DoiTuongTiem* initDoiTuong, unsigned int initGia, unsigned int initSoLuong)
{
	this->cTenVaccine = new char[100];
	this->cTenNhaPhanPhoi = new char[100];
	this->cTenNhaSanXuat = new char[100];
	this->dNgaySanXuat = new Date();
	this->dttDoiTuong = new DoiTuongTiem();

	strcpy_s(this->cTenVaccine, 100, initTenVaccine);
	strcpy_s(this->cTenNhaSanXuat, 100, initTenNhaSanXuat);
	strcpy_s(this->cTenNhaPhanPhoi, 100, initTenNhaPhanPhoi);
	this->dNgaySanXuat = new Date(*initNgaySanXuat);
	this->dttDoiTuong = new DoiTuongTiem(*initDoiTuong);
	this->uiGia = initGia;
	this->uiSoLuong = initSoLuong;
	this->uiSoLuongVaccine++;
}

Vaccine::~Vaccine()
{
	delete cTenVaccine, cTenNhaSanXuat, cTenNhaPhanPhoi;
	delete dNgaySanXuat;
	delete dttDoiTuong;
	this->uiSoLuongVaccine--;
}

Vaccine* Vaccine::input()
{
	char* initTenVaccine = new char[100],
		* initTenNhaSanXuat = new char[100],
		* initTenNhaPhanPhoi = new char[100];

	do
	{
		cout << "Nhap ten vaccine: ";
		cin.getline(initTenVaccine, 100);
	} while (!this->setTenVaccine(initTenVaccine));

	do
	{
		cout << "Nhap ten nha san xuat: ";
		cin.getline(initTenNhaSanXuat, 100);
	} while (!this->setTenNhaSanXuat(initTenNhaSanXuat));

	do
	{
		cout << "Nhap ten nha phan phoi: ";
		cin.getline(initTenNhaPhanPhoi, 100);
	} while (!this->setTenNhaPhanPhoi(initTenNhaPhanPhoi));

	cout << "Nhap ngay san xuat: " << endl;
	this->dNgaySanXuat->input();

	cout << "Nhap doi tuong tiem vaccine: " << endl;
	cin.ignore();
	this->dttDoiTuong->input();

	cout << "Nhap gia cua vaccine: ";
	cin >> this->uiGia;

	cout << "Nhap so luong trong kho: ";
	cin >> this->uiSoLuong;

	delete[] initTenVaccine, initTenNhaSanXuat, initTenNhaPhanPhoi;

	Vaccine* temp = new Vaccine(*this);
	return temp;
}

void Vaccine::display()
{
	cout << "-------------------";
	cout << "Ten vaccine: ";
	puts(this->cTenVaccine);

	cout << "Nha san xuat: ";
	puts(this->cTenNhaSanXuat);

	cout << "Nha phan phoi: ";
	puts(this->cTenNhaPhanPhoi);

	cout << "Ngay san xuat: ";
	this->dNgaySanXuat->display();

	cout << "Doi tuong tiem chung: " << endl;
	this->dttDoiTuong->display();

	cout << "Gia: " << uiGia << endl << "So luong: " << uiSoLuong << endl;
}

char* Vaccine::getTenVaccine()
{
	return this->cTenVaccine;
}

char* Vaccine::getTenNhaSanXuat()
{
	return this->cTenNhaSanXuat;
}

char* Vaccine::getTenNhaPhanPhoi()
{
	return this->cTenNhaPhanPhoi;
}

Date* Vaccine::getNgaySanXuat()
{
	return this->dNgaySanXuat;
}

DoiTuongTiem* Vaccine::getDoiTuongTiem()
{
	return this->dttDoiTuong;
}

unsigned int Vaccine::getGia()
{
	return this->uiGia;
}

unsigned int Vaccine::getSoLuong()
{
	return this->uiSoLuong;
}

unsigned int Vaccine::getSoLuongVaccine()
{
	return this->uiSoLuongVaccine;
}

int Vaccine::setTenVaccine(char* initTenVaccine)
{
	if (!isStringEmpty(initTenVaccine))
	{
		strcpy_s(this->cTenVaccine, 100, initTenVaccine);
		return 1;
	}

	return 0;
}

int Vaccine::setTenNhaPhanPhoi(char* initNhaPhanPhoi)
{
	if (!isStringEmpty(initNhaPhanPhoi))
	{
		strcpy_s(this->cTenNhaPhanPhoi, 100, initNhaPhanPhoi);
		return 1;
	}

	return 0;
}

int Vaccine::setTenNhaSanXuat(char* initTenNhaSanXuat)
{
	if (!isStringEmpty(initTenNhaSanXuat))
	{
		strcpy_s(this->cTenNhaSanXuat, 100, initTenNhaSanXuat);
		return 1;
	}

	return 0;
}

void Vaccine::setNgaySanXuat(Date* initNgaySanXuat)
{
	delete this->dNgaySanXuat;
	this->dNgaySanXuat = new Date(*initNgaySanXuat);
}

void Vaccine::setDoiTuongTiem(DoiTuongTiem* initDoiTuongTiem)
{
	delete this->dttDoiTuong;
	this->dttDoiTuong = new DoiTuongTiem(*initDoiTuongTiem);
}

void Vaccine::setGia(unsigned int initGia)
{
	this->uiGia = initGia;
}

void Vaccine::setSoLuong(unsigned int initSoLuong)
{
	this->uiSoLuong = initSoLuong;
}

bool Vaccine::isStringEmpty(char* s)
{
	if (strcmp(s, "") == 0)
		return 1;

	return 0;
}