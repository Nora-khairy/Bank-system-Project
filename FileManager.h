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
class FilesManager {
public:
	void AddClient(Client c) {
		FilesHelper::SaveClient(c);
	}
	void AddEmployee(string FileName, string LastIdFile, Employee e) {
		FilesHelper::SaveEmployee(FileName, LastIdFile, e);
	}
	void AddAdmin(Admin a) {
		FilesHelper::SaveAdmin(a);
	}
	void GetAllEmployees() {
		FilesHelper::GetEmployees();
	}
	void GetAllClients() {
		FilesHelper::GetClients();
		 
	}
	void GetAllAdmins() {
		FilesHelper::GetAdmins();
	}
	void RemoveAllClients(string FileName, string LastIdFile) {
		FilesHelper::ClearFile("Client.txt", "ClientLastId.txt");
	}
	void RemoveAllEmployees(string FileName, string LastIdFile) {
		FilesHelper::ClearFile("Employee.txt", "EmployeeLastId.txt");
	}
	void RemoveAllAdmins(string FileName, string LastIdFile) {
		FilesHelper::ClearFile("Admin.txt", "AdminLastId.txt");
	}
}
	;