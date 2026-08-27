#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "person.h"
using namespace std;

class Client : public Person {
private:
	double balance;

public:
	// constructors
	Client();
	Client(int Id, string Name, string Pasword, double balance);
	 
	// setters
	void SetBalance(double balance);

		//Getters
		double GetBalance();
		 
 
	//methods
void Deposit(double amount);
void Withdraw(double amount);
void TransferTo(double amount, Client& recipient);
void CheckBalance();
void DisPlay();
};
 