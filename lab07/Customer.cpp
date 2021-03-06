/*
 * Customer.cpp
 * CS 202
 * March 27, 2020
 * Bryan Beus
 * Customer definition file
 */

#include <iostream>
#include <iomanip>
#include <string>

#include "Customer.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::setw;
using std::left;
using std::right;

Customer::Customer() { }

Customer& Customer::operator=(const Customer& other) {

    firstName_ = other.firstName();
    lastName_ = other.lastName();
    bankBalance_ = other.bankBalance();

    return *this;
}

void Customer::setFirstName(const string& newFirstName) {
    firstName_ = newFirstName;
}

void Customer::setLastName(const string& newLastName) {
    lastName_ = newLastName;
}

void Customer::setBankBalance(double newBankBalance) {
    bankBalance_ = newBankBalance;
}

ostream& operator<< (ostream& os, const Customer& customer) {
    os << left << setw(35) << "First Name: " << right << setw(35) <<  customer.firstName() << endl;;
    os << left << setw(35) << "Last Name: " << right << setw(35) <<  customer.lastName() << endl;;
    os << left << setw(35) << "Bank Balance: " << right << setw(35) << std::put_money(customer.bankBalance()) << endl;
    return os;
}

