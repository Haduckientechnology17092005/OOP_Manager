#include "quanly.h"
#include "nhanvien.h"
#include "nvhd.h"
#include "nvbc.h"
#include <iostream>
#include <limits>

using namespace std;

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add employee\n";
    cout << "2. Calculate salaries for all employees\n";
    cout << "3. Display employee list\n";
    cout << "4. Access employee information by index\n";
    cout << "5. Remove employee\n";
    cout << "6. Exit\n";
    cout << "Choose your option: ";
}

int main() {
    QLNV qlnv("ITF Company");
    bool running = true;
    int choice;
    while (running) {
        showMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Please enter a valid number!" << endl;
            continue;
        }
        switch (choice) {
            case 1: {
                string id, name;
                int day, month, year;
                bool isWorking, sex;
                double salary, coefficient;
                int daysWorked, yearsWorked;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter sex (0 for Male, 1 for Female): ";
                cin >> sex;
                if (sex != 0 && sex != 1) {
                    cout << "Invalid gender! Please try again.\n";
                    continue;
                }
                cout << "Enter start date (day month year): \n";
                cout << "Day: ";
                cin >> day;
                cout << "Month: ";
                cin >> month;
                cout << "Year: ";
                cin >> year;
                try {
                    Date startDate(day, month, year); 
                    cout << "Full-time employee (1: Yes, 0: No): ";
                    cin >> isWorking;
                    if (!isWorking) {
                        cout << "Enter employee salary of day: ";
                        cin >> salary;
                        cout << "Enter number of days worked: ";
                        cin >> daysWorked;
                        NVHD* nv = new NVHD(id, name, startDate, sex, salary, daysWorked);
                        qlnv.addEmployee(nv);
                    } else {
                        cout << "Enter salary coefficient: ";
                        cin >> coefficient;
                        cout << "Enter number of years worked: ";
                        cin >> yearsWorked;
                        NVBC* nv = new NVBC(id, name, startDate, sex, coefficient, yearsWorked);
                        qlnv.addEmployee(nv);
                    }
                    cout << "Employee has been added!\n";
                } catch (const std::invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 2: {
                qlnv.calculateSalaries();
                cout << "Salaries have been calculated for all employees.\n";
                break;
            }
            case 3: {
                qlnv.displayEmployees();
                break;
            }
            case 4: {
                int index;
                cout << "Enter the employee index you want to access: ";
                cin >> index;
                try {
                    NhanVien* employee = qlnv[index];
                    cout << "Employee information at index " << index << ":\n";
                    employee->display();
                } catch (const std::out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 5: {
                int index;
                cout << "Enter the employee index you want to remove: ";
                cin >> index;
                try {
                    qlnv.deleteEmployeeByIndex(index); 
                    cout << "Employee at index " << index << " has been removed.\n";
                } catch (const std::out_of_range& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
            }
            case 6: {
                running = false;
                cout << "Exiting the program.\n";
                break;
            }
            default: {
                cout << "Invalid option. Please try again.\n";
                break;
            }
        }
    }
    return 0;
}
