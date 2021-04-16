#pragma once

static const char* _BloodType[] = { "O-", "O+", "A-" ,"A+", "B-", "B+", "AB+", "AB-", "O", "A", "B", "AB" };
static const int _NumberOBloodType = 12;
static const char* _Sex[] = { "f", "F", "m", "M", "n", "N", "nu", "Nu", "nam", "Nam", "A", "all", "All", "ALL", "male", "Male", "female", "Female" };
static const int _NumberOSex = 14;

class DoiTuongTiem
{
private:
	char* gioiTinh;
	char* nhomMau;
	unsigned int doTuoi;

public:
	DoiTuongTiem(char*, char*, unsigned int);
	DoiTuongTiem(const DoiTuongTiem&);
	DoiTuongTiem();
	~DoiTuongTiem();

	void input();
	void display();

	char* getGioiTinh();
	char* getNhomMau();
	unsigned int getDoTuoi();

	int setGioiTinh(char*);
	int setNhomMau(char*);
	int setDoTuoi(unsigned int);

	bool isNhomMau(char* = {});
	bool isGioiTinh(char* = {});
};

