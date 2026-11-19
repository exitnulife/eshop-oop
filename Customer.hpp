#pragma once
#include <string>
//5) STATIC INT instanceCount

//zakladni trida zakaznika
class Customer {
private:
    static int instanceCount; //pocet aktivnich instanci Customer a odvozenych trid
    int id;
    std::string name;
    std::string email;
protected:
    double discountPercent; //odvozene tridy (PremiumCustomer) mohou menit
public:
    Customer(int id, const std::string& name, const std::string& email);
    virtual ~Customer();

    int getId() const;
    std::string getName() const;
    std::string getEmail() const;

    virtual double getDiscount() const;
    virtual std::string getCustomerType() const; //pozdni vazba
    virtual void printInfo() const; //pozdni vazba
    virtual void addLoyaltyPoints(int points); //pozdni vazba, PremiumCustomer prepise

    static int getInstanceCount();
};