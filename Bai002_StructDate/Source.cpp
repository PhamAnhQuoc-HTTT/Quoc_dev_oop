#include <iostream>
using namespace std;

// 1. Định nghĩa cấu trúc Date
struct Date {
    int day;
    int month;
    int year;
};

// 2. Kiểm tra năm nhuận
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 3. Hàm trả về số ngày trong một tháng
int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

Date getNextDay(Date current, int x) {
    Date nextDate = current;
    nextDate.day += x;

    while (nextDate.day > daysInMonth(nextDate.month, nextDate.year)) {
        nextDate.day -= daysInMonth(nextDate.month, nextDate.year);
        nextDate.month++;

        if (nextDate.month > 12) {
            nextDate.month = 1;
            nextDate.year++;
        }
    }

    return nextDate;
}

int main() {
    Date today;

    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> today.day >> today.month >> today.year;

    if (today.month < 1 || today.month > 12 || today.day < 1 || today.day > daysInMonth(today.month, today.year)) {
        cout << "Ngay khong hop le" << endl;
        return 1;
    }
    cout << "Nhap so ngay muon tang: " << endl;
    int x; cin >> x;

    Date nextDay = getNextDay(today, x);

    cout << "Ngay tiep theo la: " << nextDay.day << "/" << nextDay.month << "/" << nextDay.year << endl;

    return 0;
}