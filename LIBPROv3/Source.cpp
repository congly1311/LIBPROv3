#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#pragma warning(disable:4996)
using namespace std;
struct ChucVu{
	int admin;
	int thuthu;
	int docgia;
};
class YeuCau{
public:
	int stt;
	int mayc; //1. muon sach; 2. tra sach
	char ID[13];
	char tenND[30];
	char IDsach[13];
	int IDmuon;
	char tensach[30];
	bool c = 0; //0 - degree, 1 - agree
	void ghi(fstream&);
	void doc(fstream&);
};

void YeuCau::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(YeuCau));
}
void YeuCau::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(YeuCau));
}
int TruyXuatYeuCau(YeuCau v[]) {
	fstream inFile("YeuCau.DAT", ios::in);
	int dem = 0;
	while (!inFile.eof()) {
		v[dem].doc(inFile);
		dem++;
	}
	inFile.close();
	return dem - 1;
}
char gettime() {
	time_t rawtime;
	struct tm *info;
	char buffer[50];

	time(&rawtime);

	info = localtime(&rawtime);

	strftime(buffer, 80, "%x - %I:%M%p", info);
	return buffer[50];
}
class ThongBao {
public:
	int IDthongbao;
	char IDgui[13];
	char IDnhan[13];
	char time[50];
	char tieude[100];
	char noidung[1000];
	void ghi(fstream&);
	void doc(fstream&);
	void nhap();
};
void ThongBao::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(ThongBao));
}
void ThongBao::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(ThongBao));
}
class Sach {
public:
	char ID[13];
	char tensach[30];
	char tentacgia[30];
	char ngonngu[20];
	char theloai[20];
	bool trangthai = 1;//chua muon
	float danhgia = 0; // thang 10, bang tong diem danh gia chia so luot danh gia;
	int soluotdanhgia = 0;
	void doc(fstream&);
	void ghi(fstream&);
	void nhap();
};
void Sach::nhap() {
	cout << "Nhap ma so Sach: "; cin.getline(ID,13);
	cout << "Nhap ten sach: "; cin.getline(tensach, 30);
	cout << "Nhap ten tac gia: "; cin.getline(tentacgia, 30);
	cout << "Ngon ngu: "; cin.getline(ngonngu, 20);
	cout << "The loai: "; cin.getline(theloai, 20);
};
void Sach::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(Sach));
}
void Sach::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(Sach));
}
class MuonSach :public Sach {
public:
	int ID;
	char IDsach[13];
	char tensach[30];
	char tentacgia[30];
	char ngonngu[20];
	char theloai[20];
	bool trangthai = 1;//chua muon
	float danhgia = 0; // thang 10, bang tong diem danh gia chia so luot danh gia;

    char IDmuon[13];
	char ngMuon[30];
	int ngayMuon[3]; // dinh dang ngay thang nam.
	int thoigian[3]; //dinh dang gio phu giay
	int ngayTra[3];
	void doc(fstream&);
	void ghi(fstream&);
};
void MuonSach::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(MuonSach));
}
void MuonSach::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(MuonSach));
}
class NguoiDung {
private:
public:
	char ID[13];
	char sCMND[13];
	char tenNguoiDung[30];
	char ngaySinh[15];
	char diaChi[50];
	char tenDangNhap[30];
	char MatKhau[20];
	bool trangThai = 1;
	ChucVu chucVu;
	int dem = 0;
	void doc(fstream&);
	void ghi(fstream&);
	void nhap();
};

void NguoiDung::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(NguoiDung));
}
void NguoiDung::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(NguoiDung));
}
class Quyen {
public:
	unsigned int stt;
	bool DocGia = 0;
	bool ThuThu = 0;
	bool Admin = 0;
	char tenQuyen[100];
	void doc(fstream&);
	void ghi(fstream&);
};
void Quyen::ghi(fstream &ofs) {
	ofs.write(reinterpret_cast< const char * > (this), sizeof(NguoiDung));
}
void Quyen::doc(fstream &ifs) {
	ifs.read(reinterpret_cast< char * > (this), sizeof(NguoiDung));
}
int TruyXuatNgDung(NguoiDung v[]) {
	fstream inFile("UserData.DAT", ios::in);
	int dem = 0;
	while (!inFile.eof()) {
		v[dem].doc(inFile);
		dem++;
	}
	/*
	for (int i=0; i<dem-1; i++){
	cout << "sCMND: " << v[i].sCMND << endl;
	cout << "tenNguoiDung: " << v[i].tenNguoiDung << endl;
	cout << "ngaySinh: " << v[i].ngaySinh << endl;
	cout << "diaChi: " << v[i].diaChi << endl;
	cout << "Ten Tai khoan: " << v[i].tenDangNhap <<endl;
	cout << "Chuc vu: ";
	if (v[i].chucVu == 1) cout << "Administration" <<endl;
	else if (v[i].chucVu == 2) cout << "Thu Thu" << endl;
	else cout << "Doc Gia" << endl;
	}
	*/
	inFile.close();
	return dem - 1;
}
int TruyXuatSach(Sach v[]) {
	fstream inFile("Sach.DAT", ios::in);
	int dem = 0;
	while (!inFile.eof()) {
		v[dem].doc(inFile);
		dem++;
	}
	inFile.close();
	return dem - 1;
}
int TruyXuatMuonSach(MuonSach v[]) {
	fstream inFile("MuonSach.DAT", ios::in);
	int dem = 0;
	while (!inFile.eof()) {
		v[dem].doc(inFile);
		dem++;
	}
	inFile.close();
	return dem - 1;
}
int TruyXuatThongBao(ThongBao v[]) {
	fstream inFile("ThongBao.DAT", ios::in);
	int dem = 0;
	while (!inFile.eof()) {
		v[dem].doc(inFile);
		dem++;
	}
	inFile.close();
	return dem - 1;
}
int TruyXuatQuyen(Quyen v[]) {
	fstream inFile("Quyen.DAT", ios::in);
	int dem = 0;
	while (!inFile.eof()) {
		v[dem].doc(inFile);
		dem++;
	}
	inFile.close();
	return dem - 1;
}
void CapNhatSach(Sach s[]) {
	double m;
	fstream outFile("Sach.DAT", ios::app);
	cout << "Nhap so luong sach can them: "; cin >> m;
	while (cin.bad() || m < 0 || m != (int)m) {
		cin.clear();
		fflush(stdin);
		cout << "Nhap so luong sach can them: "; cin >> m;
	};
	cin.ignore();
	cout << "==================================================" << endl;
	for (int i = 0; i<m; i++) {
		cout << "Nhap Du lieu Sach thu " << i + 1 << " :" << endl;
		s[i].nhap();
		s[i].ghi(outFile);
		cout << endl;
	}
	outFile.close();
}
void inmk(char pw[20]) {
	int pas = 0;
	char c;
	while (c = getch()) {
		if (c == '\n' || c == '\r') {
			cout << "\n";
			break;
		}
		else if (c == '\b') {
			cout << "\b \b"; pas--;
		}
		else {
			cout << '*';
			pw[pas] = c;
			pas++;
		}
	}
	for (int i = (pas); i < 20; i++)pw[i] = '\0';
}
int timkiemchuoi(char a[], char b[]) {
	char c[100], d[100];
	char *ret;
	strlwr(strcpy(c, a));
	strlwr(strcpy(d, b));

	ret = strstr(c, d);
	if (ret == NULL) return 0;
	else return 1;
}

void ThongBaoTuDong(NguoiDung ngDung[], int hientai, ThongBao thongbao[], int ms, MuonSach muonsach[]) {
	int sl = TruyXuatThongBao(thongbao);
	int m = TruyXuatNgDung(ngDung);
	int sls = TruyXuatMuonSach(muonsach);
	//thongbao[sl].IDgui = ngDung[hientai].chucVu;
	thongbao[sl].IDthongbao = sl + 1;
	//thongbao[sl].nhap();
	time_t rawtime;
	struct tm *info;
	char buffer[50];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%x - %I:%M%p", info);
	strcpy(thongbao[sl].time, buffer);
	strcpy(thongbao[sl].IDgui, "-1");
	if (ms == 1) {  // thong bao chao mung
		strcpy(thongbao[sl].IDnhan, ngDung[m - 1].sCMND);
		strcpy(thongbao[sl].tieude, "Chao mung ban den voi thu vien cua chung toi");
		strcpy(thongbao[sl].noidung, "Xin chao ");
		strcat(thongbao[sl].noidung, ngDung[m - 1].tenNguoiDung);
		strcat(thongbao[sl].noidung, ". Chung toi rat vui vi ban da den thu vien cua chung toi. Neu co bat ky thac mac nao xin hay lien he voi thu thu de duoc ho tro");
	}
	//else if (ms == 2) { // thong bao muon sach thanh cong
	//	strcpy(thongbao[sl].IDnhan,ngDung[hientai].sCMND);
	//	strcpy(thongbao[sl].tieude, "Muon sach thanh cong!");
	//	strcpy(thongbao[sl].noidung, "Chuc mung ban da muon thanh cong sach ");
	//	strcat(strcat(strcat(thongbao[sl].noidung, muonsach[sls - 1].tensach), " vao luc "), buffer);

	//	strcat(thongbao[sl].noidung, ". Ban phai tra sach muon nhat la sau 15 ngay ke tu ngay muon sach. Xin cam on. ");
	//}
	else if (ms == 3) { // thong bao tra sach thanh cong
		strcpy(thongbao[sl].IDnhan, ngDung[hientai].sCMND);
		strcpy(thongbao[sl].tieude, "Tra sach thanh cong!");
		strcpy(thongbao[sl].noidung, "Ban da tra thanh cong sach ");
		strcat(strcat(strcat(thongbao[sl].noidung, muonsach[sls - 1].tensach), " vao luc "), buffer);
		strcat(thongbao[sl].noidung, ". Cam on ban da tuog tac voi thu vien cua chung toi. ");
	}
	else if (ms == 4) {  // thong bao Doi mat khau
		strcpy(thongbao[sl].IDnhan, ngDung[m - 1].sCMND);
		strcpy(thongbao[sl].tieude, "Thong bao doi mat khau");
		strcpy(thongbao[sl].noidung, "Xin chao ");
		strcat(thongbao[sl].noidung, ngDung[m - 1].tenNguoiDung);
		strcat(thongbao[sl].noidung, ". De nghi ban doi mat khau trong lan dang nhap dau tien. Moi thac mac xin lien he admin.");
	}
	else cout << "";
	fstream outFile("ThongBao.DAT", ios::app);
	thongbao[sl].ghi(outFile);
	outFile.close();
}
void ThongBaoTuDong(NguoiDung ngDung[], ThongBao thongbao[], MuonSach muonsach[], int hientai, char tensach[]){
	int sl = TruyXuatThongBao(thongbao);
	int m = TruyXuatNgDung(ngDung);
	int sls = TruyXuatMuonSach(muonsach);
	//thongbao[sl].IDgui = ngDung[hientai].chucVu;
	thongbao[sl].IDthongbao = sl + 1;
	//thongbao[sl].nhap();
	time_t rawtime;
	struct tm *info;
	char buffer[50];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%x - %I:%M%p", info);
	strcpy(thongbao[sl].time, buffer);
	strcpy(thongbao[sl].IDgui, "-1");
	strcpy(thongbao[sl].IDnhan, ngDung[hientai].sCMND);
	strcpy(thongbao[sl].tieude, "Muon sach thanh cong!");
	strcpy(thongbao[sl].noidung, "Chuc mung ban da muon thanh cong sach ");
	strcat(strcat(strcat(thongbao[sl].noidung, tensach), " vao luc "), buffer);
	strcat(thongbao[sl].noidung, ". Ban phai tra sach muon nhat la sau 15 ngay ke tu ngay muon sach. Xin cam on. ");
	fstream outFile("ThongBao.DAT", ios::app);
	thongbao[sl].ghi(outFile);
	outFile.close();
}
void ShowMenu(NguoiDung ngDung[], int chucvu, Quyen quyen[], int m){

	system("cls");
	if (m == 1 || chucvu == 1){
		cout << " ________________________________________________________________" << endl;
		cout << "|               Ban dang dang nhap voi vai tro Admin             | " << endl;
		cout << "|________________________________________________________________|" << endl;
		cout << "|             ################ Menu #################            |" << endl;
		cout << "|________________________________________________________________|" << endl;

		for (int k = 0; k<23; k++) {
			if (quyen[k].Admin == 1) {
				cout << setw(5) << left << "|";
				cout << setw(2) << right << quyen[k].stt << ". "
					<< setw(40) << left << quyen[k].tenQuyen
					<< setw(17) << right << "|" << endl;
			}
		}
		cout << "|________________________________________________________________|" << endl;
	}
	else if (m == 2){
		cout << " ________________________________________________________________" << endl;
		cout << "|              Ban dang dang nhap voi vai tro Thu thu            | " << endl;
		cout << "|________________________________________________________________|" << endl;
		cout << "|             ################ Menu #################            |" << endl;
		cout << "|________________________________________________________________|" << endl;

		for (int k = 0; k<23; k++) {
			if (quyen[k].ThuThu == 1) {
				cout << setw(5) << left << "|";
				cout << setw(2) << right << quyen[k].stt << ". "
					<< setw(40) << left << quyen[k].tenQuyen
					<< setw(17) << right << "|" << endl;
			}
		}
		cout << "|________________________________________________________________|" << endl;
	}
	else {
		cout << " ________________________________________________________________" << endl;
		cout << "|              Ban dang dang nhap voi vai tro Doc gia             | " << endl;
		cout << "|________________________________________________________________|" << endl;
		cout << "|             ################ Menu #################            |" << endl;
		cout << "|________________________________________________________________|" << endl;

		for (int k = 0; k<23; k++) {
			if (quyen[k].DocGia == 1) {
				cout << setw(5) << left << "|";
				cout << setw(2) << right << quyen[k].stt << ". "
					<< setw(40) << left << quyen[k].tenQuyen
					<< setw(17) << right << "|" << endl;
			}
		}
		cout << "|________________________________________________________________|" << endl;
	}
}
int Chucnang(int hientai, NguoiDung ngDung[], int quyen, int &m, Quyen q[], char tdn[], Sach sach[], MuonSach muonsach[], ThongBao thongbao[], YeuCau yc[]) {

	//#######Quyen 0. Them Nguoi dung#######################################################

	if (quyen == 0) {
		system("cls");
		cout << " ________________________________________" << endl;
		cout << "|              THEM NGUOI DUNG           |" << endl;
		cout << "|________________________________________|" << endl;
		char a;
		double sl;
		int ktra = 0;
		
		cout << "Nhap so luong nguoi dung: "; cin >> sl;
		while (cin.bad() || sl < 0 || sl != (int)sl) {
			cin.clear();
			fflush(stdin);
			cout << "Nhap so luong nguoi dung: "; cin >> sl;
		} 
		cin.ignore();
		cout << endl;
		for (int i = 0; i < sl; i++) {
			m = TruyXuatNgDung(ngDung);
			ktra = 0;
			cout << "Nhap thong tin nguoi thu " << i + 1 << " : " << endl;
			do {
				cout << "Nhap so CMND: "; cin.getline(ngDung[m].sCMND, 13);
				if (strcmp(ngDung[m].sCMND, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
			} while (strcmp(ngDung[m].sCMND, "") == 0);

			for (int j = 0; j < m; j++) {
				if (strcmp(ngDung[m].sCMND, ngDung[j].sCMND)==0) {
					cout << "Da ton tai so CMND nay !!!" << endl;
					cout << "Tai khoan co vai tro hien tai la: ";
					if (ngDung[j].chucVu.admin == 1) cout << "Admin, ";
					if (ngDung[j].chucVu.thuthu == 1) cout << "Thu thu, ";
					if (ngDung[j].chucVu.docgia == 1) cout << "Doc gia, ";
					cout << endl;
					cout << "Ban co muon thay doi vai tro khong? (Y/N): "; cin >> a; cin.ignore();
					if (a == 'Y' || a == 'y'){
						cout << "Nhap vai tro moi (A T D): ";
						cin >> ngDung[j].chucVu.admin;
						cin >> ngDung[j].chucVu.thuthu;
						cin >> ngDung[j].chucVu.docgia;
						fstream out1File("UserData.DAT", ios::out);
						for (int d = 0; d < m; d++){
							ngDung[d].ghi(out1File);
						}
						out1File.close();
					}
					
					ktra = 1;
					break;
				}
			}
			
				
			
			if (ktra != 1) {

				do {
					cout << "Nhap Ho Ten: "; cin.getline(ngDung[m].tenNguoiDung, 30);
					if (strcmp(ngDung[m].tenNguoiDung, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
				} while (strcmp(ngDung[m].tenNguoiDung, "") == 0);

				do {
					cout << "Nhap Ngay Sinh: "; cin.getline(ngDung[m].ngaySinh, 30);
					if (strcmp(ngDung[m].ngaySinh, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
				} while (strcmp(ngDung[m].ngaySinh, "") == 0);
				do {
					cout << "Nhap Dia Chi: "; cin.getline(ngDung[m].diaChi, 15);
					if (strcmp(ngDung[m].diaChi, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
				} while (strcmp(ngDung[m].diaChi, "") == 0);
				int kt=0;
				do {
					kt = 0;
					cout << "Nhap Ten Tai Khoan: "; cin.getline(ngDung[m].tenDangNhap, 30);
					if (strcmp(ngDung[m].tenDangNhap, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
					for (int j = 0; j < m; j++){
						if (strcmp(ngDung[m].tenDangNhap, ngDung[j].tenDangNhap) == 0)
						{
							cout << "Ten nay da co nguoi su dung!!!" << endl;
							kt = 1;
							break;
						}
					}
				} while (strcmp(ngDung[m].tenDangNhap, "") == 0||kt==1);
				do {
					cout << "Nhap Mat khau: "; cin.getline(ngDung[m].MatKhau, 30);
					if (strcmp(ngDung[m].MatKhau, "") == 0) cout << "Khong Duoc Bo trong Phan Nay!!!" << endl;
				} while (strcmp(ngDung[m].MatKhau, "") == 0);
				cout << "Nhap Ma Chuc Vu (A T D): ";
				cin >> ngDung[m].chucVu.admin;
				cin >> ngDung[m].chucVu.thuthu;
				cin >> ngDung[m].chucVu.docgia;
				cin.ignore();
				fstream outFile("UserData.DAT", ios::app);
				ngDung[m].ghi(outFile);
				outFile.close();
				ThongBaoTuDong(ngDung, hientai, thongbao, 1, muonsach);
				ThongBaoTuDong(ngDung, hientai, thongbao, 4, muonsach);

				cout << endl;
			}
		}
		cout << "Them hoan tat!" << endl;
		Sleep(1311);
	}

	//#######Quyen 1. Khoa nguoi dung#######################################################

	else if (quyen == 1) {
		system("cls");
		cout << " ________________________________________" << endl;
		cout << "|              KHOA NGUOI DUNG           |" << endl;
		cout << "|________________________________________|" << endl;
		char cm[13];
		int i;
		int tt = 0;
		cout << "Nhap so CMND: "; cin.getline(cm,13);
		for (i = 0; i < m; i++) {
			if (strcmp(cm, ngDung[i].sCMND)==0) {
				ngDung[i].trangThai = 0;
				cout << "\n";
				cout << "Khoa thanh cong!" << endl;
				tt = 1;
			}
		}
		fstream outFile("UserData.DAT", ios::out);
		for (int k = 0; k < m; k++) {
			ngDung[k].ghi(outFile);
		}
		if (tt == 0) cout << "Khong tim thay nguoi nay!" << endl;
		outFile.close();
		Sleep(1311);
	}

	//#######Quyen 2. Mo Khoa nguoi dung#######################################################

	else if (quyen == 2) {
		system("cls");
		cout << " ________________________________________" << endl;
		cout << "|           MO KHOA NGUOI DUNG           |" << endl;
		cout << "|________________________________________|" << endl;
		char cm[13];
		int i;
		int tt = 0;
		cout << "Nhap so CMND: "; cin >> cm; cin.ignore();
		for (i = 0; i < m; i++) {
			if (strcmp(cm, ngDung[i].sCMND)==0) {
				ngDung[i].trangThai = 1;
				cout << "Mo Khoa thanh cong!" << endl;
				tt = 1;
			}
		}
		fstream outFile("UserData.DAT", ios::out);
		for (int k = 0; k < m; k++) {
			ngDung[k].ghi(outFile);
		}
		if (tt == 0) cout << "Khong tim thay nguoi nay!" << endl;
		outFile.close();
		Sleep(1311);
	}

	//#######Quyen 3. Quan ly quyen.########################################################

	else if (quyen == 3) {           //
		system("cls");
		cout << " _________________________________________________________________" << endl;
		cout << "|                          QUAN LY QUYEN                          |" << endl;
		cout << "|_________________________________________________________________|" << endl;
		cout << "__________________________________________________________________" << endl;
		cout << setw(5) << left << "|MS" << setw(30) << left << "|Ten Quyen" << setw(10) << left << "|Admin" << setw(10) << left << "|Thu thu" << setw(10) << left << "|Doc gia" << "|" << endl;
		//fstream inFile("Quyen.DAT", ios::in);
		cout << "|____|_____________________________|_________|_________|_________|" << endl;
		int dem = 23;
		/*
		while (!inFile.eof()){
		q[dem].doc(inFile);
		dem++;
		}
		*/
		for (int i = 0; i < dem; i++) {
			cout << "|" << setw(4) << left << q[i].stt << "|" << setw(29) << left << q[i].tenQuyen;
			if (q[i].Admin == 1) cout << "|" << setw(5) << right << "x" << setw(4) << " ";
			else cout << "|" << setw(9) << right << " ";
			if (q[i].ThuThu == 1) cout << "|" << setw(5) << right << "x" << setw(4) << " ";
			else cout << "|" << setw(9) << right << " ";
			if (q[i].DocGia == 1) cout << "|" << setw(5) << right << "x" << setw(4) << " ";
			else cout << "|" << setw(9) << right << " ";
			cout << "|" << endl;
		}
		cout << "|____|_____________________________|_________|_________|_________|" << endl;
		int op;
		cout << "\t1. Sua Quyen." << endl;
		cout << "\t2. Thoat." << endl;
		cout << "\t Nhap Lua chon: "; cin >> op;
		switch (op) {
		case 2: {
					break;
		}
		case 1: {
					int ms;
					cout << "Nhap ma quyen muon sua: "; cin >> ms; cin.ignore();
					for (int i = 0; i < dem; i++) {
						if (ms == q[i].stt) {
							cout << "Nhap ma tran uy quyen(A T D): ";
							cin >> q[i].Admin >> q[i].ThuThu >> q[i].DocGia; cin.ignore();
							Sleep(1311);
							break;
						}
					}
					cout << "Da sua thanh cong!" << endl;
					fstream outFile("Quyen.DAT", ios::out);
					for (int i = 0; i < dem; i++){
						q[i].ghi(outFile);
					}
					outFile.close();
					Sleep(1311);
					break;
		}
		}
	}

	//#######Quyen 4. Xem kho sach.###########################################################################

	else if (quyen == 4) {
		system("cls");
		cout << " _________________________________________________________________" << endl;
		cout << "|                             KHO SACH                            |" << endl;
		cout << "|_________________________________________________________________|" << endl;
		cout << endl;

		char ql;
		cout << "________________________________________________________________________________________________#TUYEN" << endl;
		cout << setw(5) << left << "Ma so" << setw(30) << left << "Ten sach" << setw(30) << left << "Tac gia" << setw(20) << left << "The loai" << setw(20) << left << "Ngon ngu" << setw(15) << left << "Danh gia" << setw(10) << left << "Trang thai" << endl;
		int s = TruyXuatSach(sach);
		for (int i = 0; i < s; i++) {
			cout << setw(5) << left << sach[i].ID << setw(30) << left << sach[i].tensach << setw(30) << left << sach[i].tentacgia << setw(20) << left << sach[i].theloai << setw(20) << left << sach[i].ngonngu << setw(15) << left << setprecision(2) << sach[i].danhgia;
			cout << setw(15) << left;
			if (sach[i].trangthai == 1) cout << "Chua muon" << endl;
			else cout << "Da muon" << endl;
		}
		system("pause");
	}

	//#######Quyen 5. Tim sach ##############################################################################
	else if (quyen == 5) {
		system("cls");
		double op;
		fstream inFile("Sach.DAT", ios::in);
		int s = TruyXuatSach(sach);
		cout << " ______________________________________________________________________________________" << endl;
		cout << "|                                  TIM KIEM SACH                                       |" << endl;
		cout << "|______________________________________________________________________________________|" << endl;
		cout << "|                                1. Tim theo ID                                        |" << endl;
		cout << "|                                2. Tim theo ten sach                                  |" << endl;
		cout << "|                                3. Tim theo ten tac gia                               |" << endl;
		cout << "|                                4. Tim theo the loai                                  |" << endl;
		cout << "|______________________________________________________________________________________|" << endl;
		cout << "Nhap Lua Chon :"; cin >> op;
		while (op != (int)op) {
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Nhap Lua Chon :"; cin >> op;
		} 
		cin.ignore();
		switch ((int)op) {
		case 1: {
					system("cls");
					cout << " ___________________________________________" << endl;
					cout << "|               TIM SACH THEO ID            |" << endl;
					cout << "|___________________________________________|" << endl;
					char id[13];
					int i;
					char ql;
					cout << "Nhap ID sach can tim :"; cin.getline(id,13);
					for (i = 0; i < s; i++) {
						if (strcmp(sach[i].ID, id)==0) {
							cout << " ___________________________________________" << endl;
							cout << "|                   TIM THAY  !             |" << endl;
							cout << "|___________________________________________|" << endl;
							cout << "   Ma So:           " << sach[i].ID << endl;
							cout << "   Ten Sach:        " << sach[i].tensach << endl;
							cout << "   Ten tac gia:     " << sach[i].tentacgia << endl;
							cout << "   The loai:        " << sach[i].theloai << endl;
							cout << "   Ngon ngu:        " << sach[i].ngonngu << endl;
							cout << "   Danh gia:        " << sach[i].danhgia << endl;
							cout << "   Trang thai:      ";
							cout << setw(15) << left;
							if (sach[i].trangthai == 1) cout << "Chua muon" << endl;
							else cout << "Da muon" << endl;
							break;
						}
					}
					if (i == s) {
						cout << " ___________________________________________" << endl;
						cout << "|               KHONG TIM THAY !            |" << endl;
						cout << "|___________________________________________|" << endl;
					}
					system("pause");
					break;
		}
		case 2: {
					system("cls");
					cout << " ___________________________________________" << endl;
					cout << "|             TIM SACH THEO TEN             |" << endl;
					cout << "|___________________________________________|" << endl;
					char name[30];
					int i;
					char ql;
					cout << "Nhap ten sach can tim :"; cin.getline(name, 30);
					for (i = 0; i < s; i++) {
						if (timkiemchuoi(sach[i].tensach, name) == 1) {
							cout << " ___________________________________________" << endl;
							cout << "|                   TIM THAY  !             |" << endl;
							cout << "|___________________________________________|" << endl;
							cout << " _________##########################################_________#QUANG_ " << endl;
							cout << setw(5) << left << "|Ma so" << setw(30) << left << "|Ten sach"
								<< setw(30) << left << "|Tac gia" << setw(20) << left << "|The loai"
								<< setw(20) << left << "|Ngon ngu" << setw(15) << left << "|Danh gia"
								<< setw(10) << left << "|Trang thai" << "|" << endl;
							cout << "|_____|____________________________________________________________________________|" << endl;
							for (int j = i; j < s; j++) {
								if (timkiemchuoi(sach[j].tensach, name) == 1) {
									cout << "|" << setw(4) << left << sach[j].ID << "|" << setw(29) << left << sach[j].tensach
										<< "|" << setw(29) << left << sach[j].tentacgia << "|"  << setw(19) << left << sach[j].theloai
										<< "|" << setw(19) << left << sach[j].ngonngu << "|" << setw(14) << left << sach[j].danhgia;
									cout << "|" << setw(14) << left;
									if (sach[j].trangthai == 1) cout << "Chua muon";
									else cout << "Da muon";
									cout << "|" << endl;
								}
							}
							break;
						}
					}
					if (i == s) {
						cout << " ___________________________________________" << endl;
						cout << "|               KHONG TIM THAY !            |" << endl;
						cout << "|___________________________________________|" << endl;
					}
					system("pause");
					break;
		}
		case 3: {
					system("cls");
					cout << " ___________________________________________" << endl;
					cout << "|          TIM SACH THEO TEN TAC GIA        |" << endl;
					cout << "|___________________________________________|" << endl;
					char name[30];
					int i;
					char ql;
					cout << "Nhap ten Tac gia can tim :"; cin.getline(name, 30);
					for (i = 0; i < s; i++) {
						if (timkiemchuoi(sach[i].tentacgia, name) == 1) {
							cout << "_____________________________________________#QUANG" << endl;
							cout << " _____________________________________" << endl;
							cout << "|               TIM THAY              |" << endl;
							cout << "|_____________________________________|" << endl;
							cout << setw(5) << left << "Ma so" << setw(30) << left << "Ten sach"
								<< setw(30) << left << "Tac gia" << setw(20) << left << "The loai"
								<< setw(20) << left << "Ngon ngu" << setw(15) << left << "Danh gia"
								<< setw(10) << left << "Trang thai" << endl;
							for (int j = i; j < s; j++) {
								if (timkiemchuoi(sach[j].tentacgia, name) == 1) {
									cout << setw(5) << left << sach[j].ID << setw(30) << left << sach[j].tensach
										<< setw(30) << left << sach[j].tentacgia << setw(20) << left << sach[j].theloai
										<< setw(20) << left << sach[j].ngonngu << setw(15) << left << sach[j].danhgia;
									cout << setw(15) << left;
									if (sach[j].trangthai == 1) cout << "Chua muon" << endl;
									else cout << "Da muon" << endl;
								}
							}
							break;
						}
					}
					if (i == s) cout << "Khong tim thay Sach nay!" << endl;
					system("pause");
					break;
		}
		case 4: {
					cout << "____________________________#TUYEN" << endl;
					system("cls");
					char name[30];
					int i;
					char ql;
					cout << "Nhap the loai can tim :"; cin.getline(name, 20);
					for (i = 0; i < s; i++) {
						if (timkiemchuoi(sach[i].theloai, name) == 1) {
							cout << setw(5) << left << "Ma so" << setw(30) << left << "Ten sach"
								<< setw(30) << left << "Tac gia" << setw(20) << left << "The loai"
								<< setw(20) << left << "Ngon ngu" << setw(15) << left << "Danh gia"
								<< setw(10) << left << "Trang thai" << endl;
							for (int j = i; j < s; j++) {
								if (timkiemchuoi(sach[j].theloai, name) == 1) {
									cout << setw(5) << left << sach[j].ID << setw(30) << left << sach[j].tensach
										<< setw(30) << left << sach[j].tentacgia << setw(20) << left << sach[j].theloai
										<< setw(20) << left << sach[j].ngonngu << setw(15) << left << sach[j].danhgia;
									cout << setw(15) << left;
									if (sach[j].trangthai == 1) cout << "Chua muon" << endl;
									else cout << "Da muon" << endl;
								}
							}
							break;
						}
					}
					if (i == s) cout << "Khong tim thay Sach nay!" << endl;
					system("pause");
					break;
		}
		default:
			break;
		}
	}

	//#######Quyen 6. Them sach #############################################################################

	else if (quyen == 6) {
		system("cls");
		cout << " ________________________________________" << endl;
		cout << "|               THEM SACH                |" << endl;
		cout << "|________________________________________|" << endl;
		cout << endl;
		CapNhatSach(sach);
		m = TruyXuatSach(sach);
		cout << "Them hoan tat!" << endl;
		Sleep(1311);
	}

	//#######Quyen 7. Muon sach ###############################################################################
	else if (quyen == 7) {
		time_t baygio = time(0);
		tm *ltm = localtime(&baygio);
		//nguoi dung hien tai
		char id[13];
		int op;
		int sl1 = TruyXuatSach(sach);
		int sl2 = TruyXuatMuonSach(muonsach);
		int dem = 0;
		for (int i = 0; i < sl2; i++) {
			if (muonsach[i].IDmuon == ngDung[hientai].sCMND) dem++;
		}
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|           DANG KY MUON SACH             |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << endl;
		if (dem != 0) {
			cout << "Co " << dem << " Sach da muon: " << endl;
			cout << "____________________________________________________________________________________________________________________________________________________________" << endl;
			cout << setw(10) << left << "|Ms Muon" << setw(15) << left << "|Ma So Sach"
				<< setw(30) << left << "|Ten Sach" << setw(20) << left << "|Ten tac gia"
				<< setw(20) << left << "|Ngon ngu" << setw(20) << left << "|The loai"
				<< setw(20) << left << "|Ngay muon" << setw(20) << left << "|Ngay Tra" << "|" << endl;
			for (int i = 0; i < sl2; i++) {
				if (muonsach[i].IDmuon == ngDung[hientai].sCMND) {
					cout << "|" << setw(9) << left << muonsach[i].ID << "|" << setw(14) << left << muonsach[i].IDsach
						<< "|" << setw(29) << left << muonsach[i].tensach << "|" << setw(19) << left << muonsach[i].tentacgia
						<< "|" << setw(19) << left << muonsach[i].ngonngu << "|" << setw(19) << left << muonsach[i].theloai
						<< "|" << setw(11) << right << muonsach[i].ngayMuon[0] << "/" << setw(2) << right << muonsach[i].ngayMuon[1] << "/" << muonsach[i].ngayMuon[2]
						<< "|" << setw(11) << right << muonsach[i].ngayTra[0] << "/" << setw(2) << right << muonsach[i].ngayTra[1] << "/" << muonsach[i].ngayTra[2] << "|" << endl;
				}

			}
			cout << "|_________|______________|_____________________________|___________________|___________________|___________________|___________________|___________________|" << endl;
		}
		cout << "Nhap ID sach muon muon: "; cin.getline(id,13);
		for (int i = 0; i < sl1; i++) {
			if (strcmp(id,sach[i].ID)==0) {
				if (sach[i].trangthai == 1) {
					cout << "Tim thay: " << sach[i].tensach << endl;
					cout << "Ban co muon muon sach nay?" << endl;
					cout << "1. Co " << endl;
					cout << "2. Khong " << endl;
					cout << "Nhap lua chon: "; cin >> op; cin.ignore();
					switch (op) {
					case 1: {
								muonsach[sl2].ID = sl2 + 1;
								strcpy(muonsach[sl2].IDmuon, ngDung[hientai].sCMND);
								strcpy(muonsach[sl2].IDsach, sach[i].ID);


								strcpy(muonsach[sl2].tensach, sach[i].tensach);
								strcpy(muonsach[sl2].tentacgia, sach[i].tentacgia);
								strcpy(muonsach[sl2].ngonngu, sach[i].ngonngu);
								strcpy(muonsach[sl2].theloai, sach[i].theloai);
								muonsach[sl2].ngayMuon[0] = ltm->tm_mday;
								muonsach[sl2].ngayMuon[1] = 1 + ltm->tm_mon;
								muonsach[sl2].ngayMuon[2] = 1900 + ltm->tm_year;
								muonsach[sl2].ngayTra[0] = ltm->tm_mday + 15;
								if (muonsach[sl2].ngayMuon[0] + 15 > 30) {
									muonsach[sl2].ngayTra[0] = ltm->tm_mday + 15 - 29;
									muonsach[sl2].ngayTra[1] = muonsach[sl2].ngayMuon[1] + 1;
									if (muonsach[sl2].ngayTra[1] > 12) {
										muonsach[sl2].ngayTra[1] = 1;
										muonsach[sl2].ngayTra[2] = muonsach[sl2].ngayMuon[2] + 1;
									}
									else {
										muonsach[sl2].ngayTra[2] = muonsach[sl2].ngayMuon[2];
									}
								}
								else {
									muonsach[sl2].ngayTra[0] = ltm->tm_mday + 15;
									muonsach[sl2].ngayTra[1] = 1 + ltm->tm_mon;
									muonsach[sl2].ngayTra[2] = 1900 + ltm->tm_year;
								}
								fstream outFile("MuonSach.DAT", ios::app);
								muonsach[sl2].ghi(outFile);
								outFile.close();
								cout << "Yeu cau muon sach cua ban dang duoc xu ly! Ban se nhan duoc thong bao xac nhan sau. Xin cam on.";
								sach[i].trangthai = 0; // da muon

								int slyc = TruyXuatYeuCau(yc);
								yc[slyc].stt = slyc + 1;
								//yc[slyc].GetInf(1, ngDung[hientai].sCMND, ngDung[hientai].tenNguoiDung, muonsach[sl2].IDsach, muonsach[sl2].tensach, sl2);

								yc[slyc].mayc = 1;
								strcpy(yc[slyc].ID, ngDung[hientai].sCMND);
								strcpy(yc[slyc].IDsach, muonsach[sl2].IDsach);
								strcpy(yc[slyc].tensach, muonsach[sl2].tensach);
								strcpy(yc[slyc].tenND, ngDung[hientai].tenNguoiDung);
								yc[slyc].IDmuon = sl2;

								fstream out1File("YeuCau.DAT", ios::app);
								yc[slyc].ghi(out1File);
								out1File.close();
								fstream out2File("Sach.DAT", ios::out);
								for (int j = 0; j < sl1; j++){
									sach[j].ghi(out2File);
								}
								out2File.close();
								//ThongBaoTuDong(ngDung, hientai, thongbao, 2, muonsach);

					}
					default:
						break;
					}
				}
				else cout << "Khong thay sach can tim hoac sach da duoc muon" << endl;
			}
		}
		Sleep(3000);
	}

	//#######Quyen 8. Tra sach###############################################################################

	else if (quyen == 8) {
		// nguoi dung hien tai
		int sl1 = TruyXuatSach(sach);
		int sl = TruyXuatMuonSach(muonsach);
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|                TRA SACH                 |" << endl;
		cout << "|_________________________________________|" << endl;
		char id[13];
		int dem = 0;

		for (int i = 0; i < sl; i++) {
			if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND)==0) dem++;

		}
		if (dem == 0) {
			cout << "Ban chua muon sach nao." << endl;
		}
		else {
			cout << "Co " << dem << " Sach da muon: " << endl;
			cout << "____________________________________________________________________________________________________________________________________________________________" << endl;
			cout << setw(10) << left << "|Ms Muon" << setw(15) << left << "|Ma So Sach"
				<< setw(30) << left << "|Ten Sach" << setw(20) << left << "|Ten tac gia"
				<< setw(20) << left << "|Ngon ngu" << setw(20) << left << "|The loai"
				<< setw(20) << left << "|Ngay muon" << setw(20) << left << "|Ngay Tra" << "|" << endl;
			for (int i = 0; i < sl; i++) {
				if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND)==0) {
					cout << "|" << setw(9) << left << muonsach[i].ID << "|" << setw(14) << left << muonsach[i].IDsach
						<< "|" << setw(29) << left << muonsach[i].tensach << "|" << setw(19) << left << muonsach[i].tentacgia
						<< "|" << setw(19) << left << muonsach[i].ngonngu << "|" << setw(19) << left << muonsach[i].theloai
						<< "|" << setw(11) << right << muonsach[i].ngayMuon[0] << "/" << setw(2) << right << muonsach[i].ngayMuon[1] << "/" << muonsach[i].ngayMuon[2]
						<< "|" << setw(11) << right << muonsach[i].ngayTra[0] << "/" << setw(2) << right << muonsach[i].ngayTra[1] << "/" << muonsach[i].ngayTra[2] << "|" << endl;
				}

			}
			cout << "|_________|______________|_____________________________|___________________|___________________|___________________|___________________|___________________|" << endl;

			cout << "Nhap ID sach muon tra: "; cin.getline(id,13);
			for (int i = 0; i < sl; i++) {
				if (strcmp(muonsach[i].IDsach, id)==0) {
					if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND)==0) {
						cout << "Tim thay sach " << muonsach[i].tensach << endl;
						cout << "Ban co muon tra sach nay khong? " << endl;
						int op;
						cout << "1. Co" << endl;
						cout << "2. Khong" << endl;
						cout << "Nhap lua chon: "; cin >> op; cin.ignore();
						switch (op) {
						case 1: {
									for (int j = i; j < sl; j++)
										muonsach[j] = muonsach[j + 1];
									fstream outFile("MuonSach.DAT", ios::out);
									for (int l = 0; l < sl - 1; l++) {
										muonsach[l].ghi(outFile);
									}
									for (int l = 0; l < sl1; l++) {
										if (strcmp(sach[l].ID, id)==0) sach[l].trangthai = 1;
									}
									//sach[id - 1].trangthai = 1;
									cout << "Da tra sach!" << endl;
									int choose;
									int diem;
									cout << " _________________________________________" << endl;
									cout << "|                DANH GIA                 |" << endl;
									cout << "|_________________________________________|" << endl;
									cout << "Ban co muon danh gia sach" << endl;
									cout << "1. Co \n2. Khong" << endl;
									cout << "Nhap lua chon: ";
									cin >> choose;
									int k = 0;
									for (k = 0; k < sl; k++) {
										if (strcmp(sach[k].ID, id)==0)break;

									}
									if (choose == 1) {
										cout << "Nhap so diem ban danh gia: ";
										cin >> diem;
										sach[k].danhgia = (sach[k].danhgia*sach[k].soluotdanhgia + diem) / (sach[k].soluotdanhgia + 1);
										sach[k].soluotdanhgia = sach[k].soluotdanhgia + 1;
										cout << "Cam on ban da danh gia !!!";
									}
									fstream out1File("Sach.DAT", ios::out);
									for (int j = 0; j < sl1; j++) {
										sach[j].ghi(out1File);
									}
									ThongBaoTuDong(ngDung, hientai, thongbao, 3, muonsach);
									break;
						}
						default:
							break;
						}
					}
					else cout << "Ban khong muon sach nay." << endl;
				}
			}

		}
		Sleep(1311);
	}

	//#######QUyen 9. Xem balo################################################################################

	else if (quyen == 9) {
		//nguoi dung hien tai
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|                   BALO                  |" << endl;
		cout << "|_________________________________________|" << endl;
		int sl = TruyXuatMuonSach(muonsach);
		cout << "Co " << sl << " Sach da muon: " << endl;
		cout << "____________________________________________________________________________________________________________________________________________________________" << endl;
		cout << setw(10) << left << "|Ms Muon" << setw(15) << left << "|Ma So Sach"
			<< setw(30) << left << "|Ten Sach" << setw(20) << left << "|Ten tac gia"
			<< setw(20) << left << "|Ngon ngu" << setw(20) << left << "|The loai"
			<< setw(20) << left << "|Ngay muon" << setw(20) << left << "|Ngay Tra" << "|" << endl;
		for (int i = 0; i < sl; i++) {
			if (strcmp(muonsach[i].IDmuon, ngDung[hientai].sCMND)==0) {
				cout << "|" << setw(9) << left << muonsach[i].ID << "|" << setw(14) << left << muonsach[i].IDsach
					<< "|" << setw(29) << left << muonsach[i].tensach << "|" << setw(19) << left << muonsach[i].tentacgia
					<< "|" << setw(19) << left << muonsach[i].ngonngu << "|" << setw(19) << left << muonsach[i].theloai
					<< "|" << setw(11) << right << muonsach[i].ngayMuon[0] << "/" << setw(2) << right << muonsach[i].ngayMuon[1] << "/" << muonsach[i].ngayMuon[2]
					<< "|" << setw(11) << right << muonsach[i].ngayTra[0] << "/" << setw(2) << right << muonsach[i].ngayTra[1] << "/" << muonsach[i].ngayTra[2] << "|" << endl;
			}

		}
		cout << "|_________|______________|_____________________________|___________________|___________________|___________________|___________________|___________________|" << endl;
		system("pause");
	}

	//#######Quyen 10. Doi mat khau###########################################################################

	else if (quyen == 10) {
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|               DOI MAT KHAU              |" << endl;
		cout << "|_________________________________________|" << endl;
		char mkc[20];
		char mk1[20];
		char mk2[20];
		int kt1 = 0, kt2 = 0;
		for (int i = 0; i < m; i++) {
			if (strcmp(tdn, ngDung[i].tenDangNhap) == 0) {
				while (kt1 == 0) {
					cout << "Nhap mat khau cu: "; inmk(mkc);
					if (strcmp(mkc, ngDung[i].MatKhau) == 0) {
						do {
							cout << "Nhap mat khau moi: "; inmk(mk1);
							cout << "Nhap lai mat khau moi: "; inmk(mk2);
							if (strcmp(mk1, mk2) == 0) {
								strcpy(ngDung[i].MatKhau, mk1);
								kt2 = 1;
							}
							else cout << "Khong khop. Nhap lai: " << endl;
						} while (kt2 == 0);
						cout << "Doi mat khau thanh cong! " << endl;
						kt1 = 1;
					}
					else cout << "Sai mat khau!" << endl;
				}
				break;
			}
		}
		fstream outFile("UserData.DAT", ios::out);
		for (int i = 0; i < m; i++) {
			ngDung[i].ghi(outFile);
		}
		outFile.close();
		Sleep(1311);
	}

	////########Quyen 11. Xem thong bao ########################################################################

	else if (quyen == 11) {
		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|               THONG BAO                 |" << endl;
		cout << "|_________________________________________|" << endl;
		int sl = TruyXuatThongBao(thongbao);
		fstream inFile("ThongBao.DAT", ios::in);
		for (int i = 0; i < sl; i++) {
			thongbao[i].doc(inFile);
		}
		inFile.close();
		int kt = 0;
		int op;
		cout << "_______________________############QUANG" << endl;
		cout << setw(10) << left << "Ma so" << setw(15) << left << "Nguoi gui" << setw(20) << left << "thoi gian" << setw(100) << left << "tieu de" << endl;
		for (int i = 0; i < sl; i++) {
			if (strcmp(ngDung[hientai].sCMND, thongbao[i].IDnhan)==0) {
				cout << setw(10) << left << thongbao[i].IDthongbao;
				if (strcmp(thongbao[i].IDgui, "1")==0) cout << setw(15) << left << "Admin";
				else if (strcmp(thongbao[i].IDgui, "2")==0) cout << setw(15) << left << "Thu thu";
				else cout << setw(15) << left << "He thong";
				cout << setw(20) << left << thongbao[i].time << setw(100) << left << thongbao[i].tieude << endl;
				kt = 1;
			}
		}
		if (kt == 0) cout << "Ban khong co khong bao nao." << endl;
		else {
			cout << "Nhap ma so thong bao de xem, nhap 0 de thoat." << endl;
			cout << "Nhap lua chon: "; cin >> op; cin.ignore();
			if (op != 0) {
				for (int i = 0; i < sl; i++) {
					if (strcmp(ngDung[hientai].sCMND, thongbao[i].IDnhan)==0) {
						if (thongbao[i].IDthongbao == op) {
							cout << endl;
							cout << "Chu De: " << thongbao[i].tieude << endl << endl;
							cout << "Noi Dung: " << endl;
							cout << thongbao[i].noidung << endl;
							cout << endl;
						}
					}
				}
			}
		}
		system("pause");
	}

	////########Quyen 12. Reset mat khau #######################################################################

	else if (quyen == 12) {
		system("cls");
		char cm[13];
		int i;
		int kt = 0;
		cout << " _________________________________________" << endl;
		cout << "|             RESET MAT KHAU              |" << endl;
		cout << "|_________________________________________|" << endl;
		cout << "Nhap so CMND: "; cin >> cm; cin.ignore();
		for (i = 0; i < m; i++) {
			if (strcmp(cm, ngDung[i].sCMND)==0) {
				strcpy(ngDung[i].MatKhau, "1");
				cout << "Mat khau da duoc reset" << endl;
				kt = 1;
			}
		}
		fstream outFile("UserData.DAT", ios::out);
		for (i = 0; i < m; i++) {
			ngDung[i].ghi(outFile);
		}
		if (kt == 0) cout << "Khong tim thay nguoi nay";

		outFile.close();
		Sleep(1311);
	}

	////########## quyen 13. Tim kiem tai khoan ###############################################################
	////nghia sua gd
	else if (quyen == 13) {
		system("cls");
		int op;
		fstream inFile("UserData.DAT", ios::in);
		int m = TruyXuatNgDung(ngDung);
		cout << " _________________________________________________________________________________________________" << endl;
		cout << "|                                       TIM KIEM TAI KHOAN                                        |" << endl;
		cout << "|_________________________________________________________________________________________________|" << endl;
		cout << "|                                         1. Tim theo ID.                                         |" << endl;
		cout << "|                                         2. Tim theo ten.                                        |" << endl;
		cout << "|                                         3. Tim theo Dia chi.                                    |" << endl;
		cout << "|                                         4. Tim theo ngay sinh.                                  |" << endl;
		cout << "|_________________________________________________________________________________________________|" << endl;

		cout << "Nhap lua chon: "; cin >> op; cin.ignore();
		switch (op) {
		case 1: {
					system("cls");
					//////////////TUYEN
					char id[13];
					int i;
					char ql;
					cout << "Nhap ID can tim :"; cin >> id;
					for (i = 0; i < m; i++) {
						if (strcmp(ngDung[i].sCMND, id)==0) {
							cout << setw(15) << left << "So CMND" << setw(30) << left << "Ho va ten"
								<< setw(15) << left << "Ngay sinh" << setw(30) << left << "Dia chi"
								<< setw(15) << left << "Trang thai" << setw(15) << left << "Chuc vu" << endl;
							cout << setw(15) << left << ngDung[i].sCMND << setw(30) << left << ngDung[i].tenNguoiDung
								<< setw(15) << left << ngDung[i].ngaySinh << setw(30) << left << ngDung[i].diaChi << setw(15) << left;
							if (ngDung[i].chucVu.admin == 1) cout << "Admin";
							else if (ngDung[i].chucVu.thuthu == 1) cout << "Thu Thu";
							else cout << "Doc Gia";
							cout << setw(15) << left;
							if (ngDung[i].trangThai == 1) cout << "Hoat Dong" << endl;
							else cout << "Bi khoa" << endl;
							break;
						}
					}
					if (i == m) cout << "Khong tim thay ID nay!" << endl;
					system("pause");
					break;

		}
		case 2: {
					system("cls");
					char name[30];
					int i;
					char ql;
					cout << "Nhap ten nguoi can tim :"; cin.getline(name, 30);
					for (i = 0; i < m; i++) {
						if (timkiemchuoi(ngDung[i].tenNguoiDung, name) == 1) {
							cout << setw(15) << left << "So CMND" << setw(30) << left << "Ho va ten"
								<< setw(15) << left << "Ngay sinh" << setw(30) << left << "Dia chi"
								<< setw(15) << left << "Trang thai" << setw(15) << left << "Chuc vu" << endl;
							for (int j = i; j < m; j++) {
								if (timkiemchuoi(ngDung[j].tenNguoiDung, name) == 1) {
									cout << setw(15) << left << ngDung[j].sCMND << setw(30) << left << ngDung[j].tenNguoiDung
										<< setw(15) << left << ngDung[j].ngaySinh << setw(30) << left << ngDung[j].diaChi;
									cout << setw(15) << left;
									if (ngDung[j].trangThai == 1) cout << "Hoat Dong";
									else cout << "Bi khoa";
									cout << setw(15) << left;
									if (ngDung[j].chucVu.admin == 1) cout << "Administration" << endl;
									else if (ngDung[j].chucVu.thuthu == 1) cout << "Thu Thu" << endl;
									else cout << "Doc Gia" << endl;
								}
							}
							break;
						}
					}
					if (i == m) cout << "Khong tim thay nguoi nay!" << endl;
					system("pause");
					break;
		}
		case 3: {
					system("cls");
					char name[30];
					int i;
					char ql;
					cout << "Nhap dia chi can tim :"; cin.getline(name, 30);
					for (i = 0; i < m; i++) {
						if (timkiemchuoi(ngDung[i].diaChi, name) == 1) {
							cout << setw(15) << left << "So CMND" << setw(30) << left << "Ho va ten"
								<< setw(15) << left << "Ngay sinh" << setw(30) << left << "Dia chi"
								<< setw(15) << left << "Trang thai" << setw(15) << left << "Chuc vu" << endl;
							for (int j = i; j < m; j++) {
								if (timkiemchuoi(ngDung[j].diaChi, name) == 1) {
									cout << setw(15) << left << ngDung[j].sCMND << setw(30) << left << ngDung[j].tenNguoiDung
										<< setw(15) << left << ngDung[j].ngaySinh << setw(30) << left << ngDung[j].diaChi;
									cout << setw(15) << left;
									if (ngDung[j].trangThai == 1) cout << "Hoat Dong";
									else cout << "Bi khoa";
									cout << setw(15) << left;
									if (ngDung[j].chucVu.admin == 1) cout << "Administration" << endl;
									else if (ngDung[j].chucVu.thuthu == 1) cout << "Thu Thu" << endl;
									else cout << "Doc Gia" << endl;
								}
							}
							break;
						}
					}
					if (i == m) cout << "Khong tim thay dia chi nay!" << endl;
					system("pause");
					break;
		}
		case 4: {
					system("cls");
					char name[30];
					int i;
					char ql;
					cout << "Nhap ngay sinh can tim :"; cin.getline(name, 30);
					for (i = 0; i < m; i++) {
						if (timkiemchuoi(ngDung[i].ngaySinh, name) == 1) {
							cout << setw(15) << left << "So CMND" << setw(30) << left << "Ho va ten"
								<< setw(15) << left << "Ngay sinh" << setw(30) << left << "Dia chi"
								<< setw(15) << left << "Trang thai" << setw(15) << left << "Chuc vu" << endl;
							for (int j = i; j < m; j++) {
								if (timkiemchuoi(ngDung[j].ngaySinh, name) == 1) {
									cout << setw(15) << left << ngDung[j].sCMND << setw(30) << left << ngDung[j].tenNguoiDung
										<< setw(15) << left << ngDung[j].ngaySinh << setw(30) << left << ngDung[j].diaChi;
									if (ngDung[j].trangThai == 1) cout << "Hoat Dong";
									else cout << "Bi khoa";
									cout << setw(15) << left;
									if (ngDung[j].chucVu.admin == 1) cout << "Administration" << endl;
									else if (ngDung[j].chucVu.thuthu == 1) cout << "Thu Thu" << endl;
									else cout << "Doc Gia" << endl;
								}
							}
							break;
						}
					}
					if (i == m) cout << "Khong tim thay thong tin nay!" << endl;
					system("pause");
					break;
		}
		default:
			break;
		}
	}

	////##########Quyen 14. Tao thong bao #################################################
	///Ly
	else if (quyen == 14) {
		int op;
		int sl = TruyXuatThongBao(thongbao);
		//thongbao[sl].IDgui = ngDung[hientai].chucVu;
		cout << "Chon doi tuong gui:" << endl;
		cout << "1. Ca nhan." << endl;
		cout << "2. Nhom nguoi." << endl;
		cout << "3. Tat ca Admin." << endl;
		cout << "4. Tat ca thu thu." << endl;
		cout << "5. Tat ca doc gia." << endl;
		cout << "6. Toan bo nguoi dung." << endl;
		cout << "Lua chon: "; cin >> op; cin.ignore();
		switch (op) {
		case 1: {
					system("cls");
					thongbao[sl].IDthongbao = sl + 1;
					char a[13];
					if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
					else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
					else strcpy(a, "-1");
					strcpy(thongbao[sl].IDgui, a);
					cout << "Nhap ID nguoi nhan: "; cin.getline(thongbao[sl].IDnhan,13);
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(thongbao[sl].tieude, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(thongbao[sl].noidung, 100);
					time_t rawtime;
					struct tm *info;
					char buffer[50];

					time(&rawtime);

					info = localtime(&rawtime);

					strftime(buffer, 80, "%x - %I:%M%p", info);
					strcpy(thongbao[sl].time, buffer);
					fstream outFile("ThongBao.DAT", ios::app);
					thongbao[sl].ghi(outFile);
					outFile.close();
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 2: {
					system("cls");
					int sln = 0;
					char td[100];
					char nd[1000];

					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					cout << "Nhap so luong nguoi nhan: "; cin >> sln;
					char nguoinhan[13];
					cin.ignore();
					//cout << "Nhap ID nguoi nhan, cach nhau mot khoang trang : ";
					char a[13];
					for (int i = 0; i < sln; i++) {
						cout << "Nhap ID nguoi thu " << i+1 << " : ";
						cin.getline(nguoinhan,13);
						
						if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
						else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
						else strcpy(a, "-1");
						strcpy(thongbao[sl + i].IDgui,a);
						thongbao[sl + i].IDthongbao = sl + i + 1;
						//itoa(nguoinhan[i], thongbao[sl + i].IDnhan, 13);
						//cout << thongbao[sl + i].IDnhan << endl;
						strcpy(thongbao[sl + i].IDnhan, nguoinhan);
						strcpy(thongbao[sl + i].tieude, td);
						strcpy(thongbao[sl + i].noidung, nd);

						time_t rawtime;
						struct tm *info;
						char buffer[50];

						time(&rawtime);

						info = localtime(&rawtime);

						strftime(buffer, 80, "%x - %I:%M%p", info);
						strcpy(thongbao[sl + i].time, buffer);
						fstream outFile("ThongBao.DAT", ios::app);
						thongbao[sl + i].ghi(outFile);
						outFile.close();
					}
					cout << "Gui thanh cong!" << endl;
					
					Sleep(1311);
					break;
		}
		case 3: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;

					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						if (ngDung[i].chucVu.admin == 1) {
							
							if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
							else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
							else strcpy(a, "-1");
							strcpy(thongbao[sl+dem].IDgui, a);
							//thongbao[sl + dem].IDgui = ngDung[hientai].chucVu;
							thongbao[sl + dem].IDthongbao = sl + dem + 1;
							strcpy(thongbao[sl + dem].IDnhan, ngDung[i].sCMND);
							strcpy(thongbao[sl + dem].tieude, td);
							strcpy(thongbao[sl + dem].noidung, nd);

							time_t rawtime;
							struct tm *info;
							char buffer[50];

							time(&rawtime);

							info = localtime(&rawtime);

							strftime(buffer, 80, "%x - %I:%M%p", info);
							strcpy(thongbao[sl + dem].time, buffer);
							fstream outFile("ThongBao.DAT", ios::app);
							thongbao[sl + dem].ghi(outFile);
							outFile.close();
							dem++;
						}

					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 4: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;

					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						if (ngDung[i].chucVu.thuthu == 1) {
							if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
							else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
							else strcpy(a, "-1");
							strcpy(thongbao[sl + dem].IDgui, a);
							//thongbao[sl + dem].IDgui = ngDung[hientai].chucVu;
							thongbao[sl + dem].IDthongbao = sl + dem + 1;
							strcpy(thongbao[sl + dem].IDnhan, ngDung[i].sCMND);
							strcpy(thongbao[sl + dem].tieude, td);
							strcpy(thongbao[sl + dem].noidung, nd);

							time_t rawtime;
							struct tm *info;
							char buffer[50];

							time(&rawtime);

							info = localtime(&rawtime);

							strftime(buffer, 80, "%x - %I:%M%p", info);
							strcpy(thongbao[sl + dem].time, buffer);
							fstream outFile("ThongBao.DAT", ios::app);
							thongbao[sl + dem].ghi(outFile);
							outFile.close();
							dem++;
						}

					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 5: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;

					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						if (ngDung[i].chucVu.docgia == 1) {
							if (ngDung[hientai].chucVu.admin == 1) strcpy(a, "1");
							else if (ngDung[hientai].chucVu.thuthu == 1) strcpy(a, "2");
							else strcpy(a, "-1");
							strcpy(thongbao[sl + dem].IDgui, a);
							//thongbao[sl + dem].IDgui = ngDung[hientai].chucVu;
							thongbao[sl + dem].IDthongbao = sl + dem + 1;
							strcpy(thongbao[sl + dem].IDnhan, ngDung[i].sCMND);
							strcpy(thongbao[sl + dem].tieude, td);
							strcpy(thongbao[sl + dem].noidung, nd);

							time_t rawtime;
							struct tm *info;
							char buffer[50];

							time(&rawtime);

							info = localtime(&rawtime);

							strftime(buffer, 80, "%x - %I:%M%p", info);
							strcpy(thongbao[sl + dem].time, buffer);
							fstream outFile("ThongBao.DAT", ios::app);
							thongbao[sl + dem].ghi(outFile);
							outFile.close();
							dem++;
						}

					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		case 6: {
					system("cls");
					int slnd = TruyXuatNgDung(ngDung);
					int dem = 0;

					char td[100];
					char nd[1000];
					cout << "Nhap tieu de(<100 ky tu): "; cin.getline(td, 100);
					cout << "Nhap noi dung(<1000 ky tu): "; cin.getline(nd, 1000);
					char a[13];
					for (int i = 0; i < slnd; i++) {
						strcpy(thongbao[sl + i].IDgui, "-1");
						thongbao[sl + i].IDthongbao = sl + i + 1;
						strcpy(thongbao[sl + i].IDnhan , ngDung[i].sCMND);
						strcpy(thongbao[sl + i].tieude, td);
						strcpy(thongbao[sl + i].noidung, nd);

						
						time_t rawtime;
						struct tm *info;
						char buffer[50];

						time(&rawtime);

						info = localtime(&rawtime);

						strftime(buffer, 80, "%x - %I:%M%p", info);
						strcpy(thongbao[sl + i].time, buffer);
						fstream outFile("ThongBao.DAT", ios::app);
						thongbao[sl + i].ghi(outFile);
						outFile.close();



					}
					cout << "Gui thanh cong!" << endl;
					Sleep(1311);
					break;
		}
		default: {
					 cout << "Khong co lua chon nay. Quay laij menu chinh!" << endl;
					 Sleep(1311);
					 break;
		}
		}

	}

	////##########//Quyen 15. Sua thong tin sach ##########################################

	else if (quyen == 15) {
		system("cls");
		fstream inFile("Sach.DAT", ios::in);
		int sl = TruyXuatSach(sach);

		system("cls");
		cout << " _________________________________________" << endl;
		cout << "|           SUA THONG TIN SACH            |" << endl;
		cout << "|_________________________________________|" << endl;
		char idsach[13];
		bool timkiem = 0;
		cout << "Nhap ID sach can sua: ";
		cin >> idsach; cin.ignore();
		for (int i = 0; i < sl; i++) {
			if (strcmp(idsach, sach[i].ID)==0) {
				cout << "Sach duoc tim thay: " << sach[i].tensach << endl;
				cout << "Nhap ten sach moi: ";
				cin.getline(sach[i].tensach, 30);
				cout << "Nhap ten tac gia: ";
				cin.getline(sach[i].tentacgia, 30);
				cout << "Nhap ngon ngu: ";
				cin.getline(sach[i].ngonngu, 20);
				cout << "Nhap the loai: ";
				cin.getline(sach[i].theloai, 20);
				timkiem = 1;
				cout << "Da luu thay doi";
			}
		}
		fstream outFile("Sach.DAT", ios::out);
		for (int i = 0; i < sl; i++) {
			sach[i].ghi(outFile);
		}
		
		inFile.close();
		outFile.close();
		if (timkiem = 0) cout << "Khong tim thay sach";
		inFile.close();
		outFile.close();
		Sleep(1311);
	}
	////##########//Quyen 16. Xoa sach #################################
	else if (quyen == 16) {
		system("cls");
		cout << " ______________________________________" << endl;
		cout << "|                XOA SACH              |" << endl;
		cout << "|______________________________________|" << endl;
		char id[13];
		int luachon;
		bool kt = 0;
		fstream inFile("Sach.DAT", ios::in);
		int sl = TruyXuatSach(sach);
		cout << "Nhap ID sach can xoa: ";
		cin.getline(id,13);
		for (int i = 0; i < sl; i++) {
			if (strcmp(id, sach[i].ID)==0) {
				kt = 1;
				cout << "Sach duoc tim thay: " << sach[i].tensach << endl;
				cout << "Ban co muon xoa sach: " << endl;
				cout << "1. Co" << endl;
				cout << "2. Khong" << endl;
				cout << "Nhap lua chon: ";
				cin >> luachon; cin.ignore();
				if (luachon == 1) {
					for (int j = i; j < sl; j++) {
						sach[j] = sach[j + 1];
					}
					cout << "Xoa sach thanh cong" << endl;

				}
				else {
					cout << "Xoa sach that bai" << endl;
					Sleep(1311);
				}
			}
		}
		fstream outFile("Sach.DAT", ios::out);
		for (int a = 0; a < sl; a++)
			sach[a].ghi(outFile);
		if (kt == 0)cout << "Khong tim thay sach";
		Sleep(1311);
	}

	////##########Quyen 17. Xem thong tin tai khoan ##########################################################

	else if (quyen == 17) {
		system("cls");
		cout << " ______________________________________" << endl;
		cout << "|       XEM THONG TIN TAI KHOAN        |" << endl;
		cout << "|______________________________________|" << endl;
		int soluong = TruyXuatNgDung(ngDung);
		cout << "=====================================================" << endl;
		cout << "So CMND:          " << ngDung[hientai].sCMND << endl;
		cout << "Ten Nguoi Dung:   " << ngDung[hientai].tenNguoiDung << endl;
		cout << "Ngay Sinh:        " << ngDung[hientai].ngaySinh << endl;
		cout << "Dia Chi:          " << ngDung[hientai].diaChi << endl;
		cout << "Ten Dang Nhap:    " << ngDung[hientai].tenDangNhap << endl;
		cout << "Chuc Vu:          ";
		if (ngDung[hientai].chucVu.admin == 1)cout << "Administration" << endl;
		else if (ngDung[hientai].chucVu.thuthu == 1)cout << "Thu Thu" << endl;
		else
		{
			cout << "Doc GIa" << endl;
		};
		cout << "======================================================" << endl;
		system("pause");
	}

	////##########//Quyen 18. Xem danh sach Nguoi dung.########################################################

	else if (quyen == 18) {
		system("cls");
		cout << " ______________________________________" << endl;
		cout << "|       XEM DANH SACH TAI KHOAN        |" << endl;
		cout << "|______________________________________|" << endl;
		char ql;
		cout << " ____________________________________________________________________________________________________________________" << endl;
		cout << "|" << setw(13) << left << "So CMND" << "|" << setw(28) << left << "Ho va ten" << "|" << setw(15) << left << "Ngay sinh" << "|" << setw(20) << left << "Dia chi" << "|" << setw(20) << left << "Chuc vu" << "|" << setw(15) << left << "Trang thai" << "|" << endl;
		cout << "|_____________|____________________________|_______________|____________________|____________________|_______________|" << endl;
		m = TruyXuatNgDung(ngDung);
		for (int i = 0; i < m; i++) {
			cout << "|" << setw(13) << left << ngDung[i].sCMND << "|" << setw(28) << left << ngDung[i].tenNguoiDung << "|" << setw(15) << left << ngDung[i].ngaySinh << "|" << setw(20) << left << ngDung[i].diaChi << "|" << setw(20) << left;
			if (ngDung[i].chucVu.admin == 1) cout << "Administration" << "|";
			else if (ngDung[i].chucVu.thuthu == 1) cout << "Thu Thu" << "|";
			else cout << "Doc Gia" << "|";
			cout << setw(15) << left;
			if (ngDung[i].trangThai == 1) cout << "Hoat Dong" << "|" << endl;
			else cout << "Bi khoa" << "|" << endl;
		}
		cout << "|_____________|____________________________|_______________|____________________|____________________|_______________|" << endl;
		system("pause");
	}
	////############Quyen 19. Sua thong tin tai khoan ##########################################################
	////NGHIA SUA GD
	else if (quyen == 19) {
		// QUANG
		system("cls");
		int luachon;
		int sl = TruyXuatNgDung(ngDung);
		
		cout << " ___________________________________________________________________________________________________________" << endl;
		cout << "|                                        SUA THONG TIN TAI KHOAN                                            |" << endl;
		cout << "|___________________________________________________________________________________________________________|" << endl;
		cout << "|                                          1. So CMND                                                       |" << endl;
		cout << "|                                          2. Ten nguoi dung                                                |" << endl;
		cout << "|                                          3. Ngay sinh                                                     |" << endl;
		cout << "|                                          4. Dia chi                                                       |" << endl;
		cout << "|                                          5. Ten tai khoan                                                 |" << endl;
		cout << "|___________________________________________________________________________________________________________|" << endl;
		cout << "Nhap lua chon: ";
		cin >> luachon; cin.ignore();
		switch (luachon)
		{
		case 1: {
					system("cls");
					cout << " ______________________________________" << endl;
					cout << "|              SUA SO CMND             |" << endl;
					cout << "|______________________________________|" << endl;
					cout << "So CMND cu: " << ngDung[hientai].sCMND << endl;
					cout << "Nhap so CMND moi: ";
					cin.getline(ngDung[hientai].sCMND,13);
					cout << "Da thay doi so CMND";
					break;
		}
		case 2: {
					cout << "Ten nguoi dung cu: " << ngDung[hientai].tenNguoiDung << endl;
					cout << "Nhap ten nguoi dung moi: ";
					cin.getline(ngDung[hientai].tenNguoiDung, 30);
					cout << "Da thay doi ten nguoi dung";
					break;
		}
		case 3: {
					cout << "Ngay sinh cu: " << ngDung[hientai].ngaySinh << endl;
					cout << "Nhap ngay sinh moi: ";
					cin.getline(ngDung[hientai].ngaySinh, 15);
					cout << "Da thay doi ngay sinh";
					break;
		}
		case 4: {
					cout << "Ten dia chi cu: " << ngDung[hientai].diaChi << endl;
					cout << "Nhap dia chi moi: ";
					cin.getline(ngDung[hientai].diaChi, 50);
					cout << "Da thay doi dia chi";
					break;
		}
		case 5: {
					cout << "Ten tai khoan cu: " << ngDung[hientai].tenDangNhap << endl;
					cout << "Nhap ten tai khoan moi: ";
					cin.getline(ngDung[hientai].tenDangNhap, 30);
					cout << "Da thay doi ten tai khoan";
					break;
		}
		default:
			break;
		}
		fstream outFile("UserData.DAT", ios::out);
		for (int i = 0; i < sl; i++) ngDung[i].ghi(outFile);
		outFile.close();
		Sleep(2000);
	}

	////############Quyen 20. Yeu cau tu doc gia###################################################################3#

	else if (quyen == 20){
		system("cls");
		int choose;
		int slnd = TruyXuatNgDung(ngDung);
		int sls = TruyXuatSach(sach);
		TruyXuatMuonSach(muonsach);
		int sl = TruyXuatYeuCau(yc);
		if (sl != 0){
			cout << "Co " << sl << " Yeu cau can giai quyet: " << endl;
			cout << "_______________________________________________________________________________________________" << endl;
			cout << setw(10) << left << "|Stt" << setw(15) << left << "|Ten yeu cau"
				<< setw(30) << left << "|Nguoi yeu cau";
			cout << setw(10) << left << "|ID sach" << setw(30) << left << "|Ten Sach" << "|" << endl;
			for (int i = 0; i < sl; i++) {
				cout << "|" << setw(9) << left << yc[i].stt << "|";
				(yc[i].mayc == 1) ? cout << setw(14) << left << "Muon sach" : cout << setw(14) << left << "Tra sach";
				cout << "|" << setw(29) << left << yc[i].tenND << "|";
				cout << setw(9) << left << yc[i].IDsach << "|" << setw(29) << left << yc[i].tensach << "|" << endl;
			}
			cout << "|_________|______________|_____________________________|_________|_____________________________|" << endl;
			cout << "Nhap lua chon: "; cin >> choose; cin.ignore();
			for (int i = 0; i < sl; i++){
				if (yc[i].stt == choose){
					if (yc[i].mayc == 1){
						cout << "Ban co mot yeu cau ";
						cout << "Muon sach ";
						cout << "tu ID " << yc[i].ID << "(" << yc[i].tenND << "):" << endl;
						cout << "ID sach muon: " << yc[i].IDsach << endl;
						cout << "Ten sach muon: " << yc[i].tensach << endl;
						cout << "Ten tac gia: " << muonsach[yc[i].IDmuon].tentacgia << endl;
						cout << "Ngon ngu: " << muonsach[yc[i].IDmuon].ngonngu << endl;
						cout << "The loai: " << muonsach[yc[i].IDmuon].theloai << endl;
						cout << "Ngay muon: " << muonsach[yc[i].IDmuon].ngayMuon[0] << "/" << muonsach[yc[i].IDmuon].ngayMuon[1] << "/" << muonsach[yc[i].IDmuon].ngayMuon[2] << endl;
						cout << "Xac nhan yeu cau(0-khong dong y, 1-dong y):"; cin >> yc[i].c; cin.ignore();
						if (yc[i].c == 1){
							fstream outFile("Sach.DAT", ios::out);
							for (int l = 0; l < sls; l++) {
								if (sach[l].ID == yc[i].IDsach)	sach[l].trangthai = 0;
								sach[l].ghi(outFile);
							}
							outFile.close();
							int ndht = 0;
							
							
							
							for (int l = 0; l < slnd; l++){
								if (strcmp(ngDung[l].sCMND, yc[i].ID)==0) ndht = l;
							}
							cout << "Xac nhan thanh cong!" << endl;
							cout << ndht << endl;
							ThongBaoTuDong(ngDung, thongbao, muonsach, ndht, yc[i].tensach);
							for (int j = i; j < sl; j++){
								yc[j] = yc[j + 1];
							}
							fstream outF("YeuCau.DAT", ios::out);
							for (int j = 0; j < sl - 1; j++){
								yc[j].ghi(outF);
							}
							outF.close();
						}
					}
				}
			}
		}
		else cout << "Ban khong co yeu cau nao" << endl;
		Sleep(3000);
	}

	//##########QUyen 21. Doi vai tro###############################################################################

	else if (quyen == 21) {
		Quyen q[30];
		TruyXuatQuyen(q);
		int dem = 1;
		int op, op2;
		cout << " ____________________________" << endl;
		cout << "|        DOI VAI TRO         |" << endl;
		cout << "|____________________________|" << endl;
		cout << "| Cac vai tro hien tai:      |" << endl;
		if (ngDung[hientai].chucVu.admin == 1){
			cout << "| " << dem << ". Admin                   |" << endl;
			dem++;
		}
		if (ngDung[hientai].chucVu.thuthu == 1){
			cout << "| " << dem << ". Thu Thu                 |" << endl;
			dem++;
		}
		if (ngDung[hientai].chucVu.docgia == 1){ 
			cout << "| " << dem << ". Doc Gia                 |" << endl;
			dem++;
		}
		cout << "|____________________________|" << endl;
		cout << "Nhap lua chon: "; cin >> op; cin.ignore();
		
		switch (op){
		case 1:{
				   if (ngDung[hientai].chucVu.admin == 1){
					   int kt = 0;
					   do {
						   ShowMenu(ngDung, 0, q, 1);
						   cout << "Nhap lua chon: "; cin >> op2; cin.ignore();
						   if (q[op2].Admin == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
						   else kt = Chucnang(hientai, ngDung, op2, m, q, tdn, sach, muonsach, thongbao, yc);
					   } while (kt == 0);
					   return 0;
				   }
				   else cout << "Ban khong co chuc vu nay!" << endl;
		}
		case 2:{
				   if (ngDung[hientai].chucVu.thuthu == 1){
					   int kt = 0;
					   do {
						   ShowMenu(ngDung, 0, q, 2);
						   cout << "Nhap lua chon: "; cin >> op2; cin.ignore();
						   if (q[op2].ThuThu == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
						   else kt = Chucnang(hientai, ngDung, op2, m, q, tdn, sach, muonsach, thongbao, yc);
					   } while (kt == 0);
					   return 0;
				   }
				   else cout << "Ban khong co chuc vu nay!" << endl;
		}
		case 3:{
				   if (ngDung[hientai].chucVu.docgia == 1){
					   int kt = 0;
					   do {
						   ShowMenu(ngDung, 0, q, 3);
						   cout << "Nhap lua chon: "; cin >> op2; cin.ignore();
						   if (q[op2].DocGia == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
						   else kt = Chucnang(hientai, ngDung, op2, m, q, tdn, sach, muonsach, thongbao, yc);
					   } while (kt == 0);
					   return 0;
				   }
				   else cout << "Ban khong co chuc vu nay!" << endl;
		}
		}
		/*do {
			system("cls");
			int ch = 0;
			if (ngDung[k].chucVu.admin == 1){
				ShowMenu(ngDung, chucvu, quyen, 1);
				cout << "Nhap lua chon: "; cin >> op; cin.ignore();
				if (quyen[op].Admin == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
				else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
			}
			else if (ngDung[k].chucVu.thuthu == 1) {
				ShowMenu(ngDung, chucvu, quyen, 2);
				cout << "Nhap lua chon: "; cin >> op; cin.ignore();
				if (quyen[op].ThuThu == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
				else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
			}
			else ShowMenu(ngDung, chucvu, quyen, 3);
			Sleep(1311);
		} while (kt != 1);*/

	}

	//##########//Quyen 22. Dang xuat.#########################################################################3##

	else if (quyen == 22) {
		system("cls");
		int qq;
		cout << "Ban muon thoat?(yes = 1, no = 0) "; cin >> qq; cin.ignore();
		if (qq == 1) exit(0);
		return qq;
	}


	return 0;
}

void Choose(){

}
int main() {
	// lay thoi gian he thong:
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	/*
	
	//*/
	///*
	Quyen quyen[30];
	/*quyen[0].stt = 0; quyen[0].Admin = 1; strcpy(quyen[0].tenQuyen, "Them nguoi dung.");
	quyen[1].stt = 1; quyen[1].Admin = 1; strcpy(quyen[1].tenQuyen, "Khoa nguoi dung.");
	quyen[2].stt = 2; quyen[2].Admin = 1; strcpy(quyen[2].tenQuyen, "Mo khoa nguoi dung.");
	quyen[3].stt = 3; quyen[3].Admin = 1; strcpy(quyen[3].tenQuyen, "Quan ly quyen.");
	quyen[4].stt = 4; quyen[4].ThuThu = quyen[4].DocGia = 1; strcpy(quyen[4].tenQuyen, "Xem kho sach.");
	quyen[5].stt = 5; quyen[5].ThuThu = quyen[5].DocGia = 1; strcpy(quyen[5].tenQuyen, "Tim sach.");
	quyen[6].stt = 6; quyen[6].ThuThu = 1; strcpy(quyen[6].tenQuyen, "Them sach.");
	quyen[7].stt = 7; quyen[7].DocGia = 1; strcpy(quyen[7].tenQuyen, "Muon sach.");
	quyen[8].stt = 8; quyen[8].DocGia = 1; strcpy(quyen[8].tenQuyen, "Tra sach.");
	quyen[9].stt = 9; quyen[9].DocGia = 1; strcpy(quyen[9].tenQuyen, "Xem balo.");
	quyen[10].stt = 10; quyen[10].Admin = quyen[10].ThuThu = quyen[10].DocGia = 1; strcpy(quyen[10].tenQuyen, "Doi mat khau.");
	quyen[11].stt = 11; quyen[11].Admin = quyen[11].ThuThu = quyen[11].DocGia = 1; strcpy(quyen[11].tenQuyen, "Xem thong bao.");
	quyen[12].stt = 12; quyen[12].Admin = 1; strcpy(quyen[12].tenQuyen, "Reset mat khau");
	quyen[13].stt = 13; quyen[13].Admin = quyen[13].ThuThu = 1; strcpy(quyen[13].tenQuyen, "Tim kiem tai khoan.");
	quyen[14].stt = 14; quyen[14].Admin = quyen[14].ThuThu = 1; strcpy(quyen[14].tenQuyen, "Tao thong bao.");
	quyen[15].stt = 15; quyen[15].ThuThu = 1; strcpy(quyen[15].tenQuyen, "Chinh sua sach.");
	quyen[16].stt = 16; quyen[16].ThuThu = 1; strcpy(quyen[16].tenQuyen, "Xoa sach.");
	quyen[17].stt = 17; quyen[17].Admin = quyen[17].ThuThu = quyen[17].DocGia = 1; strcpy(quyen[17].tenQuyen, "Xem thong tin tai khoan.");
	quyen[18].stt = 18; quyen[18].Admin = quyen[18].ThuThu = 1; strcpy(quyen[18].tenQuyen, "Xem danh sach tai khoan.");
	quyen[19].stt = 19; quyen[19].Admin = quyen[19].ThuThu = quyen[19].DocGia = 1; strcpy(quyen[19].tenQuyen, "Sua thong tin tai khoan.");
	quyen[20].stt = 20; quyen[20].ThuThu = 1; strcpy(quyen[20].tenQuyen, "Yeu cau tu doc gia.");
	quyen[21].stt = 21; quyen[21].Admin = quyen[21].ThuThu = 1; strcpy(quyen[21].tenQuyen, "Doi vai tro.");
	quyen[22].stt = 22; quyen[22].Admin = quyen[22].ThuThu = quyen[22].DocGia = 1; strcpy(quyen[22].tenQuyen, "Dang xuat.");*/
	//quyen[23].stt = 23; quyen[23].Admin = quyen[23].ThuThu = quyen[23].DocGia = 1; strcpy(quyen[23].tenQuyen, "Thoat.");
	//fstream outFile("Quyen.DAT", ios::out);
	////Quyen quyen[30];
	//for (int i = 0; i < 23; i++){
	//	quyen[i].ghi(outFile);
	//}
	
	TruyXuatQuyen(quyen);
	
	int taikhoanhientai;
	Sach sach[100];
	NguoiDung ngDung[100];
	MuonSach muonsach[100];
	ThongBao thongbao[100];
	YeuCau yc[100];
	char tdn[30];
	//char u[30] = "root\0";
	//char p[20] = "toor\0";
	//CapNhatNgDung(ngDung);
	fstream outSFile("Sach.DAT", ios::app); outSFile.close();
	fstream outS1File("UserData.DAT", ios::app); outS1File.close();
	fstream outS2File("MuonSach.DAT", ios::app); outS2File.close();
	fstream outS3File("ThongBao.DAT", ios::app); outS3File.close();
	fstream outS4File("YeuCau.DAT", ios::app); outS4File.close();
	int k = 0;
	int op;
	while (true) {
		int m, kt = 0;
		int chucvu;
		m = TruyXuatNgDung(ngDung);
		
		//cout << m << endl;
		char user[30], pass[20];
		cout << endl << endl << endl;
		cout << "             __                __ ________  __        _______   _______    ___      ___ "                  << endl;
		cout << "             \\ \\              / /|  ______||  |      /   ____\\ /  ___  \\  |   \\    /   |"             << endl;
		cout << "              \\ \\    ____    / / |  |_____ |  |      |  |      | |   | |  |    \\  /    |"               << endl;
		cout << "               \\ \\  /    \\  / /  |   _____||  |      |  |      | |   | |  |  |\\ \\/ /|  |"             << endl;
		cout << "                \\ \\/  /\\  \\/ /   |  |_____ |  |_____ |  |_____ | |___| |  |  | \\__/ |  |"             << endl;
		cout << "                 \\___/  \\___/    |________||________|\\_______/ \\_______/  |__|      |__|"              << endl;
		cout << "                           _________  _______           __  _________      _______          "              << endl;
		cout << "                          |___   ___|/  ___  \\          \\ \\/ /______ |    /  ___  \\               "    << endl;
		cout << "                    ___       | |    | |   | |           \\  / _____| |    | |   | |       "               << endl;
		cout << "                   |   |      | |    | |   | |            \\/ |_____  |    | |   | | "                     << endl;
		cout << "                   |   |      | |    | |___| |                _____| |    | |___| |  "                     << endl;
		cout << "                   |   |      |_|    \\_______/	             |_______| [] \\_______/           "        << endl;
		cout << "                   |   |            __   __        ______   ______   _______                             " << endl;
		cout << "                   |   |           |  | |  |      |   _  \\ |   _  \\ /  ___  \\     "                     << endl;
		cout << "                   |   |           |  | |  |___   |  |_| | |  |_| | | |   | |        "                     << endl;
		cout << "                   |   |__________ |  | |   __ \\  |   ___/ |     _/ | |   | |"                            << endl;
		cout << "                   |              ||  | |  |__| | |  |     |  |\\ \\  | |___| |         "                  << endl;
		cout << "                   |______________||__| |______/  |__|     |__| \\_\\ \\_______/                       "   <<endl;
		Sleep(1311);
		system("cls");
		do {
			system("cls");
			cout << "################Dang Nhap################" << endl;
			cout << "Ten Dang Nhap: "; cin.getline(user, 30);
			cout << "Mat Khau: ";
			inmk(pass);
			char u[5] = "root";
			char p[5] = "toor";
			//cout <<ngDung[0].tenDangNhap<<endl;
			//cout << ngDung[0].MatKhau<< endl;
			if (strcmp(user, u) == 0 && strcmp(pass, p) == 0) {
				system("cls");
				cout << "Dang nhap thanh cong!" << endl;
				chucvu = 1;
				kt = 1;
			}
			else {
				for (k = 0; k<m; k++) {
					if (strcmp(user, ngDung[k].tenDangNhap) == 0) {
						if (strcmp(pass, ngDung[k].MatKhau) == 0) {
							if (ngDung[k].trangThai == 0) {
								cout << "Tai khoan cua ban da bi khoa! lien he ad de duoc mo lai! " << endl;
								break;
							}
							else {
								system("cls");
								cout << "Dang nhap thanh cong!" << endl;
								//chucvu = ngDung[k].chucVu;
								strcpy(tdn, ngDung[k].tenDangNhap);
								taikhoanhientai = k;
								kt = 1;
								break;
							}
						}
						else {
							system("cls");
							cout << "Sai mat khau. Dang nhap that bai!" << endl;
							break;
						}
					}
				}
				if (k == m) {
					system("cls");
					cout << "Sai ten dang nhap!" << endl;
				}
			}
			Sleep(1311);
		} while (kt != 1);
		
		do {
			system("cls");
			int ch = 0;
			if (ngDung[k].chucVu.admin == 1||chucvu == 1){
				ShowMenu(ngDung, chucvu, quyen, 1);
				cout << "Nhap lua chon: "; cin >> op; cin.ignore();
				if (quyen[op].Admin == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
				else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
			}
			else if (ngDung[k].chucVu.thuthu == 1) {
				ShowMenu(ngDung, chucvu, quyen, 2);
				cout << "Nhap lua chon: "; cin >> op; cin.ignore();
				if (quyen[op].ThuThu == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
				else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
			}
			else {
				ShowMenu(ngDung, chucvu, quyen, 3);
				cout << "Nhap lua chon: "; cin >> op; cin.ignore();
				if (quyen[op].DocGia == 0) cout << "Ban khong duoc ho tro chuc nang nay!";
				else kt = Chucnang(taikhoanhientai, ngDung, op, m, quyen, tdn, sach, muonsach, thongbao, yc);
			}
			Sleep(1311);
		} while (kt != 1);
	}
	//*/
	return 0;
}
