#include <iostream>
using namespace std;

struct DaThucBac2 {
    double a;
    double b;
    double c;

    void Nhap() {
        cout << "Nhap he so a, b, c: ";
        cin >> a >> b >> c;
    }
    void Xuat() {
        cout << a << "x^2 ";
        if (b >= 0) cout << "+ ";
        cout << b << "x ";
        if (c >= 0) cout << "+ ";
        cout << c << endl;
    }

    double calculateAtZero() const {
        return c;
    }
};

DaThucBac2 tongDaThuc(DaThucBac2 p1, DaThucBac2 p2) {
    return { p1.a + p2.a, p1.b + p2.b, p1.c + p2.c };
}

DaThucBac2 hieuDaThuc(DaThucBac2 p1, DaThucBac2 p2) {
    return { p1.a - p2.a, p1.b - p2.b, p1.c - p2.c };
}

void tichDaThuc(DaThucBac2 p1, DaThucBac2 p2) {
    double x4 = p1.a * p2.a;
    double x3 = p1.a * p2.b + p1.b * p2.a;
    double x2 = p1.a * p2.c + p1.b * p2.b + p1.c * p2.a;
    double x1 = p1.b * p2.c + p1.c * p2.b;
    double x0 = p1.c * p2.c;
    cout << x4 << "x^4 ";
    if (x3 >= 0) cout << "+ ";
    cout << x3 << "x^3 ";
    if (x2 >= 0) cout << "+ ";
    cout << x2 << "x^2 ";
    if (x1 >= 0) cout << "+ ";
    cout << x1 << "x ";
    if (x0 >= 0) cout << "+ ";
    cout << x0;
    cout << endl;
}

int main() {
    DaThucBac2 p1, p2;

    cout << "Nhap da thuc thu nhat:" << endl;
    p1.Nhap();

    cout << "Nhap da thuc thu hai:" << endl;
    p2.Nhap();

    cout << "Da thuc thu nhat: " << endl;
    p1.Xuat();

    cout << "Da thuc thu hai: " << endl;
    p2.Xuat();

    DaThucBac2 sum = tongDaThuc(p1, p2);
    cout << "Tong hai da thuc: ";
    sum.Xuat();

    DaThucBac2 difference = hieuDaThuc(p1, p2);
    cout << "Hieu hai da thuc: ";
    difference.Xuat();

    cout << "GT cua da thuc thu nhat tai F(0): " << p1.calculateAtZero() << endl;
    cout << "GT cua da thuc thu hai tai F(0): " << p2.calculateAtZero() << endl;

    cout << "Tich hai da thuc: ";
    tichDaThuc(p1, p2);

    return 0;
}