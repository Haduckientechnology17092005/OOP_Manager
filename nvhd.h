#ifndef NVHD_H
#define NVHD_H
#include <iostream>
#include <string>
#include<iomanip>
#include "nhanvien.h"

using namespace std;

class NVHD : public NhanVien {
protected:
    int dayWork;
    double salaryOfDay;
public:
    NVHD(string id, string name, Date dayStartOfWork, bool sex, double salaryOfDay, int dayWork) 
        : NhanVien(id, name, dayStartOfWork, sex) {
        if (salaryOfDay < 0 || dayWork < 0) {
            throw invalid_argument("Invalid input");
        }
        this->salaryOfDay = salaryOfDay;
        this->dayWork = dayWork;
    }

    void display() override {
        NhanVien::display();
        cout << "Salary of day: " << salaryOfDay << endl;
        cout << "Day work: " << dayWork << endl;
    }

    void solutionSalary() override {
        this->salary = salaryOfDay * dayWork;
    }
};
#endif
