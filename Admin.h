#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"

class Admin :public Employee {
public:
	Admin(int Id, string Name, string Pasword, double salary) :
		Employee(Id, Name, Pasword, salary) {
	}

	void display() {
		Person::displayPerson();
		cout << salary;
	}
};


#endif 


