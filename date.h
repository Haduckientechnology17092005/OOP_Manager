#ifndef DATE_H
#define DATE_H
#include<iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>

using namespace std;

class Date {
    protected:
        int day, month, year;

    public:
        Date(int day = 1, int month = 1, int year = 2024) {
            if (check_invalid_date(day, month, year)) {
                throw invalid_argument("Invalid date provided!");
            }
            this->day = day;
            this->month = month;
            this->year = year;
        }

        Date(const Date& date) {
            this->day = date.day;
            this->month = date.month;
            this->year = date.year;
        }

        virtual ~Date() = default;

        Date& operator++() {
            int daysInMonth[] = { 31, (isLeapYear(this->year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            if (this->day == daysInMonth[this->month - 1]) {
                this->day = 1;
                if (this->month == 12) {
                    this->month = 1;
                    this->year++;
                } else {
                    this->month++;
                }
            } else {
                this->day++;
            }
            return *this;
        }

        Date& operator--() {
            int daysInMonth[] = { 31, (isLeapYear(this->year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

            if (this->day == 1) {
                if (this->month == 1) {
                    this->day = 31;
                    this->month = 12;
                    this->year--;
                } else {
                    this->month--;
                    this->day = daysInMonth[this->month - 1];
                }
            } else {
                this->day--;
            }
            return *this;
        }

        friend ostream& operator<<(ostream& os, const Date& date) {
            os << date.day << "/" << date.month << "/" << date.year;
            return os;
        }

        friend istream& operator>>(istream& is, Date& date) {
            cout << "Day: ";
            is >> date.day;
            cout << "Month: ";
            is >> date.month;
            cout << "Year: ";
            is >> date.year;
            if (check_invalid_date(date.day, date.month, date.year)) {
                throw invalid_argument("Invalid date entered!");
            }
            return is;
        }

        int daysInMonth() const {
            int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (isLeapYear(year)) days[1] = 29;
            return days[month - 1];
        }

    private:
        static bool isLeapYear(int year) {
            return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        }

        static bool check_invalid_date(int day, int month, int year) {
            if (year < 1 || month < 1 || month > 12) return true;
            int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (day < 1 || day > daysInMonth[month - 1]) return true;
            return false;
        }
};

#endif
