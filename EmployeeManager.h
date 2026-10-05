#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "Client.h"
using namespace std;

class EmployeeManager{
private:
    static vector<Employee> employees;

public:
    // 1. Print Employee Menu
    static void printEmployeMenu(){
        cout << "========== Employee Menu ==========" << endl;
        cout << "1. New Client" << endl;
        cout << "2. List All Clients" << endl;
        cout << "3. Search For Client" << endl;
        cout << "4. Edit Client Info" << endl;
        cout << "5. Logout" << endl;
        cout << "===================================" << endl;
    }

    // 2. Add New Client
    static void newClient(Employee* employee){
        int id;
        string name;
        string password;
        double balance;

        cout << "Enter Client ID: ";
        cin >> id;
        cout << "Enter Client Name: ";
        cin >> name;
        cout << "Enter Client Password: ";
        cin >> password;
        cout << "Enter Client Balance: ";
        cin >> balance;
        Client client(id, name, password, balance);
        employee->AddClient(client);
        cout << "Client added successfully." << endl;
    }

    // 3. List All Clients
    static void listAllClients(Employee* employee){
        employee->ListClients();
    }

    // 4. Search For Client
    static void searchForClient(Employee* employee){
        int id;

        cout << "Enter Client ID: ";
        cin >> id;

        Client* client = employee->searchClient(id);

        if (client != nullptr){
            client->display();
        }
        else {
            cout << "Client not found." << endl;
        }
    }

    // 5. Edit Client Information
    static void editClientInfo(Employee* employee){
        int id;
        string newName;
        string newPassword;
        double newBalance;

        cout << "Enter Client ID: ";
        cin >> id;

        cout << "Enter New Name: ";
        cin >> newName;

        cout << "Enter New Password: ";
        cin >> newPassword;

        cout << "Enter New Balance: ";
        cin >> newBalance;

        employee->EditClient(id,newName,newPassword,newBalance);
    }

    // 6. Login
    static Employee* login(int id, string password){
        for (Employee& employee : employees){
            if (employee.getid() == id &&
                employee.getpassword() == password)
            {
                return &employee;
            }
        }
          return nullptr;
    }

    // 7. Employee Options
    static bool employeeOptions(Employee* employee){
        int choice;

        printEmployeMenu();

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice){
        case 1:
            newClient(employee);
            break;

        case 2:
            listAllClients(employee);
            break;

        case 3:
            searchForClient(employee);
            break;

        case 4:
            editClientInfo(employee);
            break;

        case 5:
            cout << "Logged out successfully." << endl;
            return false;

        default:
            cout << "Invalid Choice." << endl;
        }

        return true;
    }
};
// Definition of static vector
vector<Employee> EmployeeManager::employees;

