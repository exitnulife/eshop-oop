#include "Customer.hpp"
#include <iostream>
//5) STATIC instanceCount, sdílena všemi instancemi Customer i PremiumCustomer
int Customer::instanceCount = 0;

Customer::Customer(int id, const std::string& name, const std::string& email)
    : id(id), name(name), email(email), discountPercent(0.0) {
    instanceCount++;    //inkrementace pri kazdem vytvoreni instance
}

Customer::~Customer() {
    instanceCount--;    //dekrementace pri kazdem zniceni instance
}

int Customer::getId() const { 
    return id; 
}
std::string Customer::getName() const {
    return name; 
}
std::string Customer::getEmail() const {
    return email;
}
double Customer::getDiscount() const {
    return discountPercent;
}

std::string Customer::getCustomerType() const {
    return "zakaznik";
}

void Customer::printInfo() const {
    //getCustomerType() pouziva pozdni vazbu, PremiumCustomer vrati "premium zakaznik"
    std::cout << getCustomerType() << ": " << name << " (" << email << ")" << ", Sleva: " << discountPercent << "%" << std::endl;
}

void Customer::addLoyaltyPoints(int points) {
    //zakladni zakaznik body nema, metoda nedela nic
}

int Customer::getInstanceCount() {
    return instanceCount;
}