#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#ifndef NGUOIDUNG_H
#define NGUOIDUNG_H

class NguoiDung {
private:
public:
	char MasoNguoiDung[5];
	double sCMND;
	char tenNguoiDung[30];
	char ngaySinh[15];
	char diaChi[50];
	char tenDangNhap[30];
	char MatKhau[20];
	bool trangThai = 1;
	double chucVu;
	int dem = 0;
	void doc(fstream&);
	void ghi(fstream&);
	void nhap();
};


#endif