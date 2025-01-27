#include <iostream>
#include <iomanip>
using namespace std;

struct Time {
	int Gio, Phut, Giay;
};

void Nhap(Time& t) {
	cin >> t.Gio >> t.Phut >> t.Giay;
}

void Xuat(Time t) {
	cout << setfill('0') << setw(2) << t.Gio << ":" 
		 << setfill('0') << setw(2) << t.Phut << ":" 
		 << setfill('0') << setw(2) << t.Giay << endl;
}

void normalize(Time& t) {
	t.Phut += t.Giay / 60;
	t.Giay = t.Giay % 60;

	t.Gio += t.Phut / 60;
	t.Phut = t.Phut % 60;

	t.Gio %= 24;
}

Time congThoiDiem(Time t1, Time t2) {
	Time TongThoiDiem;
	TongThoiDiem.Giay = t1.Giay + t2.Giay;
	TongThoiDiem.Phut = t1.Phut + t2.Phut;
	TongThoiDiem.Gio = t1.Gio + t2.Gio;
	normalize(TongThoiDiem);
	return TongThoiDiem;
}

int main() {
	Time t1, t2;
	cout << "Nhap gio hien tai: " << endl;
	Nhap(t1);
	cout << "Nhap thoi gian muon cong them: " << endl;
	Nhap(t2);
	Time TongThoiDiem = congThoiDiem(t1, t2);
	cout << "Thoi gian sau khi cong them: " << endl;
	Xuat(TongThoiDiem);
}