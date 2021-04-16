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

void ListVaccine::display(int ID)
{
	vector<Vaccine>::iterator it;

	if (ID != -1)
	{
		it = vaccine->begin();
		it += ID;
		it->display();
	}
	else
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

void ListVaccine::displayNameOfVaccine()
{
	if (this->vaccine->empty())
	{
		cout << "Khong co vaccine trong kho!" << endl;
		return;
	}

	vector<Vaccine>::iterator it; int i = 0;

	for (it = vaccine->begin(); it != vaccine->end(); it++)
	{
		cout << "(ID: " << i++ << ") ";
		puts(it->getTenVaccine());
	}
}

void ListVaccine::sell()
{
	if (this->vaccine->empty())
	{
		cout << "Chua co vaccine trong kho!" << endl;
		return;
	}

	int iChoice;
	this->displayNameOfVaccine();
	cout << "Nhap ID ban can mua: ";
	cin >> iChoice;

	vector<Vaccine>::iterator _vaccine = vaccine->begin();

	if (iChoice > _vaccine[0].getSoLuong() - 1)
	{
		cout << "Khong hop le" << endl;
		return;
	}

	_vaccine += iChoice;

	cout << "Don gia: " << _vaccine->getGia() << "\nSo luong con trong kho: "
		<< _vaccine->getSoLuong() << endl;

	int soLuong;

	cout << "Nhap so luong can mua: ";
	cin >> soLuong;

	if (soLuong > _vaccine->getSoLuong() || soLuong < 0)
	{
		cout << "Khong hop le!";
		return;
	}

	_vaccine->setSoLuong(_vaccine->getSoLuong() - soLuong);

	cout << "Thanh tien: " << _vaccine->getGia() * soLuong << endl;
}

void ListVaccine::buy()
{
	if (this->vaccine->empty())
	{
		this->input();
		return;
	}

	int iChoice;
	this->displayNameOfVaccine();
	cout << "Nhap ID mua them (-1 de mua moi): ";
	cin >> iChoice;

	vector<Vaccine>::iterator _vaccine = vaccine->begin();

	if (iChoice > _vaccine[0].getSoLuong() - 1)
	{
		cout << "Khong hop le" << endl;
		return;
	}

	if (iChoice == -1)
	{
		cout << "Nhap them vaccine: " << endl;
		this->input();
	}
	else
	{
		_vaccine += iChoice;
		int soLuong;
		cout << "Nhap so luong mua: ";
		cin >> soLuong;

		if (soLuong <= 0)
		{
			cout << "Khong hop le" << endl;
			return;
		}

		_vaccine->setSoLuong(_vaccine->getSoLuong() + soLuong);
		cout << "Thanh tien: " << _vaccine->getGia() * soLuong << endl;
	}
}

bool ListVaccine::isEmpty()
{
	if (this->vaccine->empty())
		return 1;

	return 0;
}

void ListVaccine::delVac()
{
	if (this->vaccine->empty())
	{
		cout << "Chua co vaccine trong kho!" << endl;
		return;
	}

	int iChoice;
	this->displayNameOfVaccine();
	
	cout << "Nhap ID vaccine can xoa: ";
	cin >> iChoice;

	vector<Vaccine>::iterator _vaccine = vaccine->begin();

	if (iChoice > _vaccine[0].getSoLuong() - 1)
	{
		cout << "Khong hop le" << endl;
		return;
	}

	_vaccine[0].setSoLuongVaccine(_vaccine[0].getSoLuongVaccine() - 1);

	this->vaccine->erase(this->vaccine->begin() + iChoice);
}