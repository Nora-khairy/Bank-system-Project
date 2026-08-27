#include <iostream>
#include <string>
#include "Validation.h"
#include "person.cpp"
using namespace std;

class Client : public Person {
private:
	double balance;

public:
	// constructors
	Client() : Person() {
		this->balance = 1500.0;
	}
	Client(int Id, string Name, string Pasword, double balance) :Person(Id, Name, Pasword) {
		SetBalance(balance);
	}
	// setters
	void SetBalance(double balance) {
		if (Validation::isValidBalance(balance)) {
			this->balance = balance;
		}
		else {
			cout << "Inavalid Balance!";
		}
	}
	//Getters
	double GetBalance() {
		return balance;
	}
	//methods
	void Deposit(double amount) {
		balance += amount;
		cout << "successful Operation ; New Balance = " << balance;
	}
	void Withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
			cout << "successful Operation ; New Balance = " << balance;
		}
		else { cout << " Invalid Operation" ; }
	}
	void TransferTo(double amount, Client& recipient) {
		if (amount <= balance) {
			Withdraw(amount);
			recipient.Deposit(amount);
			cout << "successful Operation ; New Balance = " << balance;
		}
		else { cout << " Invalid Operation"; }
	}
	void CheckBalance() {
		cout << "Current Balance = " << balance;
	}
	void DisPlay() {
		Person::displayPerson();
		CheckBalance();
	}
};
int main() {
	Client c1(333, "menna", "asd123456", 2550.0);
	Client c2(678, "mahmoud", "xxx56789", 4000.0);
	c1.DisPlay();
	c1.Deposit(200.0);
	c1.Withdraw(300.0);
	c1.TransferTo(1200.0, c2);
}