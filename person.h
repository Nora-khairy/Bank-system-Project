#include <iostream>
#include <string>
#include <cctype>
#include "Validation.h"
using namespace std;
class Person {
protected:
    string Name, Pasword;
    int Id;

public:
    Person(int Id, string Name, string Pasword) {
    this->Id = Id;
    setname(Name);
    setpassword(Pasword);
}
    Person() {}
    //setters
    void setid(int Id) {
        this->Id = Id;
    }
    void setname(string Name) {
        if (Validation::isValidName(Name)) {
            this->Name = Name;
        }
        else {
           this->Name = Validation::enterName();
        }
    }
    void setpassword(string Pasword) {
        if (Validation::isValidPassword(Pasword)) {
            this->Pasword = Pasword;
        }
        else {
             this->Pasword = Validation::enterPassword();
        }

    }
    //getters
    int getid() {
        return Id;
    }
    string getname() {
        return Name;
    }
    string  getpassword() {
        return Pasword;
    }

 void displayPerson() {
     cout << "ID :" << Id << endl;
     cout << "name :" << Name << endl;
     cout << "Password : " << Pasword << endl;
 }
virtual void display() = 0;
};
