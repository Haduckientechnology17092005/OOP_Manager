#ifndef QLNV_H
#define QLNV_H

#include "linkedlist.h"
#include "nhanvien.h"
#include <iostream>
#include <string>
#include <stdexcept>

class QLNV {
private:
    string name;
    LinkedList<NhanVien> employees;

public:
    QLNV(const string& name) : name(name) {}

    // Thêm nhân viên
    void addEmployee(NhanVien* nv) {
        employees.append(nv);
    }

    // Xuất danh sách nhân viên
    void displayEmployees() const {
        cout << "Employee List of " << name << ":\n";
        employees.display();
    }

    // Lấy số lượng nhân viên
    int getEmployeeCount() const {
        return employees.getSize();
    }

    // Truy cập nhân viên theo chỉ số
    NhanVien* operator[](int index) {
        if(index < 0 || index >= employees.getSize()) {
            throw out_of_range("Index out of range");
        }
        return employees[index];
    }

    // Toán tử gán cho QLNV
    QLNV& operator=(const QLNV& other) {
        if (this == &other) return *this;
        name = other.name;
        employees = other.employees;
        return *this;
    }

    // Xử lý tính lương cho tất cả nhân viên
    void calculateSalaries() {
        for (int i = 0; i < employees.getSize(); i++) {
            employees[i]->solutionSalary();
        }
    }

    void deleteEmployeeByIndex(int index) {
        if (index < 0 || index >= employees.getSize()) {
            cout << "Index out of range. Employee not found.\n";
            return;
        }        
        delete employees[index];
        employees.removeAt(index);
        cout << "Employee at index " << index << " has been deleted.\n";
    }
};

#endif
