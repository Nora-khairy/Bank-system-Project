#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Client.h"
#include"Admin.h"
#include"EmployeeManager.h"
#include"FilesHelper.h"
using namespace std;
class AdminManager :public EmployeeManager {
private:
    static vector<Admin> admins;
public:
    // 1. Print Admin Menu
    static void printAdminMenu() {
        cout << "========== Admin Menu ==========" << endl;
        cout << "1. New Client" << endl;
        cout << "2. List All Clients" << endl;
        cout << "3. Search For Client" << endl;
        cout << "4. Edit Client Info" << endl;
        cout << "5.  New Employee" << endl;
        cout << "6. List All Employees" << endl;
        cout << "7. Edit Employee Info" << endl;
        cout << "8. Logout" << endl;
        cout << "===================================" << endl;
    }
   
    // 2. Login
    static Admin* login(int id, string password) {
         
        for (Admin& admin : admins) {
            if (admin.getid() == id &&
                admin.getpassword() == password)
            {
                return &admin;
            }
        }
        return nullptr;

    }
    // 2. Add New Employee
    static void newEmployee(Admin* admin) {
        int id;
        string name;
        string password;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Password: ";
        cin >> password;
        cout << "Enter Employee Balance: ";
        cin >> salary;
        Employee employee(id, name, password, salary);
       admin->AddEmployee(employee);
        cout << "Employee added successfully." << endl;
    }
    //5. Edit Employee Information
    static void editEmployeeInfo(Admin* admin) {
        int id;
        string newName;
        string newPassword;
        double newBalance;

        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter New Name: ";
        cin >> newName;

        cout << "Enter New Password: ";
        cin >> newPassword;

        cout << "Enter New Balance: ";
        cin >> newBalance; 
        admin->EditEmployee(id, newName, newPassword, newBalance);
    }

    // Admin Options
    static bool AdminOptions(Admin* admin) {
        int choice;

        printAdminMenu();

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            newClient(admin);
            break;

        case 2:
            listAllClients(admin);
            break;

        case 3:
            searchForClient(admin);
            break;

        case 4:
            editClientInfo(admin);
            break;
        case 5:
          
            newEmployee(admin);
            break;
        case 6:

            admin->ListEmployees();
            break;
        case 7:

            editEmployeeInfo( admin);
            break;

        case 8:
            cout << "Logged out successfully." << endl;
            return false;

        default:
            cout << "Invalid Choice." << endl;
        }

        return true;    }
 };
// Definition of static vector
vector<Admin> AdminManager::admins;
 
    }
 };
// Definition of static vector
vector<Admin> AdminManager::admins
 
