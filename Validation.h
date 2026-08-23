
#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <cctype>

class Validation {
public:
    static bool isValidName(const std::string& name) {
        if (name.length() < 5 || name.length() > 20) return false;
        for (char c : name) {
            if (!isalpha(c) && c != ' ') return false;
        }
        return true;
    }

    static bool isValidPassword(const std::string& password) {
        return (password.length() >= 8 && password.length() <= 20);
    }

    static bool isValidBalance(double balance) {
        return balance >= 1500.0;
    }

    static bool isValidSalary(double salary) {
        return salary >= 5000.0;
    }
};

#endif
