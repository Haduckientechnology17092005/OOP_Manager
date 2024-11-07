#ifndef NV_H
#define NV_H
#include<iomanip>
#include <iostream>
#include <string>
#include "date.h"
using namespace std;

class NhanVien {
protected:
    string id;
    string name;
    Date dayStartOfWork;
    bool sex;
    double salary;
public:
    NhanVien(string id, string name, Date dayStartOfWork, bool sex) {
        if (id == "" || name == "") {
            throw invalid_argument("Invalid input");
        }
        this->id = id;
        this->name = name;
        this->dayStartOfWork = dayStartOfWork;
        this->sex = sex;
        this->salary = 0;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Day start of work: " << dayStartOfWork << endl;
        cout << "Sex: " << (sex ? "Female" : "Male") << endl;
        cout << "Salary: " << fixed << setprecision(2) << salary << endl;
    }

    virtual void solutionSalary() = 0;
};
#endif
