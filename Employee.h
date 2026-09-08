#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
class Employee :public Person
{
protected:
	double salary ;
public:
	//Constructor
	Employee(int Id, string Name, string Pasword, double salary) : Person(Id, Name, Pasword) {
		setSalary(salary);
	}
	//setter salary 
	void setSalary(double salary) {
		if (Validation::isValidSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Invalid Salary" << endl;
		}
	}


	//GETTER salary
	double  getSalary() {
		return salary;
	}
	//display 
	
	void display() override {
		Person::displayPerson();
		cout << "Salary: " << salary << endl;
	}
};
