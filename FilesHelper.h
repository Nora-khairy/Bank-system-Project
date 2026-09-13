#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include"string"
#include"Parser.h"
#include "Person.h"
#include "Employee.h"
#include "Admin.h"
#include"FilesHelper.h"
 
using namespace std;
class FilesHelper {
public:
	static void SaveLast(string FileName, int id) {
		ofstream output(FileName);
		output << id;
		output.close();
	}
	static int GetLast(string FileName, int id) {
		ifstream input(FileName);

		input >> id;
		input.close();
		return id;
	}
	static void SaveClient(Client c) {
		ofstream output("Client.txt", ios::app);
		output << c.getid() << "/" << c.getname() << "/" << c.getpassword() << "/" << c.GetBalance() << endl;
		output.close();
	}
	static void SaveEmployee(string FileName, string LastIdFile, Employee e) {
		ofstream output(FileName, ios::app);
		output << e.getid() << "/" << e.getname() << "/" << e.getpassword() << "/" << e.getSalary() << endl;
		output.close();
	}
	static void GetClients() {
		ifstream input("Client.txt");
		string line;
	 
		while (getline(input, line)) {

			if (!line.empty()) {
				Client c = Parser::parseToClient(line);
				c.display();
				cout << "========================================================" << endl;
			}

			 
		}
		input.close();
	}

	static void GetEmployees() {
		ifstream input("Employee.txt");
		string line;
		while (getline(input, line)) {

			if (!line.empty()) {
				Employee e = Parser::parseToEmployee(line);
				e.display();
			}
		}
		input.close();
	}
	static void SaveAdmin(Admin a) {
		SaveEmployee("Admin.txt", "AdminLastId.txt", a);
		ofstream output("Admin.txt", ios::app);
		output << a.getid() << "/" << a.getname() << "/" << a.getpassword() << "/" << a.getSalary() << endl;
		output.close();
	}



	static void GetAdmins() {

		ifstream input("Admin.txt");
		string line;
		while (getline(input, line)) {

			if (!line.empty()) {
				Admin a = Parser::parseToAdmin(line);
				a.display();
			}

		}
		input.close();
	}
	static void ClearFile(string FileName, string LastIdFile) {
		ofstream output(FileName, ios::trunc);
		output.close();
		ofstream lastFile(LastIdFile, ios::trunc);
		lastFile << 0;
		lastFile.close();
	}
};