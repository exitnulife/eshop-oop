#pragma once
#include "Customer.hpp"

// Odvozena trida pro premium zakazniky.
// Rozsiruje Customer o vernostni body a individualni slevu.
// Prekryva metody getCustomerType(), getDiscount() a printInfo().
class PremiumCustomer : public Customer {
private:
    int loyaltyPoints;
public:
    PremiumCustomer(int id, const std::string& name, const std::string& email, double discountPercent);
    virtual ~PremiumCustomer();

    int getLoyaltyPoints() const;
    virtual void addLoyaltyPoints(int points) override; //rozsireni chovani

    //prekryti metod ze Customer, zmena chovani
    virtual double getDiscount() const override;
    virtual std::string getCustomerType() const override;
    virtual void printInfo() const override;
};