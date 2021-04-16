#pragma once
#include "Date.h"
#include "DoiTuongTiem.h"

class Vaccine
{
private:
	char* cTenVaccine;
	char* cTenNhaSanXuat;
	char* cTenNhaPhanPhoi;
	Date* dNgaySanXuat;
	DoiTuongTiem* dttDoiTuong;
	unsigned int uiGia;
	unsigned int uiSoLuong;
	static unsigned int uiSoLuongVaccine;

public:
	Vaccine(char*, char*, char*, Date*, DoiTuongTiem*, unsigned int, unsigned int);
	Vaccine(const Vaccine&);
	Vaccine();
	~Vaccine();

	Vaccine* input();
	void display();

	char* getTenVaccine();
	char* getTenNhaSanXuat();
	char* getTenNhaPhanPhoi();
	Date* getNgaySanXuat();
	DoiTuongTiem* getDoiTuongTiem();
	unsigned int getGia();
	unsigned int getSoLuong();

	unsigned int getSoLuongVaccine();
	void setSoLuongVaccine(unsigned int);

	int setTenVaccine(char*);
	int setTenNhaSanXuat(char*);
	int setTenNhaPhanPhoi(char*);
	void setNgaySanXuat(Date*);
	void setDoiTuongTiem(DoiTuongTiem*);
	int setGia(unsigned int);
	int setSoLuong(unsigned int);

	bool isStringEmpty(char*);

};

