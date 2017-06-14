#include "NguoiDung.h"
using namespace std;
void NguoiDung::nhap() {
	do {
		cin.clear();
		//cin.ignore(80, '\n');
		cout << "Nhap so CMND :";
	} while (!(cin >> sCMND) || sCMND != (int)sCMND);
	cin.ignore();

	do {
		cout << "Nhap Ho Ten: "; cin.getline(tenNguoiDung, 30);
		if (strcmp(tenNguoiDung, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
	} while (strcmp(tenNguoiDung, "") == 0);

	do {
		cout << "Nhap Ngay Sinh: "; cin.getline(ngaySinh, 30);
		if (strcmp(ngaySinh, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
	} while (strcmp(ngaySinh, "") == 0);
	do {
		cout << "Nhap Dia Chi: "; cin.getline(diaChi, 15);
		if (strcmp(diaChi, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
	} while (strcmp(diaChi, "") == 0);
	do {
		cout << "Nhap Ten Tai Khoan: "; cin.getline(tenDangNhap, 30);
		if (strcmp(tenDangNhap, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
	} while (strcmp(tenDangNhap, "") == 0);

	do {
		cout << "Nhap Mat khau: "; cin.getline(MatKhau, 30);
		if (strcmp(MatKhau, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
	} while (strcmp(MatKhau, "") == 0);
	cout << "Nhap Ma Chuc Vu (1: Adminstration , 2: Thu Thu , 3:Doc Gia):";
	while (!(cin >> chucVu) || chucVu != (int)chucVu) {
		cin.clear();
		cin.ignore();
		cout << "Nhap Ma Chuc Vu (1: Adminstration , 2: Thu Thu , 3:Doc Gia):";
	};
};
void NguoiDung::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(NguoiDung));
}
void NguoiDung::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(NguoiDung));
}