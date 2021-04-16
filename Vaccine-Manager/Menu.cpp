#include "Menu.h"
#include <iostream>

using namespace std;

void Menu::displayMenu()
{
	cout << "------------------\n";
	cout << "-------Menu-------\n";
	cout << "------------------\n";
	cout << "1) Xem cac vaccine co trong kho\n";
	cout << "2) Mua/nhap them vaccine\n";
	cout << "3) Ban vaccine\n";
	cout << "4) Xem thong tin vaccine\n";
	cout << "5) Xoa vaccine\n";
	cout << "0) Thoat\n\n";
	cout << "Nhap lua chon cua ban: ";
}

void Menu::menu()
{
	int iChoice;

	do
	{
		this->displayMenu();
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			this->vaccine->displayNameOfVaccine();		
			break;

		case 2:
			this->vaccine->buy();
			break;

		case 3:
			this->vaccine->sell();
			break;

		case 4:
		{
			if (this->vaccine->isEmpty())
			{
				cout << "Khong co vaccine trong kho" << endl;
				break;
			}
			int ID;
			this->vaccine->displayNameOfVaccine();
			cout << "Nhap ID vaccine can xem (-1 de xem tat ca): ";
			cin >> ID;
			this->vaccine->display(ID);
		}
			break;

		case 5:
		{
			this->vaccine->delVac();
		}
			break;

		case 0:
			return;

		default:
			cout << "Khong hop le!";
			break;
		}

		system("pause");
		system("cls");
	} while (true);
}