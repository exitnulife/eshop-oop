#include "PremiumCustomer.hpp"
#include <iostream>
//7) ROZŠÍŘENÍ DAT: loyaltyPoints, nový atribut oproti Customer
//7) POZDNÍ VAZBA: getCustomerType(), getDiscount(), printInfo() překryty
//9) PROTECTED: discountPercent zapsán přímo, přístup k protected atributu z Customer

PremiumCustomer::PremiumCustomer(int id, const std::string& name, const std::string& email, double discountPercent) : Customer(id, name, email), loyaltyPoints(0) {
    //pristup k protected atributu z Customer
    this->discountPercent = discountPercent;
}

PremiumCustomer::~PremiumCustomer() {}

int PremiumCustomer::getLoyaltyPoints() const { 
    return loyaltyPoints; 
}

void PremiumCustomer::addLoyaltyPoints(int points) {
    loyaltyPoints += points;
}

double PremiumCustomer::getDiscount() const { 
    return discountPercent; 
}

std::string PremiumCustomer::getCustomerType() const { 
    return "premium zakaznik"; 
}

void PremiumCustomer::printInfo() const {
    //nejprve vypise zakladni info pres Customer::printInfo(), pak prida body
    Customer::printInfo();
    std::cout << "Vernostni body: " << loyaltyPoints << std::endl;
}